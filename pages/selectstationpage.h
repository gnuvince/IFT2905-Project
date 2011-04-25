#ifndef SELECTSTATIONPAGE_H
#define SELECTSTATIONPAGE_H

#include "stationsortproxy.h"

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


public slots:
    void stationSelected(QModelIndex index);
    void showInformation(QModelIndex index);

private:
    StationSortProxy *stationModel;
    QPushButton *btnNext;

};

#endif // SELECTSTATIONPAGE_H
