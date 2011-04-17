/*
 * geoposition.cpp
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

#include "geoposition.h"

#include <cmath>

GeoPosition::GeoPosition(qreal lat, qreal lon) :
    lat(lat), lon(lon)
{
}


qreal toRad(double deg) {
    return deg * M_PI / 180.0;
}

qreal GeoPosition::distanceFrom(GeoPosition *other) {
    qreal R = 6371; // Diameter of the Earth
    qreal lat1 = toRad(this->getLat()),
            lat2 = toRad(other->getLat()),
            lon1 = toRad(this->getLon()),
            lon2 = toRad(other->getLon());
    return acos(sin(lat1) * sin(lat2) +
                cos(lat1) * cos(lat2) *
                cos(lon2 - lon1)) * R;
}

QDataStream& operator<<(QDataStream &ds, const GeoPosition &pos)
{
    ds << pos.lat << pos.lon;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, GeoPosition &pos)
{
    ds >> pos.lat >> pos.lon;
    return ds;
}
