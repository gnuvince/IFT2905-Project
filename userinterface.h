#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QtGui>
#include <QMainWindow>
#include <QStackedWidget>

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
};

#endif // USERINTERFACE_H
