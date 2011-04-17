#ifndef SELECTPOSITIONPAGE_H
#define SELECTPOSITIONPAGE_H

#include <QtGui>
#include "page.h"

class SelectPositionPage : public Page
{
    Q_OBJECT
public:
    explicit SelectPositionPage(QWidget *parent = 0);

signals:


public slots:
    void enableNextButton();

private:
    QPushButton *btnNext;

};

#endif // SELECTPOSITIONPAGE_H
