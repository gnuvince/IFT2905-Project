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
    view->hideColumn(0);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    addWidget(view);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    QPushButton *btnNext = new QPushButton(this);
    btnNext->setIcon(QIcon(":/icones/data/icons/arrow_right.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(btnPrevious, btnMenu, btnNext);

    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnNext, SIGNAL(clicked()), SIGNAL(Next()));
}
