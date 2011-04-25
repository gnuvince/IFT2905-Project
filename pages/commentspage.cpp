#include "commentspage.h"
#include "page.h"

#include <QtGui>

CommentsPage::CommentsPage(QWidget *parent):
        Page(parent)
{
    addTitle(trUtf8("Commentaires"));

    QPushButton *btnVehicule = new QPushButton(trUtf8("Véhicule"));
    QPushButton *btnStation = new QPushButton(trUtf8("Station"));
    QPushButton *btnReservation = new QPushButton(trUtf8("Reservation"));
    QPushButton *btnToUser = new QPushButton(trUtf8("Usager"));

    btnVehicule->setIcon(QIcon(":/icones/data/icons/car_add.png"));
    btnStation->setIcon(QIcon(":/icones/data/icons/table_multiple.png"));
    btnReservation->setIcon(QIcon(":/icones/data/icons/pencil.png"));
    btnToUser->setIcon(QIcon(":/icones/data/icons/pencil.png"));

    addWidget(btnVehicule);
    addWidget(btnStation);
    addWidget(btnReservation);
    addWidget(btnToUser);

    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"));
    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnVehicule, SIGNAL(clicked()), SIGNAL(VehiculeComment()));
    connect(btnStation, SIGNAL(clicked()), SIGNAL(StationComment()));
    connect(btnReservation, SIGNAL(clicked()), SIGNAL(ReservationComment()));
    connect(btnToUser, SIGNAL(clicked()), SIGNAL(ToUserComment()));
}
