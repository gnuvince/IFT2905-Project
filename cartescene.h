/*
 * cartescene.h
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

#ifndef CARTESCENE_H
#define CARTESCENE_H

#include "carteelements.h"
#include "geoposition.h"
#include <QGraphicsScene>
#include <QtCore/QXmlStreamReader>


class CarteScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CarteScene(QObject *parent = 0);
    void changeProprietes(const QHash<int,QVariant> &proprietes);
    void ajouteNoeud(QPointF pos, int id);
    void ajouteChemin(const QList<QPointF> &noeuds, int id, QString nom, QString type, int sens);
    RueElement rue(int id) const;

    QRectF bounds() const { return _bounds; }
    void setBounds(const QRectF &bounds) { _bounds = bounds; }

    static CarteScene* readSceneFile(const QString& file);
    static QPointF GPSToPoint(qreal lat, qreal lon);
    static GeoPosition PointToGPS(const QPointF &point);


private:
    static void readNode(QXmlStreamReader &rd, qreal &lat, qreal &lon, int &id);
    static void readBounds(QXmlStreamReader &rd, double &minlat, double &minlon, double &maxlat, double &maxlon);
    static void readPath(QXmlStreamReader &rd, QList<int> &ids, int &id, QString &nom, QString &type, int &sens, bool &visible);


public slots:
    void changeSourisSurRue();
    void changeSourisDehorsRue();
    void scale(qreal scale);
    void setScale(qreal scale);

private:
    QHash<int,RueElement> _rues;
    qreal _scale;
    QRectF _bounds;
};

#endif // CARTESCENE_H
