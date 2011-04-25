#include "unexpectedpage.h"
#include "page.h"

#include <QtGui>

UnexpectedPage::UnexpectedPage(QWidget *parent):
        Page(parent)
{
    addTitle(trUtf8("Rapporter un imprévu"));

    QPushButton *btnEarly = new QPushButton(trUtf8("Je serai en retard"));
    QPushButton *btnLate = new QPushButton(trUtf8("Je suis arrivé en avance"));
    QPushButton *btnMissingKey = new QPushButton(trUtf8("Je ne trouve pas la clé"));
    QPushButton *btnMissingCar = new QPushButton(trUtf8("La voiture n'est pas là"));
    QPushButton *btnContactGuard = new QPushButton(trUtf8("Contacter le garde"));

    btnEarly->setIcon(QIcon(":/icones/data/icons/pencil.png"));
    btnLate->setIcon(QIcon(":/icones/data/icons/pencil.png"));
    btnMissingKey->setIcon(QIcon(":/icones/data/icons/pencil.png"));
    btnMissingCar->setIcon(QIcon(":/icones/data/icons/pencil.png"));
    btnContactGuard->setIcon(QIcon(":/icones/data/icons/pencil.png"));

    addWidget(btnEarly);
    addWidget(btnLate);
    addWidget(btnMissingKey);
    addWidget(btnMissingCar);
    addWidget(btnContactGuard);

    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"));
    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnEarly, SIGNAL(clicked()), SIGNAL(ArriveEarly()));
    connect(btnLate, SIGNAL(clicked()), SIGNAL(ArriveLate()));
    connect(btnMissingKey, SIGNAL(clicked()), SIGNAL(MissingKey()));
    connect(btnMissingCar, SIGNAL(clicked()), SIGNAL(MissingCar()));
    connect(btnContactGuard, SIGNAL(clicked()), SIGNAL(ContactGuard()));
}
