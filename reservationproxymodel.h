/*
 * reservationproxy.h
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

#ifndef RESERVATIONPROXY_H
#define RESERVATIONPROXY_H

#include <QSortFilterProxyModel>
#include <QHash>
#include "reservationmodel.h"

class ReservationProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    enum Option {
        Passe = (1<<0),
        Actif = (1<<1),
        Futur = (1<<2),
        PlusProche = (1<<3),
        InverseInterval = (1<<4),
        InverseVehicule = (1<<5),
        InverseStation = (1<<6)
    };
    Q_DECLARE_FLAGS(Options, Option)
public:
    explicit ReservationProxyModel(QObject *parent = 0);

    void setFilterFields(const QDateTime &debut, const QDateTime &fin, qint64 vehicule, qint64 station, Options options);
    QList<Reservation*> getFilteredReservations() const { return res; }

    void setDynamicSortFilter(bool enable);

private slots:
    void updateFilter();

signals:

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    struct Data {
        Data() : firstP(0), firstF(0) {}
        Reservation *firstP, *firstF;
    };

    QDateTime debut, fin;
    qint64 vehicule;
    qint64 station;
    Options options;

    QList<bool> kept;
    QList<Reservation*> res;

private:
    void filter();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(ReservationProxyModel::Options)
#endif // RESERVATIONPROXY_H
