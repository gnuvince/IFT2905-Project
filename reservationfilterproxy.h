#ifndef RESERVATIONFILTERPROXY_H
#define RESERVATIONFILTERPROXY_H

#include <QSortFilterProxyModel>

#include "reservation.h"
#include "reservationmodel.h"
#include "usager.h"

class ReservationFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit ReservationFilterProxy(ReservationModel *rmodel, Reservation *reservation, Usager *user, QObject *parent = 0);

protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    ReservationModel *reservationModel;
    Reservation *reservation;
    Usager *user;

signals:

public slots:

};

#endif // RESERVATIONFILTERPROXY_H
