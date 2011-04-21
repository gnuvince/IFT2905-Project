/*
 * stationmodel.h
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

#ifndef STATIONMODEL_H
#define STATIONMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include "station.h"

class StationModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit StationModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

    /*
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    */
    //bool addStation(Station *station);
    //bool removeStation(qint64 id);

    QList<Station*> getStations() const { return stations.values(); }

    Station* getStation(qint64 id) const { return stations.value(id,0); }


private:
    QVariant fieldAt(const QModelIndex &index, int role) const;
    GeoPosition *currentPosition;

signals:

public slots:

private:
    QMap<qint64, Station*> stations;

public:
    bool setStations(QString xml_path, QString photo_path);

private:
    friend QDataStream& operator<<(QDataStream& ds, const StationModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, StationModel &pos);
};

QDataStream& operator<<(QDataStream& ds, const StationModel &pos);
QDataStream& operator>>(QDataStream& ds, StationModel &pos);

#endif // STATIONMODEL_H
