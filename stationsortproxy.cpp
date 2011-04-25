#include "stationsortproxy.h"
#include "station.h"

#include <QDebug>

StationSortProxy::StationSortProxy(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

bool StationSortProxy::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
    return source_column == Station::COL_ID
        || source_column == Station::COL_NOM
        || source_column == Station::COL_DIST
        || source_column == Station::COL_INFO;
}

bool StationSortProxy::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    QModelIndex leftIndex = sourceModel()->index(left.row(), Station::COL_DIST);
    QModelIndex rightIndex = sourceModel()->index(right.row(), Station::COL_DIST);
    qreal a = leftIndex.data().toString().split(' ').at(0).toDouble();
    qreal b = rightIndex.data().toString().split(' ').at(0).toDouble();
    return a < b;
}
