/*
 * cartewidget.cpp
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
#include "cartewidget.h"
#include "ui_cartewidget.h"
#include <QtGui>
#include <cmath>

CarteScene* CarteWidget::gscene;

CarteWidget::CarteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarteWidget)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    setFocusPolicy(Qt::StrongFocus);

    if (!gscene) {
        qDebug() << trUtf8("CarteWidget::setScene() n'a pas été appelé ou n'a pas bien fonctionné! Vous devez appeler CarteScene::readSceneFile(<chemin du fichier.osm>) puis CarteWidget::setScene() avant d'utiliser CarteWidget");
    }

    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(zoomin()));
    connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(zoomout()));
    connect(ui->toolButton_3, SIGNAL(clicked()), this, SLOT(center()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setScale(int)));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    ui->graphicsView->setScene(gscene);
    ui->graphicsView->viewport()->installEventFilter(this);

    flag = new QGraphicsEllipseItem;
    flag->setRect(0,0,30,30);
    flag->setPen(QPen(Qt::red));
    flag->setVisible(false);
    gscene->addItem(flag);
}

bool CarteWidget::eventFilter(QObject *, QEvent *ev)
{
    if (ev->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *mev = static_cast<QMouseEvent*>(ev);
        if (mev->button() == Qt::RightButton) {
            QPointF pos = ui->graphicsView->mapToScene(mev->pos());
            flag->setPos(pos);
            flag->setVisible(true);
            _flagPos = CarteScene::PointToGPS(pos);
            //pour etre propre on devrait emettre le signal mais bon ...
            //emit editFinished();
        }
    }
    return false;
}

CarteWidget::~CarteWidget()
{
    delete ui;
    if (flag) delete flag;
}

void CarteWidget::setScale(int v)
{
    qreal scale = ui->graphicsView->transform().m11();
    switch (v)
    {
    case 0:
        gscene->setScale(0.5);
        ui->graphicsView->scale(defscale/(2*scale),defscale/(2*scale));
        break;
    case 1:
        gscene->setScale(1.);
        ui->graphicsView->fitInView(gscene->bounds(),Qt::KeepAspectRatio);
        break;
    case 2:
        gscene->setScale(2.);
        ui->graphicsView->scale(defscale/(0.5*scale),defscale/(0.5*scale));
        break;
    case 3:
        gscene->setScale(4.);
        ui->graphicsView->scale(defscale/(0.25*scale),defscale/(0.25*scale));
        break;
    case 4:
        gscene->setScale(8.);
        ui->graphicsView->scale(defscale/(0.125*scale),defscale/(0.125*scale));
        break;
    }
}

void CarteWidget::zoomin()
{
    gscene->scale(1.25);
    ui->graphicsView->scale(1.25,1.25);
}

void CarteWidget::zoomout()
{
    gscene->scale(0.8);
    ui->graphicsView->scale(0.8,0.8);
}

void CarteWidget::center()
{
    gscene->setScale(1.);
    ui->graphicsView->fitInView(gscene->bounds(),Qt::KeepAspectRatio);
    defscale = ui->graphicsView->transform().m11();
}

void CarteWidget::showEvent(QShowEvent *)
{
    center();
}
