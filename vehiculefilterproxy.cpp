#include "vehiculefilterproxy.h"
#include "vehicule.h"

#include <QDebug>

VehiculeFilterProxy::VehiculeFilterProxy(ReservationModel *rmodel, Reservation *reservation, QObject *parent) :
    QSortFilterProxyModel(parent),
    reservationModel(rmodel),
    reservation(reservation)
{
}


bool VehiculeFilterProxy::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
    return source_column == Vehicule::COL_ID
        || source_column == Vehicule::COL_MARQUE
        || source_column == Vehicule::COL_MODELE
        || source_column == Vehicule::COL_COULEUR
        || source_column == Vehicule::COL_INFO;
}


bool VehiculeFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    QModelIndex index = sourceModel()->index(source_row, Vehicule::COL_ID);
    qint64 vehiculeId = index.data().toInt();
    foreach (Reservation *res, reservationModel->getReservations()) {
        if (res->getVehicule() == vehiculeId && res->getStation() == reservation->getStation()
                && reservationModel->testReservation(reservation)) {
            return true;
        }
    }
    return false;
}
