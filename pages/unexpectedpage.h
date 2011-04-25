#ifndef UNEXPECTEDPAGE_H
#define UNEXPECTEDPAGE_H

#include <QtGui>
#include "page.h"

class UnexpectedPage : public Page
{
    Q_OBJECT

public:
    explicit UnexpectedPage(QWidget *parent = 0);

public slots:

signals:
    void ArriveEarly();
    void ArriveLate();
    void MissingKey();
    void MissingCar();
    void ContactGuard();
};

#endif // UNEXPECTEDPAGE_H
