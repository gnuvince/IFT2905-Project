#ifndef SELECTPOSITIONPAGE_H
#define SELECTPOSITIONPAGE_H

#include <QtGui>
#include "page.h"
#include "geoposition.h"
#include "cartewidget.h"

class SelectPositionPage : public Page
{
    Q_OBJECT
public:
    explicit SelectPositionPage(QWidget *parent = 0);

signals:
    void positionSelected(GeoPosition gp);

public slots:
    void enableNextButton();

private:
    QPushButton *btnNext;
    CarteWidget *mapWidget;

};

#endif // SELECTPOSITIONPAGE_H
