/*
 * usagermodel.cpp
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

#include "usagermodel.h"

UsagerModel::UsagerModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

QVariant UsagerModel::usagerAt(const QModelIndex &index, int role) const
{
    uint row = index.row();
    uint column = index.column();

    qint64 id = usagers.keys()[row];
    Usager *u = usagers[id];

    return u->field(column, role);
}

QVariant UsagerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    return usagerAt(index, role);
}

int UsagerModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return usagers.count();
}

int UsagerModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return Usager::headerCount();
}

QVariant UsagerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        return Usager::header(section);
    } else if (orientation == Qt::Vertical) {
        if (section < 0 || section >= usagers.count())
            return QVariant();
        return section;
    }
    return QVariant();
}

bool UsagerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    if (role != Qt::EditRole)
        return false;

    uint row = index.row();
    uint column = index.column();

    qint64 id = usagers.keys().value(row,-1);
    if (id < 0) return false;

    Usager *u = usagers[id];

    if (u->changeField(column, value)) {
        emit dataChanged(index,index);
        return true;
    }

    return false;
}

Qt::ItemFlags UsagerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlags();
    switch (index.column()) {
    case Usager::COL_NOM:
    case Usager::COL_POS:
    case Usager::COL_PERSO:
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    default:
        break;
    }
    return QAbstractTableModel::flags(index);
}

bool UsagerModel::addUsager(Usager *usager)
{
    //tester si elle est valide

    int pos = usagers.count();
    beginInsertRows(QModelIndex(), pos, pos);
    usagers[usager->getId()] = usager;
    endInsertRows();

    return true;
}

bool UsagerModel::removeUsager(qint64 id)
{
    if (usagers.count(id) == 0) return false;

    QList<qint64>::const_iterator it = qFind(usagers.keys(),id);
    int pos = it-usagers.keys().begin();
    beginRemoveRows(QModelIndex(), pos, pos);
    usagers.remove(id);
    endRemoveRows();

    return true;
}



QDataStream& operator<<(QDataStream &ds, const UsagerModel &model)
{
    int count = model.usagers.count();

    ds << count;
    foreach (Usager *u, model.usagers) {
        ds << (*u);
    }
    return ds;
}

QDataStream& operator>>(QDataStream &ds, UsagerModel &model)
{
    Usager u;
    int count;

    model.beginResetModel();
    model.usagers.clear();
    ds >> count;
    for (int i=0; i<count; ++i) {
        ds >> u;
        model.usagers[u.id] = new Usager(u);
    }
    model.endResetModel();
    return ds;
}
