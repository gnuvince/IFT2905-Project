/*
 * note.cpp
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

#include "note.h"

qint64 Note::idCount = 0;

/**
  Il faut absolument intialiser les champs
  statiques de cette maniere ... Sinon on risque
  de creer un bug lorsque on herite de cette classe
  et redefinit le champs headers parce qu'il se peut
  que ce champs ne soit pas encore initialise
  C'est le construct-on-first-use idiom :
  http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.8
*/
QStringList& Note::headers() {
    static QStringList _headers = QStringList()
            << trUtf8("id") <<
               trUtf8("usager") <<
               trUtf8("date") <<
               trUtf8("type") <<
               trUtf8("destinataire") <<
               trUtf8("description");
    return _headers;
}

Note::Note(qint64 usager, QDateTime date, int type, qint64 destinataire, QString description, QObject *parent) :
    QObject(parent),
 id(idCount), usager(usager), destinataire(destinataire), date(date), type(type), description(description)
{
    idCount++;
}


QVariant Note::field(uint column, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch (column)
        {
        case COL_ID: return id;
        case COL_USAGER: return usager;
        case COL_DATE: return date;
        case COL_TYPE: return type;
        case COL_DEST: return destinataire;
        case COL_DESC: return description;
        default:
            break;
        }
    default:
        break;
    }

    return QVariant();
}


bool Note::changeField(uint column, QVariant value)
{
    QString s;

    switch (column)
    {
    case COL_DESC:
        s = value.toString();
        if (!s.isEmpty()) {
            description = s;
            return true;
        }
        break;
    default:
        break;
    }

    return false;
}


uint Note::headerCount()
{
    return headers().count();
}

QVariant Note::header(uint column)
{
    if (column >= uint(headers().count()))
        return QVariant();

    return headers()[column];
}


//pas accessible pour personne d'autre que les sérialisateurs
Note::Note(const Note &n) :
    QObject(n.parent()),
    id(n.id), usager(n.usager), destinataire(n.destinataire), date(n.date), type(n.type), description(n.description)
{
    if (id>idCount) idCount = id;
}

QDataStream& operator<<(QDataStream &ds, const Note &note)
{
    ds << note.id << note.usager << note.destinataire << note.date << note.type << note.description;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, Note &note)
{
    ds >> note.id >> note.usager >> note.destinataire >> note.date >> note.type >> note.description;
    return ds;
}
