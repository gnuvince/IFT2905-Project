/*
 * cartewidget.h
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

#ifndef CARTEWIDGET_H
#define CARTEWIDGET_H

#include <QWidget>
#include <QRectF>
#include <QString>
#include "geoposition.h"

namespace Ui {
    class CarteWidget;
}

class CarteScene;
class QGraphicsEllipseItem;

class CarteWidget : public QWidget
{
        Q_OBJECT

        public:
        explicit CarteWidget(QWidget *parent = 0);
        ~CarteWidget();

        GeoPosition getFlagPosition() { return _flagPos; }
        void setFlagPosition(const GeoPosition &pos) { _flagPos = pos; }
    public slots:
        void zoomin();
        void zoomout();
        void center();
        void setScale(int v);

        static void setScene(CarteScene *scene) { gscene = scene; }

    private:
        static CarteScene* gscene;

    signals:
        void editFinished();

    protected:
        void showEvent(QShowEvent *);
        bool eventFilter(QObject *, QEvent *);

    private:
        Ui::CarteWidget *ui;
        GeoPosition _flagPos;
        QGraphicsEllipseItem *flag;
        qreal defscale;
};

#endif // CARTEWIDGET_H
