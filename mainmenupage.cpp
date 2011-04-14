#include "mainmenupage.h"

#include <QtGui>

MainMenuPage::MainMenuPage(QWidget *parent) :
        Page(parent)
{
    QPushButton *btnBookCar = new QPushButton(trUtf8("Réserver une voiture"));
    QPushButton *btnBookings = new QPushButton(trUtf8("Voir mes réservations"));
    QPushButton *btnLeaveComment = new QPushButton(trUtf8("Laisser une commentaire"));
    QPushButton *btnReportProblem = new QPushButton(trUtf8("Rapporter un imprévu"));

    addWidget(btnBookCar);
    addWidget(btnBookings);
    addWidget(btnLeaveComment);
    addWidget(btnReportProblem);

    QPushButton *btnQuit = new QPushButton(trUtf8("Quitter"));
    addBottomButtons(0, btnQuit, 0);

    connect(btnQuit, SIGNAL(clicked()), parent, SLOT(close()));
}
