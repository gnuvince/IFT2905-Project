#include "vehiculefilterproxy.h"
#include "vehicule.h"

#include <QDebug>

VehiculeFilterProxy::VehiculeFilterProxy(ReservationModel *rmodel, QObject *parent) :
    QSortFilterProxyModel(parent),
    reservationModel(rmodel)
{
    reservation = 0;
}


bool VehiculeFilterProxy::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
    return source_column == Vehicule::COL_ID
        || source_column == Vehicule::COL_MARQUE
        || source_column == Vehicule::COL_MODELE
        || source_column == Vehicule::COL_COULEUR
        || source_column == Vehicule::COL_INFO;
}


bool VehiculeFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (reservation == 0)
        return false;

    QModelIndex index = sourceModel()->index(source_row, Vehicule::COL_ID);
    qint64 vehiculeId = index.data().toInt();
    return reservationModel->vehiculeAvailable(vehiculeId, reservation->getStation(), reservation->getDebut(), reservation->getFin());
}

void VehiculeFilterProxy::setReservation(Reservation *res) {
    reservation = res;
}
