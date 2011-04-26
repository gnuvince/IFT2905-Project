/*
 * mainwindow.cpp
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stationmodel.h"
#include "vehiculemodel.h"
#include "reservationmodel.h"
#include "usagermodel.h"
#include "notemodel.h"
#include "reservationproxymodel.h"
#include "manote.h"
#include "geopositiondelegate.h"
#include "simulateur.h"
#include "robot.h"

#include "cartewidget.h"
#include "cartescene.h"

#include "userinterface.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString abs_path;

    //important : ne changer pas ceci ... permet de ne pas gosser avec les paths
    //sur Linux, Windows et Mac ...
#ifndef PATH
    qDebug() << trUtf8("Vous ne devez pas exécuter qmake -project, car vous allez écraser le fichier de projet fourni. Remplacez votre fichier .pro par celui fourni et recompilez.");
    exit(-1);
#else
    abs_path = QString(PATH);
#endif

    qDebug() << trUtf8("Chargement des stations");
    smodel = new StationModel(this);
    if (!smodel->setStations(QString("%1/data/xml/stations.xml").arg(abs_path),QString("%1/data/images/stations/").arg(abs_path))) {
        qDebug() << "Probleme de path :( Le path est " << abs_path;
        exit(-1);
    }

    qDebug() << trUtf8("Chargement des véhicules");
    vmodel = new VehiculeModel(this);
    if (!vmodel->setVehicules(QString("%1/data/xml/vehicules.xml").arg(abs_path),QString("%1/data/images/vehicules/").arg(abs_path))) {
        qDebug() << "Probleme de path :( Le path est " << abs_path;
        exit(-1);
    }

    simul = new Simulateur(this);

    rmodel = new ReservationModel(this);

    umodel = new UsagerModel(this);

    nmodel = new NoteModel(this);

    /// quelques notes pour rire...
    nmodel->addNote(new Note(0,QDateTime::currentDateTime(),Note::TYPE_USAGER,1,trUtf8("Salut, comment ca va?"),this));
    nmodel->addNote(new Note(1,QDateTime::currentDateTime().addSecs(60),Note::TYPE_USAGER,0,trUtf8("Pas mal, et toi?"),this));
    nmodel->addNote(new Note(0,QDateTime::currentDateTime(),Note::TYPE_VEHICULE,1187,trUtf8("Pneu dégonflé!"),this));


    //gestion du GUI
    ui->debutTEdit->setDateTime(simul->getCurrentDateAndTime());
    ui->finTEdit->setDateTime(simul->getCurrentDateAndTime());
    connect(ui->dMtntBut, SIGNAL(clicked()), this, SLOT(updateDebutTimeEdit()));
    connect(ui->eMtntBut, SIGNAL(clicked()), this, SLOT(updateFinTimeEdit()));

    connect(simul, SIGNAL(currentDateAndTime(QDateTime)), this, SLOT(updateTime(QDateTime)));

    QStringList slabels = Simulateur::labels();
    for (int s = Simulateur::ARRETE; s <= Simulateur::S_JOUR; ++s)
        ui->scaleBox->addItem(slabels[s]);

    connect(ui->applyBut, SIGNAL(clicked()), this, SLOT(applyFilter()));
    connect(ui->scaleBox, SIGNAL(currentIndexChanged(int)), simul, SLOT(setScale(int)));

    ui->usagerBox->setModel(umodel);
    ui->usagerBox->setModelColumn(Usager::COL_NOM);

    connect(ui->usagerBut, SIGNAL(clicked()), this, SLOT(changeInterfaceUsager()));

    connect(this, SIGNAL(interfaceUsagerId(qint64)), this, SLOT(changeInterfaceUsagerId(qint64)));

    //
    // on demarre un robot pour faire bouger les choses...
    //
    robot = new Robot(rmodel,vmodel,smodel,umodel,nmodel,this);
    // connecte le robot a l'horloge pour simuler...
    connect(simul, SIGNAL(currentDateAndTime(QDateTime)), robot, SLOT(updateTime(QDateTime)));

    robot->updateTime(QDateTime::currentDateTime());

    qDebug() << trUtf8("Mise à jour du filtre");
    //proxy pour filtrer les réservations
    rproxy = new ReservationProxyModel(this);
    rproxy->setSourceModel(rmodel);
    rproxy->setDynamicSortFilter(true);

    applyFilter();

    //change la taille des colonnes dans la table
    setupTables();

    connect(ui->action_Enregistrer, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->action_Ouvrir, SIGNAL(triggered()), this, SLOT(open()));


    qDebug() << trUtf8("Lecture de la carte");
    //crée une carte de Montréal pour utilisation dans le GUI
    CarteScene *scene = CarteScene::readSceneFile(QString("%1/data/xml/map_montreal.osm").arg(abs_path));
    if (!scene) {
        qDebug() << "Probleme de path :( Le path est " << abs_path;
        exit(-1);
    }
    scene->setParent(this);

    //rajoute les stations au GUI
    foreach (Station *s, smodel->getStations()) {
        QGraphicsRectItem *sItem = new QGraphicsRectItem;
        sItem->setPen(QPen(Qt::black));
        sItem->setBrush(QBrush(Qt::blue));
        sItem->setRect(0,0,200,200);
        sItem->setPos(CarteScene::GPSToPoint(s->getPosition().getLat(),s->getPosition().getLon()));
        sItem->setZValue(200);
        scene->addItem(sItem);
        //vous pourriez aussi ajouter des connections pour si la souris passe dessus ..
        //vous pouvez jetter un coup d'oeil au fichier carteelements et particulièrement
        //à l'objet CheminRueElement et l'événement hoverEnterEvent
    }

    //important tout le monde partage la scène !
    CarteWidget::setScene(scene);

    UserInterface *userInterface = new UserInterface(smodel, vmodel, umodel, rmodel, this);
    connect(this, SIGNAL(interfaceUsagerId(qint64)), userInterface, SLOT(setUser(qint64)));
    userInterface->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    QFile f("test.res");
    if (!f.open(QIODevice::WriteOnly)) {
        qDebug() << trUtf8("Impossible d'ouvrir test.res : %1.").arg(f.errorString());
        return;
    }

    QDataStream ds(&f);
    ds.setVersion(QDataStream::Qt_4_7);
    ds << ReservationModel::MAGIC_NUMBER;

    QApplication::setOverrideCursor(Qt::WaitCursor);
    qDebug() << "Faites la sérialisation de tout ce qui est nécessaire ici\n";
    ds << (*rmodel);
    qDebug() << "rmodel done\n";
    ds << (*umodel);
    qDebug() << "umodel done\n";
    ds << (*vmodel);
    qDebug() << "vmodel done\n";
    ds << (*smodel);
    qDebug() << "smodel done\n";
    ds << (*nmodel);
    qDebug() << "nmodel done\n";
    QApplication::restoreOverrideCursor();
}

void MainWindow::open()
{
    QFile f("test.res");
    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << trUtf8("Impossible d'ouvrir test.res : %1.").arg(f.errorString());
        return;
    }

    QDataStream ds(&f);
    ds.setVersion(QDataStream::Qt_4_7);
    quint32 mn;
    ds >> mn;

    if (mn != ReservationModel::MAGIC_NUMBER) {
        qDebug() << trUtf8("Le fichier test.res ne semble pas être un fichier de réservations");
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    qDebug() << "Faites la désérialisation de tout ce qui est nécessaire ici\n";
    ds >> (*rmodel);
    qDebug() << "rmodel done\n";
    ds >> (*umodel);
    qDebug() << "umodel done\n";
    ds >> (*vmodel);
    qDebug() << "vmodel done\n";
    ds >> (*smodel);
    qDebug() << "smodel done\n";
    ds >> (*nmodel);
    qDebug() << "nmodel done\n";
    QApplication::restoreOverrideCursor();
}


void MainWindow::updateTime(const QDateTime &date)
{
    ui->labelHeure->setText(date.toString("dd MMM hh:mm:ss"));
}


void MainWindow::applyFilter()
{
    ReservationProxyModel::Options opts = 0;

    if (ui->actifBox->isChecked())
        opts |= ReservationProxyModel::Actif;
    if (ui->passeBox->isChecked())
        opts |= ReservationProxyModel::Passe;
    if (ui->futurBox->isChecked())
        opts |= ReservationProxyModel::Futur;
    if (ui->inverseBox->isChecked())
        opts |= ReservationProxyModel::InverseInterval;
    if (ui->procheBox->isChecked())
        opts |= ReservationProxyModel::PlusProche;
    if (ui->sInverseBox->isChecked())
        opts |= ReservationProxyModel::InverseStation;
    if (ui->vInverseBox->isChecked())
        opts |= ReservationProxyModel::InverseVehicule;

    QDateTime debut, fin;
    if (!ui->ignoreBox->isChecked()) {
        debut = ui->debutTEdit->dateTime();
        fin = ui->finTEdit->dateTime();
    }

    qint64 vehicule = ui->vEdit->text().toLongLong();
    qint64 station = ui->sEdit->text().toLongLong();

    rproxy->setFilterFields(debut, fin, vehicule, station, opts);
}

void MainWindow::updateDebutTimeEdit()
{
    ui->debutTEdit->setDateTime(simul->getCurrentDateAndTime());
}

void MainWindow::updateFinTimeEdit()
{
    ui->finTEdit->setDateTime(simul->getCurrentDateAndTime());
}

void MainWindow::changeInterfaceUsager()
{
    int row = ui->usagerBox->currentIndex();
    QModelIndex index = umodel->index(row, Usager::COL_ID);
    if (!index.isValid()) return;
    qint64 id = umodel->data(index).toLongLong();
    emit interfaceUsagerId(id);
}

void MainWindow::changeInterfaceUsagerId(qint64 id)
{
    Usager *u = umodel->getUsager(id);
    if (!u) {
        //normalement u est valide mais bon ..
        QMessageBox::warning(this, trUtf8("Usager invalide"), trUtf8("L'usager que vous avez sélectionné n'existe pas"),QMessageBox::Ok);
    }
}

void MainWindow::setupTables()
{
    QFontMetrics fm = fontMetrics();
    QLocale locale;

    ui->tableView->setModel(smodel);
    ui->tableView->setItemDelegateForColumn(Station::COL_POS,new GeoPositionDelegate(this));
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setDefaultSectionSize(150);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(100);

    ui->tableView->setColumnWidth(Station::COL_ID,60);
    ui->tableView->setColumnWidth(Station::COL_DESCR,200);
    ui->tableView->setColumnWidth(Station::COL_POS,fm.width(QString("(+99.999,+99.999")));
    ui->tableView->setColumnWidth(Station::COL_COFF,200);
    ui->tableView->setColumnWidth(Station::COL_CARTE,150);
    ui->tableView->setColumnWidth(Station::COL_PHOTO,150);


    ui->tableView_2->setModel(vmodel);
    ui->tableView_2->verticalHeader()->hide();
    ui->tableView_2->verticalHeader()->setDefaultSectionSize(150);
    ui->tableView_2->horizontalHeader()->setDefaultSectionSize(100);

    ui->tableView_2->setColumnWidth(Vehicule::COL_ID,60);
    ui->tableView_2->setColumnWidth(Vehicule::COL_DESCRIPTION,200);
    ui->tableView_2->setColumnWidth(Vehicule::COL_PHOTO,250);


    ui->tableView_3->setModel(rmodel);
    ui->tableView_3->verticalHeader()->hide();
    ui->tableView_3->verticalHeader()->setDefaultSectionSize(30);
    ui->tableView_3->horizontalHeader()->setDefaultSectionSize(60);

    ui->tableView_3->setColumnWidth(Reservation::COL_DEBUT,fm.width(locale.toString(QDateTime::currentDateTime(),QLocale::ShortFormat))+20);
    ui->tableView_3->setColumnWidth(Reservation::COL_FIN,fm.width(locale.toString(QDateTime::currentDateTime(),QLocale::ShortFormat))+20);


    ui->tableView_4->setModel(rproxy);
    ui->tableView_4->verticalHeader()->hide();
    ui->tableView_4->verticalHeader()->setDefaultSectionSize(30);
    ui->tableView_4->horizontalHeader()->setDefaultSectionSize(60);

    ui->tableView_4->setColumnWidth(Reservation::COL_DEBUT,fm.width(locale.toString(QDateTime::currentDateTime(),QLocale::ShortFormat))+20);
    ui->tableView_4->setColumnWidth(Reservation::COL_FIN,fm.width(locale.toString(QDateTime::currentDateTime(),QLocale::ShortFormat))+20);


    //la colonne 5 a des colonnes plus grosses pour le délégué sous formes de carte..
    ui->tableView_5->setModel(umodel);
    ui->tableView_5->setItemDelegateForColumn(Usager::COL_POS,new GeoPositionDelegate(this));
    ui->tableView_5->verticalHeader()->hide();
    ui->tableView_5->verticalHeader()->setDefaultSectionSize(300);

    ui->tableView_5->horizontalHeader()->setDefaultSectionSize(60);
    ui->tableView_5->setColumnWidth(Usager::COL_POS,300);
    ui->tableView_5->setColumnWidth(Usager::COL_NOM,fm.width(QString("Jean-Sébastien")));

    ui->tableView_6->setModel(nmodel);
    ui->tableView_6->verticalHeader()->hide();
    ui->tableView_6->verticalHeader()->setDefaultSectionSize(30);
    ui->tableView_6->horizontalHeader()->setDefaultSectionSize(60);

    ui->tableView_6->setColumnWidth(Note::COL_DATE,fm.width(locale.toString(QDateTime::currentDateTime(),QLocale::ShortFormat))+20);
    ui->tableView_6->setColumnWidth(Note::COL_DESC,200);
}
