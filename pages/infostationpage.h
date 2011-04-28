#ifndef INFOSTATIONPAGE_H
#define INFOSTATIONPAGE_H

#include <QtGui>

#include "page.h"
#include "station.h"
#include "notemodel.h"

class InfoStationPage : public Page
{
    Q_OBJECT
public:
    explicit InfoStationPage(Station &station, NoteModel &noteModel, QWidget *parent = 0);
    QLabel* titleLabel(QString title);

signals:

public slots:

private:
    Station &station;

};

#endif // INFOSTATIONPAGE_H
