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
            ReservationFilterProxy *rproxy,
            QWidget *parent = 0);

signals:
    void includePastRes(bool);
    void includeCurrentRes(bool);
    void includeFuturRes(bool);

public slots:
    void resizeCols();

private:
    ReservationFilterProxy *reservationProxy;
    QTableView *bookings;
};

#endif // BOOKINGSPAGE_H
