/*
 * vehiculemodel.h
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

#ifndef VEHICULEMODEL_H
#define VEHICULEMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include "vehicule.h"

class VehiculeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit VehiculeModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;
    /*
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    */

    //bool addVehicule(Vehicule *Vehicule);
    //bool removeVehicule(qint64 id);

    bool setVehicules(QString xml_path, QString photo_path);

    QList<Vehicule*> getVehicules() const { return vehicules.values(); }

    Vehicule* getVehicule(qint64 id) const { return vehicules.value(id,0); }

private:
    QVariant fieldAt(const QModelIndex &index, int role) const;

signals:

public slots:

private:
    QMap<qint64, Vehicule*> vehicules;

private:
    friend QDataStream& operator<<(QDataStream& ds, const VehiculeModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, VehiculeModel &pos);
};

QDataStream& operator<<(QDataStream& ds, const VehiculeModel &pos);
QDataStream& operator>>(QDataStream& ds, VehiculeModel &pos);

#endif // VEHICULEMODEL_H
