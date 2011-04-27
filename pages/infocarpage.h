#ifndef INFOCARPAGE_H
#define INFOCARPAGE_H

#include <QtGui>
#include "vehicule.h"
#include "page.h"

class InfoCarPage : public Page
{
    Q_OBJECT
public:
    explicit InfoCarPage(Vehicule &vehicule, QWidget *parent = 0);
    QLabel* titleLabel(QString title);

private:
    Vehicule &vehicule;

signals:

public slots:

};

#endif // INFOCARPAGE_H
