#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QtGui>
#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>

#include "pages/page.h"

enum PageName { Page_MainMenu,
                Page_FindStation, Page_SelectPosition, Page_SelectStation, Page_SelectTime, Page_SelectCar, Page_Confirm,
              };

namespace Ui {
    class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = 0);
    ~UserInterface();

private:
    Ui::UserInterface *ui;
    QMap<PageName, Page*> *pages;
    Page* getPage(PageName name);

public slots:
    void gotoPage(PageName name);
    void gotoMainMenu();
    void gotoFindStationPage();
    void gotoSelectPosition();
    void gotoSelectStation();
    void gotoSelectTime();
    void gotoSelectCar();
    void gotoConfirm();
};

#endif // USERINTERFACE_H
