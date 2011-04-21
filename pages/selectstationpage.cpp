#include "selectstationpage.h"
#include "page.h"
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
}

void SelectStationPage::stationSelected(QModelIndex index) {
    btnNext->setEnabled(true);
}

