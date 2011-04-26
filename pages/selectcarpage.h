#ifndef SELECTCARPAGE_H
#define SELECTCARPAGE_H

#include <QtGui>
#include <QModelIndex>

#include "page.h"
#include "vehiculefilterproxy.h"

class SelectCarPage : public Page
{
    Q_OBJECT
public:
    explicit SelectCarPage(VehiculeFilterProxy *vproxy, QWidget *parent = 0);

private:
    VehiculeFilterProxy *vehiculeProxy;
    QPushButton *btnNext;

signals:
    void carSelected(qint64 carId);

public slots:
    void selectedCar(QModelIndex index);

};

#endif // SELECTCARPAGE_H
