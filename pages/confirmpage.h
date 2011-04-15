#ifndef CONFIRMPAGE_H
#define CONFIRMPAGE_H

#include <QtGui>

#include "page.h"

class ConfirmPage : public Page
{
    Q_OBJECT
public:
    explicit ConfirmPage(QWidget *parent = 0);

signals:
    void Confirm();

public slots:

};

#endif // CONFIRMPAGE_H
