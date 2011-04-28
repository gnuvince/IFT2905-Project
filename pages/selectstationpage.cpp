#include <QMessageBox>

#include "selectstationpage.h"
#include "infostationpage.h"
#include "page.h"
#include "stationmodel.h"
#include "stationsortproxy.h"
#include "station.h"

#include <QtGui>

SelectStationPage::SelectStationPage(
    StationSortProxy *smodel,
    QWidget *parent) :
    Page(parent),
    stationModel(smodel)
{
    QTableView *view = new QTableView(this);
    view->setModel(stationModel);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->verticalHeader()->hide();
    view->hideColumn(0);
    view->resizeColumnToContents(2);
    view->resizeColumnToContents(3);
    view->resizeRowsToContents();
    view->setAlternatingRowColors(true);


    QFont font = view->font();
    font.setPointSize(8);
    view->setFont(font);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    btnNext = new QPushButton(this);
    btnNext->setIcon(QIcon(":/icones/data/icons/arrow_right.png"));
    btnNext->setEnabled(false);
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addTitle(trUtf8("Choisir une station\n(3 / 5)"));
    addWidget(view);
    addBottomButtons(btnPrevious, btnMenu, btnNext);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnNext, SIGNAL(clicked()), SIGNAL(Next()));
    connect(view, SIGNAL(clicked(QModelIndex)), this, SLOT(stationSelected(QModelIndex)));
    connect(view, SIGNAL(clicked(QModelIndex)), this, SLOT(showInformation(QModelIndex)));

}

void SelectStationPage::stationSelected(QModelIndex index) {
    btnNext->setEnabled(true);

    QModelIndex index2 = index.model()->index(index.row(), Station::COL_ID);
    emit selectedStation(index2.data().toInt());
}


void SelectStationPage::showInformation(QModelIndex index) {
    if (index.column() == 3) {
        QModelIndex index2 = index.model()->index(index.row(), Station::COL_ID);
        qint64 stationId = index2.data().toInt();
        StationModel *model = (StationModel*)(stationModel->sourceModel());
        Station *station = model->getStation(stationId);
        emit showInfoStation(station);
    }
}
