/*
 * usager.h
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

#ifndef USAGER_H
#define USAGER_H

#include <QObject>
#include <QDateTime>
#include <QVariant>
#include <QStringList>
#include "geoposition.h"

class UsagerModel;

class Usager : public QObject
{
    Q_OBJECT
public:
    enum Colonnes { COL_ID, COL_NOM, COL_POS, COL_PERSO };

public:
    explicit Usager(QString nom, GeoPosition pos, QObject *parent = 0);

    virtual QVariant field(uint column, int role) const;
    virtual bool changeField(uint column, QVariant value);

    qint64 getId() const { return id; }

    QString getNom() const { return nom; }
    void setNom(const QString &nom) { if (!nom.isNull()) this->nom = nom; }

    GeoPosition getPosition() const { return position; }
    void setPosition(const GeoPosition &position) { if (position.isValid()) this->position = position; }

    static uint headerCount();
    static QVariant header(uint column);

private:
    static qint64 idCount;
    qint64 id;

signals:

public slots:

protected:
    QString nom;
    GeoPosition position;

    static QStringList& headers();

private:
    friend QDataStream& operator<<(QDataStream& ds, const Usager &pos);
    friend QDataStream& operator>>(QDataStream& ds, Usager &pos);
    friend QDataStream& operator<<(QDataStream& ds, const UsagerModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, UsagerModel &pos);
    //pour le déserialisateur seulement ...
    Usager(QObject *parent=0) : QObject(parent) {}
    Usager(const Usager &n);
};

QDataStream& operator<<(QDataStream& ds, const Usager &pos);
QDataStream& operator>>(QDataStream& ds, Usager &pos);

#endif // USAGER_H
