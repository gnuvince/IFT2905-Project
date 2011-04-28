#include <QtGui>
#include <QTableView>

#include "page.h"
#include "selectcarpage.h"
#include "vehiculemodel.h"
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
    view->setColumnHidden(0, true);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    view->setAlternatingRowColors(true);

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
    connect(view, SIGNAL(clicked(QModelIndex)), this, SLOT(showInformation(QModelIndex)));
}

void SelectCarPage::selectedCar(QModelIndex index) {
    btnNext->setEnabled(true);

    QModelIndex index2 = index.model()->index(index.row(), Vehicule::COL_ID);
    emit carSelected(index2.data().toInt());
}


void SelectCarPage::showInformation(QModelIndex index) {
    if (index.column() == 4) {
        QModelIndex index2 = index.model()->index(index.row(), Vehicule::COL_ID);
        qint64 vehiculeId = index2.data().toInt();
        VehiculeModel *model = (VehiculeModel*)(vehiculeProxy->sourceModel());
        Vehicule *vehicule = model->getVehicule(vehiculeId);
        emit showInfoVehicule(vehicule);
    }
}
