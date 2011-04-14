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
    void Menu();
    void Previous();
    void Next();

public slots:

};

#endif // SELECTPOSITIONPAGE_H
