#ifndef FINDSTATIONPAGE_H
#define FINDSTATIONPAGE_H

#include <QWidget>
#include "page.h"

class FindStationPage : public Page
{
    Q_OBJECT

public:
    explicit FindStationPage(QWidget *parent = 0);

signals:
    void UseCurrentPosition();
    void SelectPosition();

public slots:

};

#endif // FINDSTATIONPAGE_H
