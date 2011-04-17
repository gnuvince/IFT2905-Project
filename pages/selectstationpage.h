#ifndef SELECTSTATIONPAGE_H
#define SELECTSTATIONPAGE_H

#include "stationmodel.h"

#include "page.h"
#include <QtGui>

class SelectStationPage : public Page
{
    Q_OBJECT
public:
    explicit SelectStationPage(
        StationModel *smodel,
        QWidget *parent = 0);

signals:


public slots:

private:
    StationModel *stationModel;

};

#endif // SELECTSTATIONPAGE_H
