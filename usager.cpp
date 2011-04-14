/*
 * usager.cpp
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

#include "usager.h"

qint64 Usager::idCount = 0;

/**
  Il faut absolument intialiser les champs
  statiques de cette maniere ... Sinon on risque
  de creer un bug lorsque on herite de cette classe
  et redefinit le champs headers parce qu'il se peut
  que ce champs ne soit pas encore initialise
  C'est le construct-on-first-use idiom :
  http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.8
*/
QStringList& Usager::headers() {
    static QStringList _headers = QStringList()
            << trUtf8("id") <<
               trUtf8("nom") <<
               trUtf8("position");
    return _headers;
}

Usager::Usager(QString nom, GeoPosition position, QObject *parent) :
    QObject(parent),
    id(idCount), nom(nom), position(position)
{
    idCount++;
}

QVariant Usager::field(uint column, int role) const
{
    switch(role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch (column)
        {
        case COL_ID: return id;
        case COL_NOM: return nom;
        case COL_POS: return qVariantFromValue<GeoPosition>(position);
        default:
            break;
        }
        break;
    }

    return QVariant();
}

bool Usager::changeField(uint column, QVariant value)
{    
    QString s;
    GeoPosition p;

    switch (column)
    {
    case COL_NOM:
        s = value.toString();
        if (!s.isEmpty()) {
            nom = s;
            return true;
        }
        break;
    case COL_POS:
        p = qVariantValue<GeoPosition>(value);
        if (p.isValid()) {
            position = p;
            return true;
        }
        break;
    default:
        break;
    }

    return false;
}


uint Usager::headerCount()
{
    return headers().count();
}

QVariant Usager::header(uint column)
{
    if (column >= uint(headers().count()))
        return QVariant();

    return headers()[column];
}

//pas accessible pour personne d'autre que les sérialisateurs
Usager::Usager(const Usager &u) :
    QObject(u.parent()),
    id(u.id), nom(u.nom), position(u.position)
{
    if (id>idCount) idCount = id;
}

QDataStream& operator<<(QDataStream &ds, const Usager &usager)
{
    ds << usager.id << usager.nom << usager.position;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, Usager &usager)
{
    ds >> usager.id >> usager.nom >> usager.position;
    return ds;
}
