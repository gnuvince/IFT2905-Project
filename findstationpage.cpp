#include "page.h"
#include "findstationpage.h"
#include <QtGui>

FindStationPage::FindStationPage(QWidget *parent) :
    Page(parent)
{
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"));
    QPushButton *btnUseCurrentPosition = new QPushButton(trUtf8("Utiliser ma position courante"));
    QPushButton *btnChoosePosition = new QPushButton(trUtf8("Choisir une position"));

    addTitle(trUtf8("Trouver une station\n(1 / 5)"));
    addWidget(btnUseCurrentPosition);
    addWidget(btnChoosePosition);
    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnUseCurrentPosition, SIGNAL(clicked()), SIGNAL(UseCurrentPosition()));
    connect(btnChoosePosition, SIGNAL(clicked()), SIGNAL(ChoosePosition()));
}
