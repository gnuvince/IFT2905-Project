#include <QtGui>
#include <QTableView>

#include "page.h"
#include "selectcarpage.h"

SelectCarPage::SelectCarPage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Choisir le véhicule\n(5 / 5)"));

    QTableView *view = new QTableView(this);
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
