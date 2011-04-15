#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H

#include <QtGui>
#include "page.h"

class MainMenuPage : public Page
{
    Q_OBJECT

public:
    explicit MainMenuPage(QWidget *parent = 0);

public slots:

signals:
    void BookCar();
    void ViewBookings();
    void LeaveComment();
    void ReportProblem();
};

#endif // MAINMENUPAGE_H
