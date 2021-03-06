#ifndef CONFIRMPAGE_H
#define CONFIRMPAGE_H

#include <QtGui>

#include "page.h"
#include "reservation.h"
#include "usagermodel.h"
#include "vehiculemodel.h"
#include "reservationmodel.h"
#include "stationmodel.h"

class ConfirmPage : public Page
{
    Q_OBJECT
public:
    explicit ConfirmPage(UsagerModel *umodel,
                         VehiculeModel *vmodel,
                         StationModel *smodel,
                         QWidget *parent = 0);
    void setReservation(Reservation *res);
    QPlainTextEdit *editor;


private:
    Reservation *reservation;
    UsagerModel *umodel;
    VehiculeModel *vmodel;
    StationModel *smodel;


signals:
    void Confirm();

public slots:
    void setEditorText();

};

#endif // CONFIRMPAGE_H
