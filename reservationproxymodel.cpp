/*
 * reservationproxy.cpp
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

#include "reservationproxymodel.h"
#include <QDebug>

ReservationProxyModel::ReservationProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent),
    debut(QDateTime()), fin(QDateTime()), station(-1), vehicule(-1), options(0)
{
}

void ReservationProxyModel::filter()
{
    ReservationModel *model = qobject_cast<ReservationModel*>(sourceModel());
    if (!model)
        return;

    QList<Reservation*> reservations = model->getReservations();
    QHash<qint64,Data> filtered;
    kept.clear();
    res.clear();

    if (debut.isValid() && fin.isValid()) {
        foreach (Reservation *r, reservations) {
            Data d = filtered.value(r->getVehicule());
            QDateTime cdebut = r->getDebut();
            QDateTime cfin = r->getFin();

            if (cfin <= debut) {
                //toutes les reservations passees
                if (!d.firstP) d.firstP = r;
                else if (cfin > d.firstP->getFin())
                    d.firstP = r;
            } else if (cdebut >= fin) {
                //toutes les reservations futures
                if (!d.firstF) d.firstF = r;
                else if (cdebut < d.firstF->getDebut())
                    d.firstF = r;
            }
            filtered[r->getVehicule()]=d;
        }
    }

    foreach (Reservation *r, reservations) {
        QDateTime cdebut = r->getDebut();
        QDateTime cfin = r->getFin();
        qint64 id = r->getId();
        qint64 cvehicule = r->getVehicule();
        bool bt, bs, bv;

        //test sur l'interval
        if (!debut.isValid() && !fin.isValid()) bt = true;
        else {
            bt = false;
            if (cfin <= debut && options.testFlag(Passe)) {
                //tester le plus proche :(
                if (options.testFlag(PlusProche)) {
                    if (filtered[cvehicule].firstP && id == filtered[cvehicule].firstP->getId())
                        bt = true;
                } else
                    bt = true;
            }
            else if (cdebut >= fin && options.testFlag(Futur)) {
                bt = true;
                //tester le plus proche :(
                if (options.testFlag(PlusProche)) {
                    if (filtered[cvehicule].firstF && id == filtered[cvehicule].firstF->getId())
                        bt = true;
                } else
                    bt = true;

            }
            else if ( (cfin > debut && cdebut < fin) && options.testFlag(Actif) ) {
                bt = true;
                //on ignore le plus proche
            }
        }

        if (options.testFlag(InverseInterval)) bt = !bt;

        if (!bt) {
            kept.append(false);
            continue;
        }

        //test sur le vehicule
        if (vehicule < 0) bv = true;
        else {
            bv = false;
            if (cvehicule == vehicule) bv = true;
        }

        if (options.testFlag(InverseVehicule)) bv = !bv;

        if (!bv) {
            kept.append(false);
            continue;
        }

        //test sur la station
        if (station < 0) bs = true;
        else {
            bs = false;
            if (filtered[cvehicule].firstP) {
                bs=( filtered[cvehicule].firstP->getStation() == station );
            }
        }

        if (options.testFlag(InverseStation)) bs = !bs;

        if (!bs) {
            kept.append(false);
        } else {
            kept.append(true);
            res.append(r);
        }
    }
}

bool ReservationProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent)
    return kept.value(source_row,false);
}

void ReservationProxyModel::setDynamicSortFilter(bool enable)
{
    if (!enable) {
        if (sourceModel()) {
            ReservationModel *model = qobject_cast<ReservationModel*>(sourceModel());
            disconnect(model, SIGNAL(mayNeedFilterUpdate()), this, SLOT(updateFilter()));
        }
    } else {
        ReservationModel *model = qobject_cast<ReservationModel*>(sourceModel());
        connect(model, SIGNAL(mayNeedFilterUpdate()), this, SLOT(updateFilter()));
    }
    QSortFilterProxyModel::setDynamicSortFilter(enable);
}

void ReservationProxyModel::updateFilter()
{
    filter();
}

void ReservationProxyModel::setFilterFields(const QDateTime &debut, const QDateTime &fin, qint64 vehicule, qint64 station, Options options)
{    
    this->options = options;
    this->debut = debut;
    this->fin = fin;
    this->vehicule = vehicule;
    this->station = station;

    updateFilter();
    invalidateFilter();
}
