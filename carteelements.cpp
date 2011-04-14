/*
 * carteelements.cpp
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

#include "carteelements.h"
#include <QtGui>
#include <limits>

using std::numeric_limits;

bool RueElement::_init = false;
QHash<int, QVariant> RueElement::defautsProprietes;

template <class T>
void extraitDonnees(const QHash<int,QVariant> &props, const RueElement &rel,int cle, T *t)
{
    T _t;
    {
        QVariant defvar = RueElement::defautsProprietes[cle];
        QHash<int, T> defvals = qVariantValue< QHash<int,T> >(defvar);
        QHash<int, T> vals;
        if (props.contains(cle) &&
                props[cle].userType() == qMetaTypeId< QHash<int, T> >())
            vals = qVariantValue< QHash<int, T> >(props[cle]);
        if (vals.contains(rel.type()))
            _t = vals[rel.type()];
        else
            _t = defvals[rel.type()];
    }
    *t = _t;
}

void RueElement::init()
{
    const qreal AUTOROUTE_size = 20.0;
    const qreal NATIONALE_size = 18.0;
    const qreal PRIMAIRE_size = 15.0;
    const qreal SECONDAIRE_size = 12.0;
    const qreal TERTIAIRE_size = 10.0;
    const qreal NON_CLASSIFIE_size = 9.0;
    const qreal RESIDENTIEL_size = 8.0;
    const qreal RUE_size = 7.0;
    const qreal SERVICE_size = 7.0;
    const qreal CYCLABLE_size = 6.0;
    const qreal PIED_size = 4.0;

    /**********************************************/
    /************* CHEMIN *************************/
    /**********************************************/

    QHash<int,QPen> cheminRueCrayon;
    cheminRueCrayon[AUTOROUTE] = cheminRueCrayon[AUTOROUTE_BRETELLE] = QPen(Qt::red,AUTOROUTE_size*0.9);
    cheminRueCrayon[NATIONALE] = cheminRueCrayon[NATIONALE_BRETELLE] = QPen(Qt::blue,NATIONALE_size*0.9);
    cheminRueCrayon[PRIMAIRE] = cheminRueCrayon[PRIMAIRE_BRETELLE] = QPen(Qt::green,PRIMAIRE_size*0.9);
    cheminRueCrayon[SECONDAIRE] = cheminRueCrayon[SECONDAIRE_BRETELLE] = QPen(QColor(0,170,0),SECONDAIRE_size*0.9);
    cheminRueCrayon[TERTIAIRE] = QPen(QColor(0,85,0),TERTIAIRE_size*0.9);
    cheminRueCrayon[NON_CLASSIFIE] = QPen(Qt::darkCyan,NON_CLASSIFIE_size*0.9);
    cheminRueCrayon[RESIDENTIEL] = QPen(Qt::white,RUE_size*0.9);
    cheminRueCrayon[RUE] = QPen(Qt::white,RUE_size*0.9);
    cheminRueCrayon[SERVICE] = QPen(Qt::white,SERVICE_size*0.9);
    cheminRueCrayon[CYCLABLE] = QPen(QColor(0,0,128),CYCLABLE_size*0.9,Qt::DashDotLine);
    cheminRueCrayon[PIED] = QPen(QColor(15,15,15),PIED_size*0.9);
    defautsProprietes[CleCheminRueCrayon] = qVariantFromValue<QHashIntQPen>(cheminRueCrayon);

    QHash<int,qreal> cheminRueScaleMin;
    QHash<int,qreal> cheminRueScaleMax;
    cheminRueScaleMin[AUTOROUTE] = cheminRueScaleMin[AUTOROUTE_BRETELLE] = 0.;
    cheminRueScaleMin[NATIONALE] = cheminRueScaleMin[NATIONALE_BRETELLE] = 0.;
    cheminRueScaleMin[PRIMAIRE] = cheminRueScaleMin[PRIMAIRE_BRETELLE] = 0.;
    cheminRueScaleMin[SECONDAIRE] = cheminRueScaleMin[SECONDAIRE_BRETELLE] = 0.;


    cheminRueScaleMax[AUTOROUTE] = cheminRueScaleMax[AUTOROUTE_BRETELLE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[NATIONALE] = cheminRueScaleMax[NATIONALE_BRETELLE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[PRIMAIRE] = cheminRueScaleMax[PRIMAIRE_BRETELLE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[SECONDAIRE] = cheminRueScaleMax[SECONDAIRE_BRETELLE] = numeric_limits<qreal>::max();


    cheminRueScaleMin[TERTIAIRE] = 2.5;
    cheminRueScaleMin[NON_CLASSIFIE] = 2.5;
    cheminRueScaleMin[RESIDENTIEL] = 2.5;

    cheminRueScaleMin[RUE] = 5.;
    cheminRueScaleMin[SERVICE] = 5.;
    cheminRueScaleMin[CYCLABLE] = 5.;
    cheminRueScaleMin[PIED] = 5.;

    cheminRueScaleMax[TERTIAIRE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[NON_CLASSIFIE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[RESIDENTIEL] = numeric_limits<qreal>::max();
    cheminRueScaleMax[RUE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[SERVICE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[CYCLABLE] = numeric_limits<qreal>::max();
    cheminRueScaleMax[PIED] = numeric_limits<qreal>::max();

    defautsProprietes[CleCheminRueScaleMin] = qVariantFromValue<QHashIntReal>(cheminRueScaleMin);
    defautsProprietes[CleCheminRueScaleMax] = qVariantFromValue<QHashIntReal>(cheminRueScaleMax);

    QHash<int,int> cheminRueZValeur;
    cheminRueZValeur[AUTOROUTE] = cheminRueZValeur[AUTOROUTE_BRETELLE] = 50;
    cheminRueZValeur[NATIONALE] = cheminRueZValeur[NATIONALE_BRETELLE] = 48;
    cheminRueZValeur[PRIMAIRE] = cheminRueZValeur[PRIMAIRE_BRETELLE] = 45;
    cheminRueZValeur[SECONDAIRE] = cheminRueZValeur[SECONDAIRE_BRETELLE] = 40;
    cheminRueZValeur[TERTIAIRE] = 35;
    cheminRueZValeur[NON_CLASSIFIE] = 32;
    cheminRueZValeur[RESIDENTIEL] = 30;
    cheminRueZValeur[RUE] = 25;
    cheminRueZValeur[SERVICE] = 20;
    cheminRueZValeur[CYCLABLE] = 10;
    cheminRueZValeur[PIED] = 8;
    defautsProprietes[CleCheminRueZValeur] = qVariantFromValue<QHashIntInt>(cheminRueZValeur);


    /**********************************************/
    /**********************************************/



    /**********************************************/
    /************* BORDURE ************************/
    /**********************************************/

    QHash<int,QPen> bordureRueCrayon;
    bordureRueCrayon[AUTOROUTE] = bordureRueCrayon[AUTOROUTE_BRETELLE] = QPen(Qt::black,AUTOROUTE_size);
    bordureRueCrayon[NATIONALE] = bordureRueCrayon[NATIONALE_BRETELLE] = QPen(Qt::black,NATIONALE_size);
    bordureRueCrayon[PRIMAIRE] = bordureRueCrayon[PRIMAIRE_BRETELLE] = QPen(Qt::black,PRIMAIRE_size);
    bordureRueCrayon[SECONDAIRE] = bordureRueCrayon[SECONDAIRE_BRETELLE] = QPen(Qt::black,SECONDAIRE_size);
    bordureRueCrayon[TERTIAIRE] = QPen(Qt::black,TERTIAIRE_size);
    bordureRueCrayon[NON_CLASSIFIE] = QPen(Qt::black,NON_CLASSIFIE_size);
    bordureRueCrayon[RESIDENTIEL] = QPen(Qt::black,RESIDENTIEL_size);
    bordureRueCrayon[RUE] = QPen(Qt::black,RUE_size);
    bordureRueCrayon[SERVICE] = QPen(Qt::black,SERVICE_size,Qt::DashLine);
    bordureRueCrayon[CYCLABLE] = QPen();
    bordureRueCrayon[PIED] = QPen(Qt::black,PIED_size,Qt::DashLine);
    defautsProprietes[CleBordureRueCrayon] = qVariantFromValue<QHashIntQPen>(bordureRueCrayon);

    QHash<int,qreal> bordureRueScaleMin;
    QHash<int,qreal> bordureRueScaleMax;
    bordureRueScaleMin[AUTOROUTE] = bordureRueScaleMin[AUTOROUTE_BRETELLE] = 0.;
    bordureRueScaleMin[NATIONALE] = bordureRueScaleMin[NATIONALE_BRETELLE] = 0.;
    bordureRueScaleMin[PRIMAIRE] = bordureRueScaleMin[PRIMAIRE_BRETELLE] = 0.;    
    bordureRueScaleMin[SECONDAIRE] = bordureRueScaleMin[SECONDAIRE_BRETELLE] = 0.;

    bordureRueScaleMax[AUTOROUTE] = bordureRueScaleMax[AUTOROUTE_BRETELLE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[NATIONALE] = bordureRueScaleMax[NATIONALE_BRETELLE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[PRIMAIRE] = bordureRueScaleMax[PRIMAIRE_BRETELLE] = numeric_limits<qreal>::max();    
    bordureRueScaleMax[SECONDAIRE] = bordureRueScaleMax[SECONDAIRE_BRETELLE] = numeric_limits<qreal>::max();

    bordureRueScaleMin[TERTIAIRE] = 2.5;
    bordureRueScaleMin[NON_CLASSIFIE] = 2.5;
    bordureRueScaleMin[RESIDENTIEL] = 2.5;

    bordureRueScaleMin[RUE] = 5.0;
    bordureRueScaleMin[SERVICE] = 5.0;
    bordureRueScaleMin[CYCLABLE] = 5.0;
    bordureRueScaleMin[PIED] = 5.0;

    bordureRueScaleMax[TERTIAIRE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[NON_CLASSIFIE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[RESIDENTIEL] = numeric_limits<qreal>::max();
    bordureRueScaleMax[RUE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[SERVICE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[CYCLABLE] = numeric_limits<qreal>::max();
    bordureRueScaleMax[PIED] = numeric_limits<qreal>::max();

    defautsProprietes[CleBordureRueScaleMin] = qVariantFromValue<QHashIntReal>(bordureRueScaleMin);
    defautsProprietes[CleBordureRueScaleMax] = qVariantFromValue<QHashIntReal>(bordureRueScaleMax);

    QHash<int,int> bordureRueZValeur;
    bordureRueZValeur[AUTOROUTE] = bordureRueZValeur[AUTOROUTE_BRETELLE] = 50-1;
    bordureRueZValeur[NATIONALE] = bordureRueZValeur[NATIONALE_BRETELLE] = 48-1;
    bordureRueZValeur[PRIMAIRE] = bordureRueZValeur[PRIMAIRE_BRETELLE] = 45-1;
    bordureRueZValeur[SECONDAIRE] = bordureRueZValeur[SECONDAIRE_BRETELLE] = 40-1;
    bordureRueZValeur[TERTIAIRE] = 35-1;
    bordureRueZValeur[NON_CLASSIFIE] = 32-1;
    bordureRueZValeur[RESIDENTIEL] = 30-1;
    bordureRueZValeur[RUE] = 25-1;
    bordureRueZValeur[SERVICE] = 20-1;
    bordureRueZValeur[CYCLABLE] = 10-1;
    bordureRueZValeur[PIED] = 8-1;
    defautsProprietes[CleBordureRueZValeur] = qVariantFromValue<QHashIntInt>(bordureRueZValeur);


    /**********************************************/
    /**********************************************/



    /**********************************************/
    /************* NOM ****************************/
    /**********************************************/


    QHash<int,QFont> nomRuePolice;
    nomRuePolice[AUTOROUTE] = nomRuePolice[AUTOROUTE_BRETELLE] = QFont(qApp->font().family(), 50.0);
    nomRuePolice[NATIONALE] = nomRuePolice[NATIONALE_BRETELLE] = QFont(qApp->font().family(), 45.0);
    nomRuePolice[PRIMAIRE] = nomRuePolice[PRIMAIRE_BRETELLE] = QFont(qApp->font().family(), 42.0);
    nomRuePolice[SECONDAIRE] = nomRuePolice[SECONDAIRE_BRETELLE] = QFont(qApp->font().family(), 40.0);
    nomRuePolice[TERTIAIRE] = QFont(qApp->font().family(), 38.0);
    nomRuePolice[NON_CLASSIFIE] = QFont(qApp->font().family(), 36.5);
    nomRuePolice[RESIDENTIEL] = QFont(qApp->font().family(), 35.0);
    nomRuePolice[RUE] = QFont(qApp->font().family(), 30.0);
    nomRuePolice[SERVICE] = QFont(qApp->font().family(), 30.0);
    nomRuePolice[CYCLABLE] = QFont();
    nomRuePolice[PIED] = QFont();
    defautsProprietes[CleNomRuePolice] = qVariantFromValue<QHashIntQFont>(nomRuePolice);

    QHash<int,QPen> nomRueCrayon;
    nomRueCrayon[AUTOROUTE] = nomRueCrayon[NATIONALE] = nomRueCrayon[PRIMAIRE] = nomRueCrayon[SECONDAIRE] = nomRueCrayon[TERTIAIRE] = nomRueCrayon[NON_CLASSIFIE] = nomRueCrayon[RESIDENTIEL] = nomRueCrayon[RUE] = nomRueCrayon[SERVICE] = QPen(Qt::black);
    nomRueCrayon[AUTOROUTE_BRETELLE] = nomRueCrayon[NATIONALE_BRETELLE] = nomRueCrayon[PRIMAIRE_BRETELLE] = nomRueCrayon[SECONDAIRE_BRETELLE] = QPen();
    nomRueCrayon[CYCLABLE] = QPen();
    nomRueCrayon[PIED] = QPen();
    defautsProprietes[CleNomRueCrayon] = qVariantFromValue<QHashIntQPen>(nomRueCrayon);

    QHash<int,qreal> nomRueScaleMin;
    QHash<int,qreal> nomRueScaleMax;
    nomRueScaleMin[AUTOROUTE] = nomRueScaleMin[NATIONALE] = nomRueScaleMin[PRIMAIRE] = nomRueScaleMin[SECONDAIRE] = 3.5;
    nomRueScaleMax[AUTOROUTE] = nomRueScaleMax[NATIONALE] = nomRueScaleMax[PRIMAIRE] = nomRueScaleMax[SECONDAIRE] = numeric_limits<qreal>::max();

    nomRueScaleMin[TERTIAIRE] = nomRueScaleMin[RESIDENTIEL] = nomRueScaleMin[RUE] = nomRueScaleMin[SERVICE] = 5.;
    nomRueScaleMax[TERTIAIRE] = nomRueScaleMax[RESIDENTIEL] = nomRueScaleMax[RUE] = nomRueScaleMax[SERVICE] = numeric_limits<qreal>::max();

    nomRueScaleMin[AUTOROUTE_BRETELLE] = nomRueScaleMin[NATIONALE_BRETELLE] = nomRueScaleMin[PRIMAIRE_BRETELLE] = nomRueScaleMin[SECONDAIRE_BRETELLE] = nomRueScaleMin[CYCLABLE] = nomRueScaleMin[NON_CLASSIFIE] = nomRueScaleMin[PIED] = -1.;
    nomRueScaleMax[AUTOROUTE_BRETELLE] = nomRueScaleMax[NATIONALE_BRETELLE] = nomRueScaleMax[PRIMAIRE_BRETELLE] = nomRueScaleMax[SECONDAIRE_BRETELLE] = nomRueScaleMax[CYCLABLE] = nomRueScaleMax[NON_CLASSIFIE] = nomRueScaleMax[PIED] = -1.;

    defautsProprietes[CleNomRueScaleMin] = qVariantFromValue<QHashIntReal>(nomRueScaleMin);
    defautsProprietes[CleNomRueScaleMax] = qVariantFromValue<QHashIntReal>(nomRueScaleMax);

    QHash<int,int> nomRueZValeur;
    nomRueZValeur[AUTOROUTE] = nomRueZValeur[AUTOROUTE_BRETELLE] = 100;
    nomRueZValeur[NATIONALE] = nomRueZValeur[NATIONALE_BRETELLE] = 100;
    nomRueZValeur[PRIMAIRE] = nomRueZValeur[PRIMAIRE_BRETELLE] = 100;
    nomRueZValeur[SECONDAIRE] = nomRueZValeur[SECONDAIRE_BRETELLE] = 100;
    nomRueZValeur[TERTIAIRE] = 100;
    nomRueZValeur[NON_CLASSIFIE] = 100;
    nomRueZValeur[RESIDENTIEL] = 100;
    nomRueZValeur[RUE] = 100;
    nomRueZValeur[SERVICE] = 100;
    nomRueZValeur[CYCLABLE] = 100;
    nomRueZValeur[PIED] = 100;
    defautsProprietes[CleNomRueZValeur] = qVariantFromValue<QHashIntInt>(nomRueZValeur);


    /**********************************************/
    /**********************************************/



    /**********************************************/
    /************* SENS ***************************/
    /**********************************************/



    QHash<int,QPen> sensRueCrayon;
    sensRueCrayon[AUTOROUTE] = sensRueCrayon[AUTOROUTE_BRETELLE] = QPen(Qt::blue,2.5);
    sensRueCrayon[NATIONALE] = sensRueCrayon[NATIONALE_BRETELLE] = QPen(Qt::blue,2.5);
    sensRueCrayon[PRIMAIRE] = sensRueCrayon[PRIMAIRE_BRETELLE] = QPen(Qt::blue,2.5);
    sensRueCrayon[SECONDAIRE] = sensRueCrayon[SECONDAIRE_BRETELLE] = QPen(Qt::blue,2.5);
    sensRueCrayon[TERTIAIRE] = QPen(Qt::blue,2.0);
    sensRueCrayon[NON_CLASSIFIE] = QPen(Qt::blue,2.0);
    sensRueCrayon[RESIDENTIEL] = QPen(Qt::blue,2.0);
    sensRueCrayon[RUE] = QPen(Qt::blue,2.0);
    sensRueCrayon[SERVICE] = QPen(Qt::blue,2.0);
    sensRueCrayon[CYCLABLE] = QPen();
    sensRueCrayon[PIED] = QPen();
    defautsProprietes[CleSensRueCrayon] = qVariantFromValue<QHashIntQPen>(sensRueCrayon);

    QHash<int,qreal> sensRueScaleMin;
    QHash<int,qreal> sensRueScaleMax;
    sensRueScaleMin[AUTOROUTE] = sensRueScaleMin[AUTOROUTE_BRETELLE] = 2.;
    sensRueScaleMin[NATIONALE] = sensRueScaleMin[NATIONALE_BRETELLE] = 2.;
    sensRueScaleMin[PRIMAIRE] = sensRueScaleMin[PRIMAIRE_BRETELLE] = 2.;
    sensRueScaleMin[SECONDAIRE] = sensRueScaleMin[SECONDAIRE_BRETELLE] = 2.;

    sensRueScaleMax[AUTOROUTE] = sensRueScaleMax[AUTOROUTE_BRETELLE] = numeric_limits<qreal>::max();
    sensRueScaleMax[NATIONALE] = sensRueScaleMax[NATIONALE_BRETELLE] = numeric_limits<qreal>::max();
    sensRueScaleMax[PRIMAIRE] = sensRueScaleMax[PRIMAIRE_BRETELLE] = numeric_limits<qreal>::max();
    sensRueScaleMax[SECONDAIRE] = sensRueScaleMax[SECONDAIRE_BRETELLE] = numeric_limits<qreal>::max();

    sensRueScaleMin[TERTIAIRE] = 5.;
    sensRueScaleMin[NON_CLASSIFIE] = 5.;
    sensRueScaleMin[RESIDENTIEL] = 5.;
    sensRueScaleMin[RUE] = 5.;
    sensRueScaleMin[SERVICE] = 5.;

    sensRueScaleMax[TERTIAIRE] = numeric_limits<qreal>::max();
    sensRueScaleMax[NON_CLASSIFIE] = numeric_limits<qreal>::max();
    sensRueScaleMax[RESIDENTIEL] = numeric_limits<qreal>::max();
    sensRueScaleMax[RUE] = numeric_limits<qreal>::max();
    sensRueScaleMax[SERVICE] = numeric_limits<qreal>::max();

    sensRueScaleMin[CYCLABLE] = -1;
    sensRueScaleMin[PIED] = -1;

    sensRueScaleMax[CYCLABLE] = -1;
    sensRueScaleMax[PIED] = -1;

    defautsProprietes[CleSensRueScaleMin] = qVariantFromValue<QHashIntReal>(sensRueScaleMin);
    defautsProprietes[CleSensRueScaleMax] = qVariantFromValue<QHashIntReal>(sensRueScaleMax);

    QHash<int,int> sensRueZValeur;
    sensRueZValeur[AUTOROUTE] = sensRueZValeur[AUTOROUTE_BRETELLE] = 50+2;
    sensRueZValeur[NATIONALE] = sensRueZValeur[NATIONALE_BRETELLE] = 48+2;
    sensRueZValeur[PRIMAIRE] = sensRueZValeur[PRIMAIRE_BRETELLE] = 45+2;
    sensRueZValeur[SECONDAIRE] = sensRueZValeur[SECONDAIRE_BRETELLE] = 40+2;
    sensRueZValeur[TERTIAIRE] = 35+2;
    sensRueZValeur[NON_CLASSIFIE] = 32+2;
    sensRueZValeur[RESIDENTIEL] = 30+2;
    sensRueZValeur[RUE] = 25+2;
    sensRueZValeur[SERVICE] = 20+2;
    sensRueZValeur[CYCLABLE] = 10+2;
    sensRueZValeur[PIED] = 10+2;
    defautsProprietes[CleSensRueZValeur] = qVariantFromValue<QHashIntInt>(sensRueZValeur);


    _init = true;
}

/// liste des types de rue supportés, c'est-à-dire qui peuvent être affichés
const QStringList RueElement::typesSupportes = QStringList() <<
                 "motorway"<< "motorway_link"<< "trunk"<< "trunk_link"<< "primary"<< "primary_link"<<
                 "secondary"<< "secondary_link"<< "tertiary"<< "unclassified"<<
                 "-road"<< "residential" << "living_street" << "-track"<< "-pedestrian"<<
                 "-raceway"<< "service" << "cycleway"<< "footway"<< "-steps";


RueElement::RueElement(const QList<QPointF> &noeuds, int id, QString nom, QString type) :
    _id(id), _nom(nom)
{
    if (!_init) init();

    _type = NON_SUPPORTE;
    for (int i=0; i<typesSupportes.size(); ++i) {
        if (type == typesSupportes[i]) {
            _type = RueType(i);
            break;
        }
    }

    if (_type == NON_SUPPORTE) {
        //qDebug() << "type non supporte : " << type;
        return;
    }

    int size = noeuds.size();
    moveTo(noeuds[0]);
    for (int i=1; i<size; ++i) {
        lineTo(noeuds[i]);
    }
}

CheminRueElement::CheminRueElement(RueElement rel,  QGraphicsItem *parent) :
    QGraphicsPathItem(parent),
    _rel(rel)
{
    setPath(rel);
    setAcceptHoverEvents(true);
}

void CheminRueElement::changeProprietes(const QHash<int, QVariant> &props, qreal scale)
{
    QPen pen;
    extraitDonnees(props, _rel, RueElement::CleCheminRueCrayon, &pen);
    pen.setCapStyle(Qt::RoundCap);
    setPen(pen);

    int zval;
    extraitDonnees(props, _rel, RueElement::CleCheminRueZValeur, &zval);
    setZValue(zval);

    qreal scaleMin, scaleMax;
    extraitDonnees(props, _rel, RueElement::CleCheminRueScaleMin, &scaleMin);
    extraitDonnees(props, _rel, RueElement::CleCheminRueScaleMax, &scaleMax);
    setVisible(scale>=scaleMin && scale<=scaleMax);
}

void CheminRueElement::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    emit sourisDessus();
}

void CheminRueElement::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    emit sourisDehors();
}

BordureRueElement::BordureRueElement(RueElement rel,  QGraphicsItem *parent) :
    QGraphicsPathItem(parent),
    _rel(rel)
{
    setPath(rel);
}

void BordureRueElement::changeProprietes(const QHash<int, QVariant> &props, qreal scale)
{
    QPen pen;
    extraitDonnees(props, _rel, RueElement::CleBordureRueCrayon, &pen);
    pen.setCapStyle(Qt::RoundCap);
    setPen(pen);

    int zval;
    extraitDonnees(props, _rel, RueElement::CleBordureRueZValeur, &zval);
    setZValue(zval);

    qreal scaleMin, scaleMax;
    extraitDonnees(props, _rel, RueElement::CleBordureRueScaleMin, &scaleMin);
    extraitDonnees(props, _rel, RueElement::CleBordureRueScaleMax, &scaleMax);
    setVisible(scale>=scaleMin && scale<=scaleMax);
}

void NomRueElement::creerTexte()
{
    QString nom = _rel.nom();
    QFontMetricsF fm(_police);
    qreal w = fm.boundingRect(nom).width();

    qreal r = w/qreal(_rel.boundingRect().width());
    if (r < 1) {
        //pour une raison quelconque somme(width(char)) != width(string)...
        qreal width = 0;
        int len = nom.length();
        for (int i=0; i<len; ++i)
            width += fm.width(nom.at(i));

        qreal d = (_rel.length()-width)/2.;
        for (int i=0; i<len; ++i) {
            qreal t = _rel.percentAtLength(d);
            QPointF pt = _rel.pointAtPercent(t);
            qreal angle = _rel.angleAtPercent(t);
            QString txt = nom.at(i);
            QGraphicsSimpleTextItem *it = new QGraphicsSimpleTextItem(txt);
            it->setFont(_police);
            it->setPos(pt);
            it->setRotation(it->rotation()-angle);
            it->setPen(_crayon);
            addToGroup(it);

            d += fm.width(txt);
        }
    }
}

NomRueElement::NomRueElement(RueElement rel, QGraphicsItem *parent) :
    QGraphicsItemGroup(parent),
    _rel(rel)
{
    //rien a faire ici, il nous faut les proprietes d'abord
    //ou alors on utilise des valeurs par defaut ...
}

void NomRueElement::changeProprietes(const QHash<int, QVariant> &props, qreal scale)
{
    QPen pen;
    extraitDonnees(props, _rel, RueElement::CleNomRueCrayon, &pen);
    pen.setCapStyle(Qt::RoundCap);
    _crayon = pen;

    QPen bpen;
    extraitDonnees(props, _rel, RueElement::CleBordureRueCrayon, &pen);
    bpen.setCapStyle(Qt::RoundCap);
    _bordureCrayon = bpen;

    QFont font;
    extraitDonnees(props, _rel, RueElement::CleNomRuePolice, &font);
    _police = font;

    int zval;
    extraitDonnees(props, _rel, RueElement::CleNomRueZValeur, &zval);
    setZValue(zval);

    if (childItems().count()==0)
        creerTexte();

    qreal scaleMin, scaleMax;
    extraitDonnees(props, _rel, RueElement::CleNomRueScaleMin, &scaleMin);
    extraitDonnees(props, _rel, RueElement::CleNomRueScaleMax, &scaleMax);
    setVisible(scale>=scaleMin && scale<=scaleMax);
}

SensRueElement::SensRueElement(RueElement rel, int sens, QGraphicsItem *parent) :
    QGraphicsItemGroup(parent),
    _rel(rel), _sens(sens)
{
    qreal h = 8.0;
    qreal w = 16.0;
    //fleche
    QPainterPath fleche;
    fleche.moveTo(0,0);
    fleche.lineTo(w,0);
    fleche.moveTo(0.8*w,-h/2);
    fleche.lineTo(w,0);
    fleche.moveTo(0.8*w,h/2);
    fleche.lineTo(w,0);

    qreal tw = _rel.length();
    //combien ?
    qreal s = 0.;
    int n = 0;
    for (; s+32*w<tw; s+=32*w, ++n);

    qreal pas = (tw-n*w)/(n+1);
    qreal d = pas;

    for (int i=0; i<n; ++i) {
        qreal t = _rel.percentAtLength(d);
        QPointF pt = _rel.pointAtPercent(t);
        qreal angle = _rel.angleAtPercent(t);
        QGraphicsPathItem *it = new QGraphicsPathItem(fleche);
        it->setPos(pt);
        if (sens == -1)
            it->setRotation(it->rotation()+180-angle);
        else
            it->setRotation(it->rotation()-angle);
        it->setPen(QPen(Qt::black,1.0));
        addToGroup(it);
        if (sens == 1) {
            it = new QGraphicsPathItem(fleche);
            it->setPos(pt);
            it->setRotation(it->rotation()+180-angle);
            it->setPen(QPen(Qt::black,1.0));
            addToGroup(it);
        }

        d += (pas+w);
    }
}

void SensRueElement::changeProprietes(const QHash<int, QVariant> &props, qreal scale)
{

    QPen pen;
    extraitDonnees(props, _rel, RueElement::CleSensRueCrayon, &pen);
    pen.setCapStyle(Qt::RoundCap);
    foreach (QGraphicsItem *item, childItems()) {
        QGraphicsPathItem *pitem = qgraphicsitem_cast<QGraphicsPathItem*>(item);
        if (pitem) pitem->setPen(pen);
    }

    int zval;
    extraitDonnees(props, _rel, RueElement::CleSensRueZValeur, &zval);
    setZValue(zval);

    qreal scaleMin, scaleMax;
    extraitDonnees(props, _rel, RueElement::CleSensRueScaleMin, &scaleMin);
    extraitDonnees(props, _rel, RueElement::CleSensRueScaleMax, &scaleMax);
    setVisible(scale>=scaleMin && scale<=scaleMax);
}
