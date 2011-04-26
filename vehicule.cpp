/*
 * vehicule.cpp
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

#include "vehicule.h"


/**
  Il faut absolument intialiser les champs
  statiques de cette maniere ... Sinon on risque
  de creer un bug lorsque on herite de cette classe
  et redefinit le champs headers parce qu'il se peut
  que ce champs ne soit pas encore initialise
  C'est le construct-on-first-use idiom :
  http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.8
*/
QStringList& Vehicule::headers() {
    static QStringList _headers = QStringList()
            << trUtf8("id")
            << trUtf8("Marque")
            << trUtf8("Modèle")
            << trUtf8("couleur")
            << trUtf8("description")
            << trUtf8("photo")
            << trUtf8("Info");
    return _headers;
}

Vehicule::Vehicule(qint64 id,QString marque,QString modele,QString couleur,QString description,QPixmap photo, QObject *parent) :
    QObject(parent),
    id(id), marque(marque), modele(modele), couleur(couleur), description(description), photo(photo), photoCache(photo.cacheKey())
{
}

QVariant Vehicule::field(uint column, int role) const
{

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch (column)
        {
        case COL_ID: return id;
        case COL_MARQUE: return marque;
        case COL_MODELE: return modele;
        case COL_COULEUR: return couleur;
        case COL_DESCRIPTION: return description;
        default: break;
        }
        break;
    case Qt::DecorationRole:
        switch (column)
        {
        case COL_PHOTO: return photo;
        default: break;
        }
    case Qt::SizeHintRole:
        switch (column)
        {
        case COL_PHOTO: return QSize(150,150);
        default: break;
        }
        break;
    }

    return QVariant();
}

/*
bool Vehicule::changeField(uint column, QVariant value)
{
    Q_UNUSED(column)
    Q_UNUSED(value)
    return false;
}
*/

uint Vehicule::headerCount()
{
    return headers().count();
}

QVariant Vehicule::header(uint column)
{
    if (column >= uint(headers().count()))
        return QVariant();

    return headers()[column];
}

//pas accessible pour personne d'autre que les sérialisateurs
Vehicule::Vehicule(const Vehicule &v) :
    QObject(v.parent()),
    id(v.id), marque(v.marque), modele(v.modele), couleur(v.couleur), description(v.description), photoCache(v.photoCache)
{
}

QDataStream& operator<<(QDataStream &ds, const Vehicule &vehicule)
{
    ds << vehicule.id << vehicule.marque << vehicule.modele << vehicule.couleur << vehicule.description << vehicule.photoCache;
    return ds;
}

QDataStream& operator>>(QDataStream &ds, Vehicule &vehicule)
{
        ds >> vehicule.id >> vehicule.marque >> vehicule.modele >> vehicule.couleur >> vehicule.description >> vehicule.photoCache;
    return ds;
}
