#ifndef BOOKINGSPAGE_H
#define BOOKINGSPAGE_H

#include <QtGui>

#include "page.h"
#include "reservationfilterproxy.h"

class BookingsPage : public Page
{
    Q_OBJECT
public:
    explicit BookingsPage(
            ReservationFilterProxy *rmodel,
            QWidget *parent = 0);

signals:

public slots:

private:
    ReservationFilterProxy *reservationModel;
};

#endif // BOOKINGSPAGE_H
