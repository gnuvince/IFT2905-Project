#include "vehiculefilterproxy.h"
#include "vehicule.h"

VehiculeFilterProxy::VehiculeFilterProxy(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}


bool VehiculeFilterProxy::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
    return source_column == Vehicule::COL_ID
        || source_column == Vehicule::COL_MARQUE
        || source_column == Vehicule::COL_MODELE
        || source_column == Vehicule::COL_INFO;
}


bool VehiculeFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    return true;
}
