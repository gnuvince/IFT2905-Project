#ifndef SELECTCARPAGE_H
#define SELECTCARPAGE_H

#include <QtGui>

#include "page.h"
#include "vehiculefilterproxy.h"

class SelectCarPage : public Page
{
    Q_OBJECT
public:
    explicit SelectCarPage(VehiculeFilterProxy *vproxy, QWidget *parent = 0);

private:
    VehiculeFilterProxy *vehiculeProxy;

signals:


public slots:

};

#endif // SELECTCARPAGE_H
