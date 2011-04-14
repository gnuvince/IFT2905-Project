/*
 * notemodel.h
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

#ifndef NOTEMODEL_H
#define NOTEMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include "note.h"

class NoteModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit NoteModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool addNote(Note *note);
    bool removeNote(qint64 id);

    QList<Note*> getNotes() const { return notes.values(); }
    Note* getNote(qint64 id) const { return notes.value(id,0); }

private:
    QVariant noteAt(const QModelIndex &index, int role) const;

signals:

public slots:

private:
    QMap<qint64, Note*> notes;

private:
    friend QDataStream& operator<<(QDataStream& ds, const NoteModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, NoteModel &pos);
};

QDataStream& operator<<(QDataStream& ds, const NoteModel &pos);
QDataStream& operator>>(QDataStream& ds, NoteModel &pos);

#endif // NOTEMODEL_H
