#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QtGui>
#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>

#include "pages/page.h"

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
    QMap<QString, Page*> *pages;
    Page* getPage(const char *s);

public slots:
    void gotoFindStationPage();
    void gotoPage(const char *s);
    void gotoMainMenu();
};

#endif // USERINTERFACE_H
