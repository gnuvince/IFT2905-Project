#include "mainmenupage.h"
#include "page.h"

#include <QtGui>

MainMenuPage::MainMenuPage(QWidget *parent):
        Page(parent)
{
    QPushButton *btnBookCar = new QPushButton(trUtf8("Réserver une voiture"));
    QPushButton *btnBookings = new QPushButton(trUtf8("Voir mes réservations"));
    QPushButton *btnLeaveComment = new QPushButton(trUtf8("Laisser un commentaire"));
    //QPushButton *btnReportUnexpected = new QPushButton(trUtf8("Rapporter un imprévu"));

    btnBookCar->setIcon(QIcon(":/icones/data/icons/car_add.png"));
    btnBookings->setIcon(QIcon(":/icones/data/icons/table_multiple.png"));
    btnLeaveComment->setIcon(QIcon(":/icones/data/icons/pencil.png"));
    //btnReportUnexpected->setIcon(QIcon(":/icones/data/icons/error.png"));

    addWidget(btnBookCar);
    addWidget(btnBookings);
    addWidget(btnLeaveComment);
    //addWidget(btnReportUnexpected);

    QPushButton *btnQuit = new QPushButton(trUtf8("Quitter"));
    addBottomButtons(0, btnQuit, 0);

    connect(btnQuit, SIGNAL(clicked()), parent, SLOT(close()));
    connect(btnBookCar, SIGNAL(clicked()), SIGNAL(BookCar()));
    connect(btnBookings, SIGNAL(clicked()), SIGNAL(ViewBookings()));
    connect(btnLeaveComment, SIGNAL(clicked()), SIGNAL(LeaveComment()));
    //connect(btnReportUnexpected, SIGNAL(clicked()), SIGNAL(ReportUnexpected()));
}
