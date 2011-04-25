/*
 * station.cpp
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

#include "station.h"

/**
  Il faut absolument intialiser les champs
  statiques de cette maniere ... Sinon on risque
  de creer un bug lorsque on herite de cette classe
  et redefinit le champs headers parce qu'il se peut
  que ce champs ne soit pas encore initialise
  C'est le construct-on-first-use idiom :
  http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.8
*/
QStringList& Station::headers() {
    static QStringList _headers = QStringList()
            << trUtf8("id") <<
               trUtf8("Station") <<
               trUtf8("description") <<
               trUtf8("coffret") <<
               trUtf8("position") <<
               trUtf8("photo") <<
               trUtf8("carte") <<
               trUtf8("Distance") <<
               trUtf8("Information");
    return _headers;
}

Station::Station(uint id, QString nom, QString description,QString coffret, GeoPosition position, QPixmap photo, QPixmap carte, QObject *parent) :
    QObject(parent),
    id(id), nom(nom), description(description), coffret(coffret), position(position),
    photo(photo), carte(carte)
{
}

QVariant Station::field(uint column, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch (column)
        {
        case COL_ID: return id;
        case COL_NOM: return nom;
        case COL_DESCR: return description;
        case COL_COFF: return coffret;
        case COL_POS: return qVariantFromValue<GeoPosition>(position);
        default:
            break;
        }
        break;
    case Qt::DecorationRole:
        switch (column)
        {
        case COL_PHOTO: return photo;
        case COL_CARTE: return carte;
        default: break;
        }
        break;
    case Qt::SizeHintRole:
        switch (column)
        {
        case COL_PHOTO: return QSize(150,150);
        case COL_CARTE: return QSize(150,150);
        default: break;
        }
        break;
    }
    return QVariant();   
}

/*
bool Station::changeField(uint column, QVariant value)
{
    Q_UNUSED(column)
    Q_UNUSED(value)
    return false;
}
*/

uint Station::headerCount()
{
    return headers().count();
}

QVariant Station::header(uint column)
{
    if (column >= uint(headers().count()))
        return QVariant();

    return headers()[column];
}

//pas accessible pour personne d'autre que les sérialisateurs
Station::Station(const Station &s) :
    QObject(s.parent()),
    id(s.id), nom(s.nom), description(s.description), coffret(s.coffret), position(s.position), photo(s.photo),
    carte(s.carte)
{
}

QDataStream& operator<<(QDataStream &ds, const Station &station)
{
    ds << station.id << station.nom << station.description << station.coffret << station.position << station.photo << station.carte;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, Station &station)
{
    ds >> station.id >> station.nom >> station.description >> station.coffret >> station.position >> station.photo >> station.carte;
    return ds;
}
