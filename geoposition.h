/*
 * geoposition.h
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

#ifndef GEOPOSITION_H
#define GEOPOSITION_H

#include <QMetaType>
#include <QVariant>

class GeoPosition
{
public:
    GeoPosition() { }
    GeoPosition(qreal lat, qreal lon);

    QString toString() const {
        return QObject::trUtf8("(%1,%2)").arg(lat,0,'g',5).arg(lon,0,'g',5);
    }
    bool isValid() const { return true; }

    qreal getLat() const { return lat; }
    void setLat(qreal lat) { this->lat = lat; }

    qreal getLon() const { return lon; }
    void setLon(qreal lon) { this->lon = lon; }

private:
    qreal lat, lon;

private:
    friend QDataStream& operator<<(QDataStream& ds, const GeoPosition &pos);
    friend QDataStream& operator>>(QDataStream& ds, GeoPosition &pos);
};

QDataStream& operator<<(QDataStream& ds, const GeoPosition &pos);
QDataStream& operator>>(QDataStream& ds, GeoPosition &pos);

Q_DECLARE_METATYPE(GeoPosition)
#endif // GEOPOSITION_H
