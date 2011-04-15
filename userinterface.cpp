#include "userinterface.h"
#include "ui_userinterface.h"

#include "pages/page.h"
#include "pages/mainmenupage.h"
#include "pages/findstationpage.h"
#include "pages/selectpositionpage.h"

#include <QDebug>

#define DEFAULT_PAGE Page_MainMenu


UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    ui->lblEnveloppe->setPixmap(QPixmap(":/icones/data/icons/email.png"));
    ui->lblEnveloppe->setCursor(QCursor(Qt::PointingHandCursor));

    pages = new QMap<PageName, Page*>;

    pages->insert(Page_MainMenu, new MainMenuPage(this));
    pages->insert(Page_FindStation, new FindStationPage(this));
    pages->insert(Page_SelectPosition, new SelectPositionPage(this));

    QMapIterator<PageName, Page*> iter(*pages);
    while (iter.hasNext()) {
        iter.next();
        ui->stackedWidget->addWidget(iter.value());
    }

    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(getPage(DEFAULT_PAGE)));

    // Signals for mainMenu
    connect(getPage(Page_MainMenu), SIGNAL(BookCar()), this, SLOT(gotoFindStationPage()));

    // Signals for findStation
    connect(getPage(Page_FindStation), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_FindStation), SIGNAL(SelectPosition()), this, SLOT(gotoSelectPosition()));
    connect(getPage(Page_FindStation), SIGNAL(UseCurrentPosition()), this, SLOT(gotoSelectStation()));
}

UserInterface::~UserInterface()
{
    delete ui;
}


Page* UserInterface::getPage(PageName name) {
    return pages->value(name);
}


void UserInterface::gotoPage(PageName name) {
    int i = ui->stackedWidget->indexOf(getPage(name));
    ui->stackedWidget->setCurrentIndex(i);
}


void UserInterface::gotoMainMenu() {
    gotoPage(Page_MainMenu);
}

void UserInterface::gotoFindStationPage() {
    gotoPage(Page_FindStation);
}

void UserInterface::gotoSelectStation() {
    gotoPage(Page_SelectStation);
}

void UserInterface::gotoSelectPosition() {
    gotoPage(Page_SelectPosition);
}

void UserInterface::gotoSelectTime() {
    gotoPage(Page_SelectTime);
}

void UserInterface::gotoSelectCar() {
    gotoPage(Page_SelectCar);
}

void UserInterface::gotoConfirm() {
    gotoPage(Page_Confirm);
}
