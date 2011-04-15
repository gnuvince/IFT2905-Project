#include "selectstationpage.h"
#include "page.h"

#include <QtGui>

SelectStationPage::SelectStationPage(QWidget *parent) :
    Page(parent)
{
    QTableView *view = new QTableView(this);

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

