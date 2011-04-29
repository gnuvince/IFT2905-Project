/*
 * reservation.cpp
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

#include "reservation.h"
#include <QSize>

qint64 Reservation::idCount = 0;

/**
  Il faut absolument intialiser les champs
  statiques de cette maniere ... Sinon on risque
  de creer un bug lorsque on herite de cette classe
  et redefinit le champs headers parce qu'il se peut
  que ce champs ne soit pas encore initialise
  C'est le construct-on-first-use idiom :
  http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.8
*/
QStringList& Reservation::headers() {
    static QStringList _headers = QStringList()
            << trUtf8("id")
            << trUtf8("Début")
            << trUtf8("Fin")
            << trUtf8("Véhicule")
            << trUtf8("usager")
            << trUtf8("Station");
    return _headers;
}

Reservation::Reservation(QDateTime debut, QDateTime fin, qint64 vehicule, qint64 usager, qint64 station, QObject *parent) :
    QObject(parent),
    id(idCount), vehicule(vehicule), usager(usager), station(station), debut(debut), fin(fin)
{
    idCount++;
}


QVariant Reservation::field(uint column, int role) const
{

    switch(role) {
      case Qt::DisplayRole:
      case Qt::EditRole:
        switch (column)
        {
        case COL_ID: return id;
        case COL_DEBUT: return debut;
        case COL_FIN: return fin;
        case COL_VEHICULE: return vehicule;
        case COL_USAGER: return usager;
        case COL_STATION: return station;
        default:
            break;
        }
        break;
    }
    return QVariant();
}

bool Reservation::changeField(uint column, QVariant value)
{
    bool ok;
    QDateTime d;
    qint64 i;

    switch (column)
    {
    case COL_DEBUT:
        d = value.toDateTime();
        if (d.isValid()) {
            debut = d;
            return true;
        }
        break;
    case COL_FIN:
        d = value.toDateTime();
        if (d.isValid()) {
            fin = d;
            return true;
        }
        break;
    case COL_VEHICULE:
        i = value.toLongLong(&ok);
        if (ok) {
            vehicule = i;
            return true;
        }
        break;
    case COL_USAGER:
        i = value.toLongLong(&ok);
        if (ok) {
            usager = i;
            return true;
        }
        break;
    case COL_STATION:
        i = value.toLongLong(&ok);
        if (ok) {
            station = i;
            return true;
        }
        break;
    default:
        break;
    }

    return false;
}

uint Reservation::headerCount()
{
    return headers().count();
}

QVariant Reservation::header(uint column)
{
    if (column >= uint(headers().count()))
        return QVariant();

    return headers()[column];
}

//pas accessible pour personne d'autre que les sérialisateurs
Reservation::Reservation(const Reservation &r) :
    QObject(r.parent()),
    id(r.id), vehicule(r.vehicule), usager(r.usager), station(r.station), debut(r.debut), fin(r.fin)
{
    if (id>idCount) idCount = id;
}

QDataStream& operator<<(QDataStream &ds, const Reservation &res)
{
    ds << res.id << res.vehicule << res.usager << res.station << res.debut << res.fin;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, Reservation &res)
{
    ds >> res.id >> res.vehicule >> res.usager >> res.station >> res.debut >> res.fin;
    return ds;
}

