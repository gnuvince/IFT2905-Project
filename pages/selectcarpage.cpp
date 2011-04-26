#include <QtGui>
#include <QTableView>

#include "page.h"
#include "selectcarpage.h"
#include "vehiculefilterproxy.h"

SelectCarPage::SelectCarPage(VehiculeFilterProxy *vproxy, QWidget *parent) :
    Page(parent),
    vehiculeProxy(vproxy)
{
    addTitle(trUtf8("Choisir le véhicule\n(5 / 5)"));

    QTableView *view = new QTableView(this);
    view->setModel(vehiculeProxy);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->verticalHeader()->hide();
    view->hideColumn(Vehicule::COL_ID);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    addWidget(view);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    btnNext = new QPushButton(this);
    btnNext->setIcon(QIcon(":/icones/data/icons/arrow_right.png"));
    btnNext->setEnabled(false);
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(btnPrevious, btnMenu, btnNext);

    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnNext, SIGNAL(clicked()), SIGNAL(Next()));
    connect(view, SIGNAL(clicked(QModelIndex)), this, SLOT(selectedCar(QModelIndex)));
}

void SelectCarPage::selectedCar(QModelIndex index) {
    btnNext->setEnabled(true);

    QModelIndex index2 = index.model()->index(index.row(), Vehicule::COL_ID);
    emit carSelected(index2.data().toInt());
}
