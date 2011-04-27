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
        || source_column == Reservation::COL_USAGER
        || source_column == Reservation::COL_STATION
        || source_column == Reservation::COL_PERSO;
}


bool ReservationFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (user == 0)
        return false;


    QModelIndex indexUser = sourceModel()->index(source_row, Reservation::COL_USAGER);
    if (user->getId() == indexUser.data().toInt()) {
        QDateTime now = QDateTime::currentDateTime();
        QDateTime resStart = sourceModel()->index(source_row, Reservation::COL_DEBUT).data().toDateTime();
        QDateTime resEnd = sourceModel()->index(source_row, Reservation::COL_FIN).data().toDateTime();

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
}

void ReservationFilterProxy::includeCurrentRes(bool p) {
    this->currentResIncluded = p;
}

void ReservationFilterProxy::includeFuturRes(bool p) {
    this->futurResIncluded = p;
}
