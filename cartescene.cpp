/*
 * cartescene.cpp
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


#include "cartescene.h"
#include <QtGui>

CarteScene::CarteScene(QObject *parent) :
    QGraphicsScene(parent),
    _scale(1.0)
{
}


const qreal CIRCONFERENCEEQUATEURMETRE = 40075016.68; /**< Circonférence de la Terre à l'équateur en mètre */
const qreal DEMICIRCONFERENCEEQUATEURMETRE = 20037508.34; /**< Demi-circonférence de la Terre à l'équateur en mètre */

template<class T> T smod(T a, T b) {
    return a - b*floor(a/b);
}

qreal radians(qreal degres) {
    qreal v = smod(degres,360.);
    return (v/180.)*M_PI;
}

qreal degrees(qreal radians) {
   return radians*180/M_PI;
}

QPointF CarteScene::GPSToPoint(qreal lat, qreal lon)
{
    qreal x, y;
    qreal rad = radians(lat);
    x = lon / 180. * DEMICIRCONFERENCEEQUATEURMETRE;
    y = CIRCONFERENCEEQUATEURMETRE - (log(tan(rad) + 1/cos(rad)) / M_PI * (DEMICIRCONFERENCEEQUATEURMETRE));

    return QPointF(x,y);
}

GeoPosition CarteScene::PointToGPS(const QPointF &point)
{
    qreal lat, lon;
    lon = point.x()*180 / DEMICIRCONFERENCEEQUATEURMETRE;
    lat = degrees(atan(sinh( (CIRCONFERENCEEQUATEURMETRE-point.y())/DEMICIRCONFERENCEEQUATEURMETRE * M_PI )));
    return GeoPosition(lat,lon);
}


void CarteScene::changeProprietes(const QHash<int,QVariant> &proprietes)
{
    foreach (QGraphicsItem *item, items()) {
        CarteElement *cel = dynamic_cast<CarteElement*>(item);
        if (cel) cel->changeProprietes(proprietes, _scale);
    }
}

void CarteScene::ajouteChemin(const QList<QPointF> &noeuds, int id, QString nom, QString type, int sens)
{
    RueElement rel(noeuds, id, nom, type);
    _rues[id] = rel;

    CheminRueElement *crel = new CheminRueElement(rel);
    addItem(crel);
    BordureRueElement *brel = new BordureRueElement(rel);
    addItem(brel);

    //si vous voulez accélérer le temps de chargement de la carte commentez les deux lignes suivantes :
    NomRueElement *nrel = new NomRueElement(rel);
    addItem(nrel);

    SensRueElement *srel = new SensRueElement(rel, sens);
    addItem(srel);

    connect(crel, SIGNAL(sourisDessus()), this, SLOT(changeSourisSurRue()));
    connect(crel, SIGNAL(sourisDehors()), this, SLOT(changeSourisDehorsRue()));
}

void CarteScene::ajouteNoeud(QPointF, int)
{
}

void CarteScene::changeSourisSurRue()
{
    //CheminRueElement *el = qobject_cast<CheminRueElement*>(sender());
    //par exemple, vous pouvez émettre un signal avec le nom de la rue ...
    //emit sourisSurRue(el->rueElement().nom());
}

void CarteScene::scale(qreal scale)
{
    _scale *= scale;
    changeProprietes(RueElement::defautsProprietes);
}

void CarteScene::setScale(qreal scale)
{
    _scale = scale;
    changeProprietes(RueElement::defautsProprietes);
}

void CarteScene::changeSourisDehorsRue()
{
    //par exemple, vous pouvez émettre un signal avec une chaîne vide
    //emit sourisSurRue("");
}

RueElement CarteScene::rue(int id) const
{
    return _rues[id];
}


