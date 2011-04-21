/*
 * station.h
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

#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QPixmap>
#include <QVariant>
#include <QDateTime>
#include <QStringList>
#include "geoposition.h"

class StationModel;

class Station : public QObject
{
    Q_OBJECT
public:
    enum Colonnes { COL_ID, COL_NOM, COL_DESCR, COL_COFF, COL_POS, COL_PHOTO, COL_CARTE, COL_DIST };

public:
    explicit Station(uint id, QString nom, QString description, QString coffret, GeoPosition position, QPixmap stationImage, QPixmap mapImage, QObject *parent = 0);

    QVariant field(uint column, int role) const;
    //bool changeField(uint column, QVariant value);

    qint64 getId() const { return id; }

    QString getNom() const { return nom; }
    //void setNom(const QString &nom) { if (!nom.isNull()) this->nom = nom; }

    QString getDescription() const { return description; }
    //void setDescription(const QString &description) { if (!description.isNull()) this->description = description; }

    QString getCoffret() const { return coffret; }
    //void setCoffret(const QString &coffret) { if (!coffret.isNull()) this->coffret = coffret; }

    GeoPosition getPosition() const { return position; }
    //void setPosition(const GeoPosition &position) { if (position.isValid()) this->position = position; }

    QPixmap getPhoto() const { return photo; }
    //void setPhoto(const QPixmap &photo) { if (!photo.isNull()) this->photo = photo; }

    QPixmap getCarte() const { return carte; }
    //void setCarte(const QPixmap &carte) { if (!carte.isNull()) this->carte = carte; }

    static uint headerCount();
    static QVariant header(uint column);

signals:

public slots:

private:
    qint64 id;

protected:
    QString nom;
    QString description;
    QString coffret;
    GeoPosition position;
    QPixmap photo;
    QPixmap carte;
    static QStringList& headers();

private:
    friend QDataStream& operator<<(QDataStream& ds, const Station &pos);
    friend QDataStream& operator>>(QDataStream& ds, Station &pos);
    friend QDataStream& operator<<(QDataStream& ds, const StationModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, StationModel &pos);
    //pour le déserialisateur seulement ...
    Station(QObject *parent=0) : QObject(parent) {}
    Station(const Station &n);
};

QDataStream& operator<<(QDataStream& ds, const Station &pos);
QDataStream& operator>>(QDataStream& ds, Station &pos);

#endif // STATION_H
