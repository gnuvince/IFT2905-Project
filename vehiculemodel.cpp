/*
 * vehiculemodel.cpp
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

#include "vehiculemodel.h"

#include <QFile>
#include <QXmlStreamReader>

VehiculeModel::VehiculeModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

QVariant VehiculeModel::fieldAt(const QModelIndex &index, int role) const
{
    uint row = index.row();
    uint column = index.column();

    qint64 id = vehicules.keys()[row];
    Vehicule *v = vehicules[id];

    if (column == Vehicule::COL_INFO && role == Qt::DecorationRole) {
        return QPixmap(":/icones/data/icons/help.png");
    }

    return v->field(column, role);
}

QVariant VehiculeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    return fieldAt(index, role);
}

int VehiculeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return vehicules.count();
}

int VehiculeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return Vehicule::headerCount();
}

QVariant VehiculeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        return Vehicule::header(section);
    } else if (orientation == Qt::Vertical) {
        if (section < 0 || section >= vehicules.count())
            return QVariant();
        return section;
    }
    return QVariant();
}

/*
bool VehiculeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    if (role != Qt::EditRole)
        return false;

    uint row = index.row();
    uint column = index.column();

    qint64 id = vehicules.keys().value(row,-1);
    if (id < 0) return false;

    Vehicule *v = vehicules[id];

    if (v->changeField(column, value)) {
        emit dataChanged(index,index);
        return true;
    }

    return false;
}

Qt::ItemFlags VehiculeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlags();
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
*/

/*
bool VehiculeModel::addVehicule(Vehicule *vehicule)
{
    //tester si elle est valide

    int pos = vehicules.count();
    beginInsertRows(QModelIndex(), pos, pos+1);
    vehicules[vehicule->getId()] = vehicule;
    endInsertRows();

    return true;
}
*/

bool VehiculeModel::setVehicules(QString xml_path, QString photo_path)
{
    QFile f(xml_path);
    if (!f.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;

    QXmlStreamReader rd;
    rd.setDevice(&f);

    beginResetModel();

    vehicules.clear();
    QHash<QString,QPixmap> photos;
    while (rd.readNextStartElement()) {
        if (rd.name() == "vehicule") {
            uint id;
            QString marque,modele,couleur,desc,photoName;
            while (rd.readNextStartElement()) {
                if (rd.isStartElement()) {
                    if (rd.name() == "id") {
                        id = rd.readElementText().toUInt();
                    } else if (rd.name() == "marque") {
                        marque = rd.readElementText();
                    } else if (rd.name() == "modele") {
                        modele = rd.readElementText();
                    } else if (rd.name() == "couleur") {
                        couleur = rd.readElementText();
                    } else if (rd.name() == "desc") {
                        desc = rd.readElementText();
                    } else if (rd.name() == "photo") {
                        photoName = rd.readElementText();
                    } else
                        rd.skipCurrentElement();
                }
            }

            QPixmap photo = photos.value(photoName,QPixmap());
            if (photo.isNull()) {
                QString path;
                path = QString("%2%1.png").arg(photoName).arg(photo_path);
                if (!photo.load(path))
                    return false;
                photos[photoName] = photo;
            }
            vehicules[id] = new Vehicule(id, marque,modele,couleur, desc,photo, this);
        }
    }

    endResetModel();

    return true;
}




QDataStream& operator<<(QDataStream &ds, const VehiculeModel &model)
{
    int count = model.vehicules.count();

    ds << count;
    QMap<qint64,QPixmap> images;
    foreach (Vehicule *v, model.vehicules) {
        qint64 key = v->photo.cacheKey();
        if (!images.contains(key))
                images[key] = v->photo;
        ds << (*v);
    }
    ds << images;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, VehiculeModel &model)
{
    Vehicule v;
    int count;

    model.beginResetModel();
    model.vehicules.clear();
    ds >> count;
    for (int i=0; i<count; ++i) {
        ds >> v;
        model.vehicules[v.id] = new Vehicule(v);
    }
    QMap<qint64,QPixmap> images;
    ds >> images;
    foreach (Vehicule *v, model.vehicules)
        v->photo = images[v->photoCache];
    model.endResetModel();
    return ds;
}

/*
bool VehiculeModel::removeVehicule(qint64 id)
{
    if (vehicules.count(id) == 0) return false;

    QList<qint64>::const_iterator it = qFind(vehicules.keys(),id);
    int pos = it-vehicules.keys().begin();
    beginRemoveRows(QModelIndex(), pos, pos+1);
    vehicules.remove(id);
    endRemoveRows();

    return true;
}
*/
