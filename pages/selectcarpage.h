#ifndef SELECTCARPAGE_H
#define SELECTCARPAGE_H

#include <QtGui>
#include <QModelIndex>

#include "page.h"
#include "vehiculefilterproxy.h"
#include "vehicule.h"

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
    void showInfoVehicule(Vehicule *vehicule);

public slots:
    void selectedCar(QModelIndex index);
    void showInformation(QModelIndex index);

};

#endif // SELECTCARPAGE_H
