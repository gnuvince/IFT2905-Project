#include <QDateTime>
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
        || source_column == Reservation::COL_STATION;
}


bool ReservationFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (user == 0)
        return false;

    QModelIndex index = sourceModel()->index(source_row, Reservation::COL_ID);
    qint64 reservationId = index.data().toInt();
    Reservation *reservation = dynamic_cast<ReservationModel*>(sourceModel())->getReservation(reservationId);

    if (reservation->getUsager() == user->getId()) {
        QDateTime now = QDateTime::currentDateTime();
        QDateTime resStart = reservation->getDebut();
        QDateTime resEnd = reservation->getFin();

        if (currentResIncluded && (now > resStart) && (now < resEnd)) {
            return true;
        }
        if (futurResIncluded && (now < resStart)) {
            return true;
        }
        if (pastResIncluded && (now > resEnd)) {
            return true;
        }
    }
    return false;
}

void ReservationFilterProxy::setUser(Usager *user) {
    qDebug() << "ReservationFilterProxy::setUser done";
    this->user = user;
}

void ReservationFilterProxy::includePastRes(bool p) {
    this->pastResIncluded = p;
    invalidate();
}

void ReservationFilterProxy::includeCurrentRes(bool p) {
    this->currentResIncluded = p;
    invalidate();
}

void ReservationFilterProxy::includeFuturRes(bool p) {
    this->futurResIncluded = p;
    invalidate();
}
