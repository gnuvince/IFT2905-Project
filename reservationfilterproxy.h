#ifndef RESERVATIONFILTERPROXY_H
#define RESERVATIONFILTERPROXY_H

#include <QSortFilterProxyModel>

#include "reservationmodel.h"
#include "usager.h"

class ReservationFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit ReservationFilterProxy(QObject *parent = 0);
    void setUser(Usager *user);

protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    ReservationModel *reservationModel;
    Usager *user;
    bool pastResIncluded;
    bool currentResIncluded;
    bool futurResIncluded;

signals:

public slots:
    void includePastRes(bool p);
    void includeCurrentRes(bool p);
    void includeFuturRes(bool p);

};

#endif // RESERVATIONFILTERPROXY_H
