#ifndef VEHICULEFILTERPROXY_H
#define VEHICULEFILTERPROXY_H

#include <QSortFilterProxyModel>

class VehiculeFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit VehiculeFilterProxy(QObject *parent = 0);

protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

signals:

public slots:

};

#endif // VEHICULEFILTERPROXY_H
