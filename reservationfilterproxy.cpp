#include "reservationfilterproxy.h"
#include "reservation.h"

#include <QDebug>

ReservationFilterProxy::ReservationFilterProxy(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    user = 0;
}


bool ReservationFilterProxy::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
    return source_column == Reservation::COL_ID
        || source_column == Reservation::COL_DEBUT
        || source_column == Reservation::COL_FIN
        || source_column == Reservation::COL_VEHICULE
        || source_column == Reservation::COL_USAGER
        || source_column == Reservation::COL_STATION
        || source_column == Reservation::COL_PERSO;
}


bool ReservationFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (user == 0)
        return false;

    foreach (Reservation *res, reservationModel->getReservations()) {
        qDebug() << "res user: " << res->getUsager();
        qDebug() << "user id: " << user->getId();
        qDebug() << "user name: " << user->getNom();
        if (res->getUsager() == user->getId())
            return true;
    }
    return false;
}

void ReservationFilterProxy::setUser(Usager *user) {
    qDebug() << "ReservationFilterProxy::setUser done";
    this->user = user;
}
