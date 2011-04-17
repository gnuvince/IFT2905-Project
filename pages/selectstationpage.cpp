#include "selectstationpage.h"
#include "page.h"
#include "stationmodel.h"

#include <QtGui>

SelectStationPage::SelectStationPage(
    StationModel *smodel,
    QWidget *parent) :
    Page(parent),
    stationModel(smodel)
{
    QTableView *view = new QTableView(this);
    view->setModel(stationModel);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);

    QList<qint32> hiddenColumns;
    hiddenColumns << 0 << 2 << 3 << 4 << 5 << 6;
    foreach (qint32 col, hiddenColumns) {
        view->hideColumn(col);
    }


    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    QPushButton *btnNext = new QPushButton(this);
    btnNext->setIcon(QIcon(":/icones/data/icons/arrow_right.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addTitle(trUtf8("Choisir une station\n(3 / 5)"));
    addWidget(view);
    addBottomButtons(btnPrevious, btnMenu, btnNext);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnNext, SIGNAL(clicked()), SIGNAL(Next()));
}

