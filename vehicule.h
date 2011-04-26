/*
 * vehicule.h
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

#ifndef VEHICULE_H
#define VEHICULE_H

#include <QObject>
#include <QDateTime>
#include <QVariant>
#include <QStringList>
#include <QPixmap>

class VehiculeModel;

class Vehicule : public QObject
{
    Q_OBJECT
public:
    enum Colonnes { COL_ID, COL_MARQUE, COL_MODELE, COL_COULEUR, COL_DESCRIPTION, COL_PHOTO, COL_INFO };

    explicit Vehicule(qint64 id,QString marque,QString modele,QString couleur,QString description,QPixmap photo, QObject *parent=0);

    virtual QVariant field(uint column, int role) const;
    //virtual bool changeField(uint column, QVariant value);

    qint64 getId() const { return id; }

    QString getMarque() const { return marque; }
    //void setMarque(const QString &marque) { if (!marque.isNull()) this->marque = marque; }

    QString getModele() const { return modele; }
    //void setModele(const QString &modele) { if (!modele.isNull()) this->modele = modele; }

    QString getCouleur() const { return couleur; }
    //void setCouleur(const QString &couleur) { if (!couleur.isNull()) this->couleur = couleur; }

    QString getDescription() const { return description; }
    //void setDescription(const QString &description) { if (!description.isNull()) this->description = description; }

    QPixmap getPhoto() const { return photo; }
    //void setPhoto(const QPixmap &photo) { if (!photo.isNull()) this->photo = photo; }

    static uint headerCount();
    static QVariant header(uint column);

private:
    qint64 id;

signals:

public slots:

protected:
    QString marque;
    QString modele;
    QString couleur;
    QString description;
    QPixmap photo;
    qint64 photoCache;
    static QStringList& headers();

private:
    friend QDataStream& operator<<(QDataStream& ds, const Vehicule &pos);
    friend QDataStream& operator>>(QDataStream& ds, Vehicule &pos);
    friend QDataStream& operator<<(QDataStream& ds, const VehiculeModel &pos);
    friend QDataStream& operator>>(QDataStream& ds, VehiculeModel &pos);
    //pour le déserialisateur seulement ...
    Vehicule(QObject *parent=0) : QObject(parent) {}
    Vehicule(const Vehicule &n);
};

QDataStream& operator<<(QDataStream& ds, const Vehicule &pos);
QDataStream& operator>>(QDataStream& ds, Vehicule &pos);

#endif // VEHICULE_H
