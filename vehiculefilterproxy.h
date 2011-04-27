#ifndef VEHICULEFILTERPROXY_H
#define VEHICULEFILTERPROXY_H

#include <QSortFilterProxyModel>

#include "reservation.h"
#include "reservationmodel.h"

class VehiculeFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit VehiculeFilterProxy(ReservationModel *rmodel, QObject *parent = 0);
    void setReservation(Reservation *res);

protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    ReservationModel *reservationModel;
    Reservation *reservation;

signals:

public slots:

};

#endif // VEHICULEFILTERPROXY_H
