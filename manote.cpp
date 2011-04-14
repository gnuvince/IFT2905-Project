/*
 * manote.cpp
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

#include "manote.h"
#include <QDebug>

QStringList MaNote::headers = Note::headers() << trUtf8(" rigolo");

MaNote::MaNote(qint64 usager, QDateTime date, int type, qint64 destinataire, QString description, qreal value, QObject *parent) :
    Note(usager, date, type, destinataire, description, parent),
    value(value)
{
}

QVariant MaNote::field(uint column, int role) const
{
    if (column < offset)
        return Note::field(column, role);

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    switch (column) {
    case COL_PERSO:
        return value;
    default:
        break;
    }

    return QVariant();
}

bool MaNote::changeField(uint column, QVariant val)
{
    bool ok;
    qreal v;

    if (column < offset)
        return Note::changeField(column, val);
    else {
        switch (column) {
        case COL_PERSO:
            v = val.toDouble(&ok);
            if (ok) {
                val = v;
                return true;
            }
            break;
        default:
            break;
        }
    }

    return false;
}
