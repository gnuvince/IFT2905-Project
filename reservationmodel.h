/*
 * reservationmodel.h
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

#ifndef RESERVATIONMODEL_H
#define RESERVATIONMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include "reservation.h"

class ReservationProxyModel;

class ReservationModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ReservationModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;


    bool testReservation(Reservation *reservation) const;

    bool addReservations(const QList<Reservation*> &reservations);
    bool addReservation(Reservation *reservation);
    bool removeReservation(qint64 id);

    QList<Reservation*> getReservations() const { return reservations.values(); }
    Reservation* getReservation(qint64 id) const { return reservations.value(id,0); }

    static int compareIntervalles(QDateTime A,QDateTime B,QDateTime C,QDateTime D);

    static const quint32 MAGIC_NUMBER = 0x182f3a41;

private:
    QVariant fieldAt(const QModelIndex &index, int role) const;

signals:
    void mayNeedFilterUpdate();

public slots:

private:
    QMap<qint64, Reservation*> reservations;

private:
    friend QDataStream& operator<<(QDataStream& ds, const ReservationModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, ReservationModel &pos);
    friend class ReservationProxyModel;
};

QDataStream& operator<<(QDataStream& ds, const ReservationModel &pos);
QDataStream& operator>>(QDataStream& ds, ReservationModel &pos);

#endif // RESERVATIONMODEL_H
