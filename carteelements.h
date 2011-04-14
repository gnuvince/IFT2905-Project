/*
 * carteelements.h
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

#ifndef ELEMENTSCARTE_H
#define ELEMENTSCARTE_H

#include <QMetaType>
#include <QHash>
#include <QFont>
#include <QColor>
#include <QPen>
#include <QGraphicsPathItem>
#include <QGraphicsItemGroup>

typedef QHash<int,QPen> QHashIntQPen;
Q_DECLARE_METATYPE(QHashIntQPen)
typedef QHash<int,QBrush> QHashIntQBrush;
Q_DECLARE_METATYPE(QHashIntQBrush)
typedef QHash<int,QFont> QHashIntQFont;
Q_DECLARE_METATYPE(QHashIntQFont)
typedef QHash<int,bool> QHashIntBool;
Q_DECLARE_METATYPE(QHashIntBool)
typedef QHash<int,int> QHashIntInt;
Q_DECLARE_METATYPE(QHashIntInt)
typedef QHash<int,qreal> QHashIntReal;
Q_DECLARE_METATYPE(QHashIntReal)

class CarteElement {
public:
    /// Destructeur de la classe CarteElement
    virtual ~CarteElement() { }
    /// change les propriétés de tous les objets qui dérivent de CarteElement
    virtual void changeProprietes(const QHash<int,QVariant> &props, qreal scale) = 0;
};

class RueElement : public QPainterPath {
public:
    /// Constructeur vide de la classe RueElement
    RueElement() {}
    RueElement(const QList<QPointF> &noeuds, int id, QString nom, QString type);
    /// Énumération qui définit les types possibles de rue
    enum RueType {AUTOROUTE = 0, AUTOROUTE_BRETELLE, NATIONALE, NATIONALE_BRETELLE, PRIMAIRE, PRIMAIRE_BRETELLE,
                  SECONDAIRE, SECONDAIRE_BRETELLE, TERTIAIRE, NON_CLASSIFIE, ROUTE, RESIDENTIEL, RUE, CHEMIN, PEDESTRE,
                  COURSE, SERVICE, CYCLABLE, PIED, ESCALIER,
                  NON_SUPPORTE=20000};
    static const QStringList typesSupportes;

    /// Ce sont les clés que l'on peut modifier ou lire dans la table des propriétés
    enum Cle {
        CleCheminRueCrayon = 1000,
        CleCheminRueScaleMin,
        CleCheminRueScaleMax,
        CleCheminRueZValeur,
        CleBordureRueCrayon = 2000,
        CleBordureRueVisible,
        CleBordureRueScaleMin,
        CleBordureRueScaleMax,
        CleBordureRueZValeur,
        CleNomRueCrayon = 3000,
        CleNomRuePolice,
        CleNomRueScaleMin,
        CleNomRueScaleMax,
        CleNomRueZValeur,
        CleSensRueCrayon = 4000,
        CleSensRueScaleMin,
        CleSensRueScaleMax,
        CleSensRueZValeur
    };

    /// Retourne l'id unique de la rue
    int id() const { return _id; }
    /// Retourne le nom de la rue
    QString nom() const { return _nom; }
    /// Retourne le type de la rue
    RueType type() const { return _type; }
    /// Définit les propriétés par défaut de RueElement. On peut les utiliser
    /// directement ou en modifier une copie
    static QHash<int, QVariant> defautsProprietes;

private:
    int _id;
    QString _nom;
    RueType _type;
    static bool _init;
    static void init();
};

template <class T> void extraitDonnees(const QHash<int,QVariant> &props, const RueElement &rel,int cle, T *t);

class CheminRueElement : public QObject, public QGraphicsPathItem, public CarteElement {
    Q_OBJECT
public:
    CheminRueElement(RueElement rel, QGraphicsItem *parent=0);
    void changeProprietes(const QHash<int,QVariant> &props, qreal scale);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    RueElement rueElement() const { return _rel; }    

private:
    RueElement _rel;

signals:
    void sourisDessus();
    void sourisDehors();
};

class BordureRueElement : public QGraphicsPathItem, public CarteElement {
public:
    BordureRueElement(RueElement rel, QGraphicsItem *parent=0);
    void changeProprietes(const QHash<int,QVariant> &props, qreal scale);
    RueElement rueElement() const { return _rel; }

private:
    RueElement _rel;
};

class NomRueElement : public QGraphicsItemGroup, public CarteElement {
public:
    NomRueElement(RueElement rel, QGraphicsItem *parent=0);
    void changeProprietes(const QHash<int,QVariant> &props, qreal scale);
    RueElement rueElement() const { return _rel; }

private:
    void creerTexte();
    RueElement _rel;
    QPen _bordureCrayon;
    QFont _police;
    QPen _crayon;
};

class SensRueElement : public QGraphicsItemGroup, public CarteElement {
public:
    SensRueElement(RueElement rel, int sens, QGraphicsItem *parent=0);
    void changeProprietes(const QHash<int,QVariant> &props, qreal scale);
    RueElement rueElement() const { return _rel; }

private:
    void creerTexte();
    RueElement _rel;
    qreal _bordureTaille;
    int _sens;
};

#endif // ELEMENTSCARTE_H
