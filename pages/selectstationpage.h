#ifndef SELECTSTATIONPAGE_H
#define SELECTSTATIONPAGE_H

#include "stationsortproxy.h"

#include "station.h"
#include "page.h"
#include <QtGui>

class SelectStationPage : public Page
{
    Q_OBJECT
public:
    explicit SelectStationPage(
        StationSortProxy *smodel,
        QWidget *parent = 0);

signals:
    void showInfoStation(Station *station);
    void selectedStation(qint64 stationId);

public slots:
    void stationSelected(QModelIndex index);
    void showInformation(QModelIndex index);

private:
    StationSortProxy *stationModel;
    QPushButton *btnNext;

};

#endif // SELECTSTATIONPAGE_H
