/*
 * notemodel.cpp
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

#include "notemodel.h"

NoteModel::NoteModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

QVariant NoteModel::noteAt(const QModelIndex &index, int role) const
{
    uint row = index.row();
    uint column = index.column();

    qint64 id = notes.keys()[row];
    Note *n = notes[id];

    return n->field(column, role);
}

QVariant NoteModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    return noteAt(index, role);
}

int NoteModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return notes.count();
}

int NoteModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return Note::headerCount();
}

QVariant NoteModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        return Note::header(section);
    } else if (orientation == Qt::Vertical) {
        if (section < 0 || section >= notes.count())
            return QVariant();
        return section;
    }
    return QVariant();
}

bool NoteModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    if (role != Qt::EditRole)
        return false;

    uint row = index.row();
    uint column = index.column();

    qint64 id = notes.keys().value(row,-1);
    if (id < 0) return false;

    Note *r = notes[id];

    if (r->changeField(column, value)) {
        emit dataChanged(index,index);
        return true;
    }

    return false;
}

Qt::ItemFlags NoteModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlags();
    switch (index.column())
    {
    case Note::COL_DESC:
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    default:
        break;
    }

    return QAbstractTableModel::flags(index);
}

bool NoteModel::addNote(Note *note)
{
    //tester si elle est valide

    int pos = notes.count();
    beginInsertRows(QModelIndex(), pos, pos);
    notes[note->getId()] = note;
    endInsertRows();

    return true;
}

bool NoteModel::removeNote(qint64 id)
{
    if (notes.count(id) == 0) return false;

    QList<qint64>::const_iterator it = qFind(notes.keys(),id);
    int pos = it-notes.keys().begin();
    beginRemoveRows(QModelIndex(), pos, pos);
    notes.remove(id);
    endRemoveRows();

    return true;
}

QDataStream& operator<<(QDataStream &ds, const NoteModel &model)
{
    int count = model.notes.count();

    ds << count;
    foreach (Note *n, model.notes) {
        ds << (*n);
    }
    return ds;
}

QDataStream& operator>>(QDataStream &ds, NoteModel &model)
{
    Note n(&model);
    int count;

    model.beginResetModel();
    model.notes.clear();
    ds >> count;
    for (int i=0; i<count; ++i) {
        ds >> n;
        model.notes[n.id] = new Note(n);
    }
    model.endResetModel();
    return ds;
}
