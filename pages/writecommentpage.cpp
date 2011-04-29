#include <QtGui>
#include <QTableView>
#include <QDebug>

#include "page.h"
#include "writecommentpage.h"
#include "station.h"
#include "vehicule.h"
#include "reservation.h"
#include "note.h"

WriteCommentPage::WriteCommentPage(qint64 uid, NoteModel *nmodel, ReservationModel *rmodel, StationModel *smodel, VehiculeModel *vmodel, QWidget *parent) :
    Page(parent),
    reservationModel(rmodel),
    noteModel(nmodel),
    stationModel(smodel),
    vehiculeModel(vmodel),
    userId(uid)
{
    addTitle(trUtf8("Écrire un commentaire"));

    type = new QComboBox(this);
    type->addItem(trUtf8("Véhicule"), 0);
    type->addItem(trUtf8("Station"), 1);

    comment = new QTextEdit(this);

    QWidget *widget = new QWidget(this);
    QFormLayout *layout = new QFormLayout(this);

    subject = new QComboBox(this);
    subject->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    layout->addRow(trUtf8("Type:"), type);
    layout->addRow(trUtf8("Sujet:"), subject);
    layout->addRow(trUtf8("Message:"), comment);

    widget->setLayout(layout);
    addWidget(widget);

    btnSend = new QPushButton(trUtf8("Envoyer"), this);
    btnSend->setEnabled(false);
    btnSend->setIcon(QIcon(":/icones/data/icons/email.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(0, btnMenu, btnSend);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnSend, SIGNAL(clicked()), SIGNAL(Send()));
    connect(btnSend, SIGNAL(clicked()), this, SLOT(addNote()));
    connect(subject, SIGNAL(currentIndexChanged(int)), this, SLOT(enableSend()));
    connect(type, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSubjects(int)));
}

void WriteCommentPage::updateSubjects(int x) {
    subject->clear();
    if (x == 0) {
        foreach (Reservation *r, reservationModel->getReservations()) {
            if (r->getUsager() == userId) {
                Vehicule *v = vehiculeModel->getVehicule(r->getVehicule());
                subject->addItem(v->getName(), v->getId());
            }
        }
    }
    else if (x == 1) {
        foreach (Reservation *r, reservationModel->getReservations()) {
            if (r->getUsager() == userId) {
                Station *s = stationModel->getStation(r->getStation());
                subject->addItem(s->getNom(), s->getId());
            }
        }
    }
}

void WriteCommentPage::addNote() {
    qint64 messageType, id;

    if (type->itemData(type->currentIndex()).toInt() == 0)
        messageType = Note::TYPE_VEHICULE;
    else
        messageType = Note::TYPE_STATION;
    id = subject->itemData(subject->currentIndex()).toInt();

    noteModel->addNote(new Note(userId,
                                QDateTime::currentDateTime(),
                                messageType,
                                id,
                                comment->toPlainText(),
                                this));
    comment->clear();
    QMessageBox::information(this,
                             trUtf8("Commentaire ajouté"),
                             trUtf8("Votre commentaire a été ajouté"),
                             QMessageBox::Ok);
}

void WriteCommentPage::enableSend() {
    btnSend->setEnabled(true);
}
