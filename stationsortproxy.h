#ifndef STATIONSORTPROXY_H
#define STATIONSORTPROXY_H

#include <QSortFilterProxyModel>

class StationSortProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit StationSortProxy(QObject *parent = 0);

signals:

public slots:

protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;

};

#endif // STATIONSORTPROXY_H
