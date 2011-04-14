#include "userinterface.h"
#include "ui_userinterface.h"
#include "page.h"
#include "mainmenupage.h"
#include "findstationpage.h"

#include <QDebug>

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    ui->lblEnveloppe->setPixmap(QPixmap(":/icones/data/icons/email.png"));
    ui->lblEnveloppe->setCursor(QCursor(Qt::PointingHandCursor));

    pages = new QMap<QString, Page*>;

    pages->insert(QString("mainMenu"), new MainMenuPage(this));
    pages->insert(QString("findStation"), new FindStationPage(this));

    QMapIterator<QString, Page*> iter(*pages);
    while (iter.hasNext()) {
        iter.next();
        ui->stackedWidget->addWidget(iter.value());
    }

    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(getPage("mainMenu")));

    connect(getPage("mainMenu"), SIGNAL(BookCar()), this, SLOT(gotoFindStationPage()));
    connect(getPage("findStation"), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::gotoPage(const char *s) {
    int i = ui->stackedWidget->indexOf(getPage(s));
    ui->stackedWidget->setCurrentIndex(i);
}

void UserInterface::gotoFindStationPage() {
    gotoPage("findStation");
}

void UserInterface::gotoMainMenu() {
    gotoPage("mainMenu");
}


Page* UserInterface::getPage(const char *s) {
    return pages->value(QString(s));
}
