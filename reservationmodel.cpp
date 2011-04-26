/*
 * reservationmodel.cpp
 * Copyright (C) 2011 Nicolas Martin, Université de Montréal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "reservationmodel.h"

#include <QDebug>

ReservationModel::ReservationModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

QVariant ReservationModel::fieldAt(const QModelIndex &index, int role) const
{
    uint row = index.row();
    uint column = index.column();

    qint64 id = reservations.keys()[row];
    Reservation *r = reservations[id];

    return r->field(column, role);
}

QVariant ReservationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();
    return fieldAt(index, role);
}

int ReservationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return reservations.count();
}

int ReservationModel::columnCount(const QModelIndex &parent) const
{    
    if (parent.isValid()) return 0;
    return Reservation::headerCount();
}

QVariant ReservationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        return Reservation::header(section);
    } else if (orientation == Qt::Vertical) {
        if (section < 0 || section >= reservations.count())
            return QVariant();
        return section;
    }
    return QVariant();
}

bool ReservationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    if (role != Qt::EditRole)
        return false;

    uint row = index.row();
    uint column = index.column();

    qint64 id = reservations.keys().value(row,-1);
    if (id < 0) return false;

    Reservation *r = reservations[id];

    if (r->changeField(column, value)) {
        emit mayNeedFilterUpdate();
        emit dataChanged(index,index);

        return true;
    }

    return false;
}

Qt::ItemFlags ReservationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlags();
    switch (index.column())
    {
    case Reservation::COL_DEBUT:
    case Reservation::COL_FIN:
    case Reservation::COL_STATION:
    case Reservation::COL_USAGER:
    case Reservation::COL_VEHICULE:
    case Reservation::COL_PERSO:
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    default:
        break;
    }

    return QAbstractTableModel::flags(index);
}

// Compare l'intervalle de dates A-B avec C-D
// retour -1 si A-B est AVANT C-D
// retour 0 si A-B intersecte C-D
// retour 1 si A-B est APRES C-D
int ReservationModel::compareIntervalles(QDateTime A,QDateTime B,QDateTime C,QDateTime D)
{
    if( A>B || C>D ) { qDebug()<<"Intervalle invalid!!! ("<< A <<","<< B <<") (" << C << "," << D << ")";return(0); }
    if( B<=C ) return(-1);
    if( A>=D ) return(1);
    return(0);
}

bool ReservationModel::testReservation(Reservation *newres) const
{
    // tester si reservation valide
    // pour chaque reservation existante:
    // -> doit etre meme vehicule
    // teste si intervalle de temps est compatible
    foreach (Reservation* r, reservations) {
        if( r->getVehicule()!=newres->getVehicule() ) continue;
        if( compareIntervalles(r->getDebut(),r->getFin(),newres->getDebut(),newres->getFin())==0 ) return false;
    }
    return true;
}

bool ReservationModel::addReservations(const QList<Reservation *> &reservations)
{
    QList<Reservation*> accepted;
    foreach (Reservation *r, reservations)
        if (testReservation(r)) accepted.append(r);

    int count = accepted.count();

    if (count>0) {
        int pos = this->reservations.count();

        beginInsertRows(QModelIndex(), pos, pos+count-1);
        foreach (Reservation *r, accepted)
            this->reservations[r->getId()] = r;

        emit mayNeedFilterUpdate();

        endInsertRows();

        emit dataChanged(index(pos,0),index(pos+count-1,columnCount()));
    } else
        return false;

    return true;
}

bool ReservationModel::addReservation(Reservation *newres)
{    
    if (!testReservation(newres)) return false;

    int pos = reservations.count();
    beginInsertRows(QModelIndex(), pos, pos);

    reservations[newres->getId()] = newres;
    emit mayNeedFilterUpdate();

    endInsertRows();    

    emit dataChanged(index(pos,0),index(pos,columnCount()));

    return true;
}

bool ReservationModel::removeReservation(qint64 id)
{
    if (reservations.count(id) == 0) return false;

    QList<qint64>::const_iterator it = qFind(reservations.keys(),id);
    int pos = it-reservations.keys().begin();
    beginRemoveRows(QModelIndex(), pos, pos);
    reservations.remove(id);
    endRemoveRows();

    return true;
}

QDataStream& operator<<(QDataStream &ds, const ReservationModel &model)
{
    int count = model.reservations.count();

    ds << count;
    foreach (Reservation *r, model.reservations) {
        ds << (*r);
    }
    return ds;
}

QDataStream& operator>>(QDataStream &ds, ReservationModel &model)
{
    Reservation r;
    int count;

    model.beginResetModel();
    model.reservations.clear();
    ds >> count;
    for (int i=0; i<count; ++i) {
        ds >> r;
        model.reservations[r.id] = new Reservation(r);
    }
    model.endResetModel();
    return ds;
}


qint64 ReservationModel::getVehiculeStation(qint64 vehiculeId) {
    foreach (Reservation* reservation, reservations) {
        if (reservation->getVehicule() == vehiculeId)
            return reservation->getStation();
    }
    return -1;
}
