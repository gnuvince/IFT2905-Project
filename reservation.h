/*
 * reservation.h
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

#ifndef RESERVATION_H
#define RESERVATION_H

#include <QObject>
#include <QVariant>
#include <QDateTime>
#include <QStringList>

class ReservationModel;

class Reservation : public QObject
{
    Q_OBJECT

public:
    enum Colonnes { COL_ID, COL_DEBUT, COL_FIN, COL_VEHICULE, COL_USAGER, COL_STATION, COL_PERSO };

public:
    explicit Reservation(QDateTime debut, QDateTime fin, qint64 vehicule, qint64 usager, qint64 station, QObject *parent=0);

    QVariant field(uint column, int role) const;
    bool changeField(uint column, QVariant value);

    qint64 getId() const { return id; }

    qint64 getVehicule() const { return vehicule; }
    void setVehicule(qint64 vehicule) { if (vehicule>=0) this->vehicule = vehicule; }

    qint64 getUsager() const { return usager; }
    void setUsager(qint64 usager) { if (usager>=0) this->usager = usager; }

    qint64 getStation() const { return station; }
    void setStation(qint64 station) { if (station>=0) this->station = station; }

    QDateTime getDebut() const { return debut; }
    void setDebut(const QDateTime &debut) { if (debut.isValid()) this->debut = debut; }

    QDateTime getFin() const { return fin; }
    void setFin(const QDateTime &fin) { if (fin.isValid()) this->fin = fin; }

    static uint headerCount();
    static QVariant header(uint column);

private:
    static qint64 idCount;
    qint64 id;

protected:
    qint64 vehicule;
    qint64 usager;
    qint64 station;
    QDateTime debut;
    QDateTime fin;

    static QStringList& headers();

private:
    friend QDataStream& operator<<(QDataStream& ds, const Reservation &pos);
    friend QDataStream& operator>>(QDataStream& ds, Reservation &pos);
    friend QDataStream& operator<<(QDataStream& ds, const ReservationModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, ReservationModel &pos);
    //pour le déserialisateur seulement ...
    Reservation(QObject *parent=0) : QObject(parent) {}
    Reservation(const Reservation &n);
};

QDataStream& operator<<(QDataStream& ds, const Reservation &pos);
QDataStream& operator>>(QDataStream& ds, Reservation &pos);

#endif // RESERVATION_H
