#include <QtGui>

#include "page.h"
#include "confirmpage.h"
#include "vehicule.h"

ConfirmPage::ConfirmPage(UsagerModel *umodel,
                         VehiculeModel *vmodel,
                         StationModel *smodel,
                         QWidget *parent) :
    Page(parent),
    umodel(umodel),
    vmodel(vmodel),
    smodel(smodel)
{
    addTitle(trUtf8("Confirmer la réservation"));


    editor = new QPlainTextEdit(this);
    editor->setReadOnly(true);
    editor->setFont(QFont("Courier"));


    addWidget(editor);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    QPushButton *btnConfirm= new QPushButton(trUtf8("Confirmer"), this);
    btnConfirm->setIcon(QIcon(":/icones/data/icons/tick.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(btnPrevious, btnMenu, btnConfirm);

    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnConfirm, SIGNAL(clicked()), SIGNAL(Confirm()));
}

void ConfirmPage::setEditorText() {
    QString username = umodel->getUsager(reservation->getUsager())->getNom();
    QString station = smodel->getStation(reservation->getStation())->getNom();
    Vehicule *vehicule = vmodel->getVehicule(reservation->getVehicule());
    QString vehiculeName = trUtf8("%1 %2 (%3)").arg(vehicule->getMarque())
            .arg(vehicule->getModele()).arg(vehicule->getCouleur());

    editor->setPlainText(
                trUtf8("Usager  : %1\n"
                       "Station : %2\n"
                       "Véhicule: %3\n"
                       "Départ  : %4\n"
                       "Retour  : %5\n")
                .arg(username)
                .arg(station)
                .arg(vehiculeName)
                .arg(reservation->getDebut().toString("dd MMM yyyy hh:mm"))
                .arg(reservation->getFin().toString("dd MMM yyyy hh:mm"))
    );
}

void ConfirmPage::setReservation(Reservation *res) {
    reservation = res;
}
