/*
 * stationmodel.cpp
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

#include "stationmodel.h"
#include <QFile>
#include <QXmlStreamReader>
#include "geoposition.h"
#include "station.h"
#include <QDebug>

StationModel::StationModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    currentPosition->setLat(45.525);
    currentPosition->setLon(-73.561);
    qDebug() << currentPosition->getLat();
    qDebug() << currentPosition->getLon();
}

QVariant StationModel::fieldAt(const QModelIndex &index, int role) const
{
    uint row = index.row();
    uint column = index.column();

    qint64 id = stations.keys()[row];
    Station *s = stations[id];
    if (column == Station::COL_DIST) {
        qreal distance = s->getPosition().distanceFrom(currentPosition);
        return QVariant(distance);
    }
    return s->field(column, role);
}

QVariant StationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    return fieldAt(index, role);
}

int StationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return stations.count();
}

int StationModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return Station::headerCount();
}

QVariant StationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        return Station::header(section);
    } else if (orientation == Qt::Vertical) {
        if (section < 0 || section >= stations.count())
            return QVariant();
        return section;
    }
    return QVariant();
}

/*
bool StationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    if (role != Qt::EditRole)
        return false;

    uint row = index.row();
    uint column = index.column();

    qint64 id = stations.keys().value(row,-1);
    if (id < 0) return false;

    Station *s = stations[id];

    if (s->changeField(column, value)) {
        emit dataChanged(index,index);
        return true;
    }

    return false;
}

Qt::ItemFlags StationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlags();
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
*/

#include <QDebug>

bool StationModel::setStations(QString xml_path, QString photo_path)
{
    QFile f(xml_path);
    if (!f.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;

    QXmlStreamReader rd;
    rd.setDevice(&f);

    beginResetModel();

    stations.clear();
    while (rd.readNextStartElement()) {
        if (rd.name() == "station") {
            uint id;
            QString nom,desc,coffret;
            qreal lat, lon;
            while (rd.readNextStartElement()) {
                if (rd.isStartElement()) {
                    if (rd.name() == "num") {
                        id = rd.readElementText().toUInt();
                    } else if (rd.name() == "nom") {
                        nom = rd.readElementText();
                    } else if (rd.name() == "description") {
                        desc = rd.readElementText();
                    } else if (rd.name() == "coffret") {
                        coffret = rd.readElementText();
                    } else if (rd.name() == "lat") {
                        lat = rd.readElementText().toDouble();
                    } else if (rd.name() == "lng") {
                        lon = rd.readElementText().toDouble();
                    } else
                        rd.skipCurrentElement();
                }
            }
            QPixmap photo, map;
            QString path;
            path = QString("%2photo%1.jpg").arg(QString::number(id).rightJustified(3,QChar('0'))).arg(photo_path);
            if (!photo.load(path))
                return false;
            path = QString("%2map%1.gif").arg(QString::number(id).rightJustified(3,QChar('0'))).arg(photo_path);
            if (!map.load(path))
                return false;

            stations[id] = new Station(id, nom, desc,coffret, GeoPosition(lat,lon), photo, map, this);
        }
    }

    endResetModel();

    return true;
}

/*
bool StationModel::addStation(Station *station)
{
    //tester si elle est valide

    int pos = stations.count();
    beginInsertRows(QModelIndex(), pos, pos+1);
    stations[station->getId()] = station;
    endInsertRows();

    return true;
}

bool StationModel::removeStation(qint64 id)
{
    if (stations.count(id) == 0) return false;

    QList<qint64>::const_iterator it = qFind(stations.keys(),id);
    int pos = it-stations.keys().begin();
    beginRemoveRows(QModelIndex(), pos, pos+1);
    stations.remove(id);
    endRemoveRows();

    return true;
}
*/

QDataStream& operator<<(QDataStream &ds, const StationModel &model)
{
    int count = model.stations.count();

    ds << count;
    foreach (Station *s, model.stations) {
        ds << (*s);
    }
    return ds;
}

QDataStream& operator>>(QDataStream &ds, StationModel &model)
{
    Station s;
    int count;

    model.beginResetModel();
    model.stations.clear();
    ds >> count;
    for (int i=0; i<count; ++i) {
        ds >> s;
        model.stations[s.id] = new Station(s);
    }
    model.endResetModel();
    return ds;
}