CarteScene* CarteScene::readSceneFile(const QString &file)
{
    QFile f(file);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << QString(trUtf8("Erreur: Impossible de lire le fichier %1 : %2")).arg(file,f.errorString());
        return 0;
    }

    QXmlStreamReader rd;
    rd.setDevice(&f);

    if (rd.readNextStartElement()) {
        if (rd.name() != "osm") {
            f.close();
            return 0;
        }
    }

    QHash<int,QPointF> nodes;
    CarteScene *scene = new CarteScene;

    while (rd.readNextStartElement()) {
        if (rd.name() == "node") {
            qreal lat, lon;
            int id;
            readNode(rd, lat, lon, id);

            //scene->ajouteNoeud(GPSToPoint(lat,lon),id);
            nodes[id] = GPSToPoint(lat,lon);
        } else if (rd.name() == "way") {
            QList<int> ids;
            int id, sens;
            QString nom, type;
            bool visible;
            readPath(rd, ids, id, nom, type, sens, visible);

            if (visible) {
                QList<QPointF> ns;
                foreach (int i, ids)
                    ns.append(nodes[i]);
                scene->ajouteChemin(ns, id, nom, type, sens);
            }
        } else if (rd.name() == "bounds") {
            double minlat, minlon, maxlat, maxlon;
            readBounds(rd, minlat, minlon, maxlat, maxlon);

            scene->setBounds(QRectF(GPSToPoint(maxlat,minlon),GPSToPoint(minlat,maxlon)));
        } else {
            rd.skipCurrentElement();
        }
    }

    if (rd.hasError()) {
        qDebug() << QString(trUtf8("Erreur: Impossible d'anlyser le fichier %1 : %2")).arg(file,rd.errorString()); {
            f.close();
            delete scene;
            return 0;
        }
    } else if (f.error() != QFile::NoError) {
        qDebug() << QString(trUtf8("Erreur: Impossible de lire le fichier %1 : %2")).arg(file,f.errorString()); {
            f.close();
            delete scene;
            return 0;
        }
    }
    f.close();

    QHash<int,QVariant> props = RueElement::defautsProprietes;
    scene->changeProprietes(props);

    return scene;
}


void CarteScene::readNode(QXmlStreamReader &rd, qreal &lat, qreal &lon, int &id)
{
    if (!rd.attributes().hasAttribute("visible") || rd.attributes().value("visible").toString()=="true") {
        id = rd.attributes().value("id").toString().toInt();
        lat = rd.attributes().value("lat").toString().toDouble();
        lon = rd.attributes().value("lon").toString().toDouble();
    }
    rd.skipCurrentElement();
}

void CarteScene::readBounds(QXmlStreamReader &rd, double &minlat, double &minlon, double &maxlat, double &maxlon)
{
    minlat = rd.attributes().value("minlat").toString().toDouble();
    maxlat = rd.attributes().value("maxlat").toString().toDouble();
    minlon = rd.attributes().value("minlon").toString().toDouble();
    maxlon = rd.attributes().value("maxlon").toString().toDouble();
    rd.skipCurrentElement();
}

void CarteScene::readPath(QXmlStreamReader &rd, QList<int> &ids, int &id, QString &name, QString &type, int &sens, bool &visible)
{
    sens = 1;//-1 reverse, 0 one way bon sens, 1 two way
    visible = (!rd.attributes().hasAttribute("visible") || rd.attributes().value("visible").toString()=="true");
    id = rd.attributes().value("id").toString().toInt();

    while (rd.readNextStartElement()) {
        if (rd.name() == "nd") {
            int i = rd.attributes().value("ref").toString().toInt();
            ids.append(i);
            rd.skipCurrentElement();
        } else if (rd.name() == "tag") {
            QString key = rd.attributes().value("k").toString();
            if (key == "highway") {
                type = rd.attributes().value("v").toString();
            } else if (key == "name") {
                name = rd.attributes().value("v").toString();
            } else if (key == "oneway") {
                QString rep = rd.attributes().value("v").toString();
                bool ok;
                sens = rep.toInt(&ok);
                if (!ok) {
                    if (rep == "yes" || rep == "true") sens = 0;
                    else if (rep == "no" || rep == "false") sens = 1;
                }
            }
            rd.skipCurrentElement();
        } else {
            rd.skipCurrentElement();
        }
    }
}

