#ifndef INFOSTATIONPAGE_H
#define INFOSTATIONPAGE_H

#include <QtGui>

#include "page.h"
#include "station.h"

class InfoStationPage : public Page
{
    Q_OBJECT
public:
    explicit InfoStationPage(Station &station, QWidget *parent = 0);

signals:

public slots:

private:
    Station &station;

};

#endif // INFOSTATIONPAGE_H
