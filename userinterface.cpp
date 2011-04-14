#include "userinterface.h"
#include "ui_userinterface.h"
#include "page.h"
#include "mainmenupage.h"

#include <QDebug>

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);

    MainMenuPage *mmp = new MainMenuPage(this);
    QVBoxLayout *layout = new QVBoxLayout;
    ui->stackedWidget->addWidget(mmp);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(mmp));
}

UserInterface::~UserInterface()
{
    delete ui;
}
