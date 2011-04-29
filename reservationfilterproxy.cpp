#include <QDateTime>
#include "reservationfilterproxy.h"
#include "reservation.h"
#include "stationmodel.h"
#include "vehiculemodel.h"

#include <QDebug>

ReservationFilterProxy::ReservationFilterProxy(
    StationModel *smodel,
    VehiculeModel *vmodel,
    QObject *parent) :
    QSortFilterProxyModel(parent),
    stationModel(smodel),
    vehiculeModel(vmodel)
{
    user = 0;
    pastResIncluded = true;
    currentResIncluded = true;
    futurResIncluded = true;
}


bool ReservationFilterProxy::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
    return true;
}

QVariant ReservationFilterProxy::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    qint64 vid, sid;

    QVariant data = sourceModel()->data(index);

    switch (index.column()) {
    case Reservation::COL_DEBUT:
        return data.toDateTime().toString("dd MMM yyyy hh:mm");

    case Reservation::COL_STATION:
        sid = data.toInt();
        return stationModel->getStation(sid)->getNom();

    case Reservation::COL_VEHICULE:
        vid = data.toInt();
        return vehiculeModel->getVehicule(vid)->getName();

    default:
        return QVariant();
    }
}


QVariant ReservationFilterProxy::headerData(int section, Qt::Orientation orientation, int role) const {
    return sourceModel()->headerData(section, orientation, role);
}

Qt::ItemFlags ReservationFilterProxy::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
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
