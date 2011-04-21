#include "userinterface.h"
#include "ui_userinterface.h"

#include "pages/page.h"
#include "pages/mainmenupage.h"
#include "pages/findstationpage.h"
#include "pages/selectpositionpage.h"
#include "pages/selectstationpage.h"
#include "pages/selecttimepage.h"
#include "pages/selectcarpage.h"
#include "pages/confirmpage.h"

#include "stationmodel.h"
#include "stationsortproxy.h"

#include <QDebug>

#define DEFAULT_PAGE Page_MainMenu


UserInterface::UserInterface(
    StationModel *smodel,
    QWidget *parent) :
    QMainWindow(parent),
    stationModel(smodel),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    ui->lblEnveloppe->setPixmap(QPixmap(":/icones/data/icons/email.png"));
    ui->lblEnveloppe->setCursor(QCursor(Qt::PointingHandCursor));

    StationSortProxy *stationProxy = new StationSortProxy(this);
    stationProxy->setSourceModel(stationModel);
    stationProxy->sort(1);

    pages = new QMap<PageName, Page*>;

    pages->insert(Page_MainMenu, new MainMenuPage(this));
    pages->insert(Page_FindStation, new FindStationPage(this));
    pages->insert(Page_SelectPosition, new SelectPositionPage(this));
    pages->insert(Page_SelectStation, new SelectStationPage(stationProxy, this));
    pages->insert(Page_SelectTime, new SelectTimePage(this));
    pages->insert(Page_SelectCar, new SelectCarPage(this));
    pages->insert(Page_Confirm, new ConfirmPage(this));

    QMapIterator<PageName, Page*> iter(*pages);
    while (iter.hasNext()) {
        iter.next();
        ui->stackedWidget->addWidget(iter.value());
    }

    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(getPage(DEFAULT_PAGE)));

    // Connections for main menu
    connect(getPage(Page_MainMenu), SIGNAL(BookCar()), this, SLOT(gotoFindStationPage()));

    // Connections for find station
    connect(getPage(Page_FindStation), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_FindStation), SIGNAL(SelectPosition()), this, SLOT(gotoSelectPosition()));
    connect(getPage(Page_FindStation), SIGNAL(UseCurrentPosition()), this, SLOT(gotoSelectStation()));

    // Connections for select position
    connect(getPage(Page_SelectPosition), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectPosition), SIGNAL(Previous()), this, SLOT(gotoFindStationPage()));
    connect(getPage(Page_SelectPosition), SIGNAL(Next()), this, SLOT(gotoSelectStation()));

    // Connections for select station
    connect(getPage(Page_SelectStation), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectStation), SIGNAL(Previous()), this, SLOT(gotoSelectPosition()));
    connect(getPage(Page_SelectStation), SIGNAL(Next()), this, SLOT(gotoSelectTime()));

    // Connections for select time
    connect(getPage(Page_SelectTime), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectTime), SIGNAL(Previous()), this, SLOT(gotoSelectStation()));
    connect(getPage(Page_SelectTime), SIGNAL(Next()), this, SLOT(gotoSelectCar()));

    // Connections for select car
    connect(getPage(Page_SelectCar), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectCar), SIGNAL(Previous()), this, SLOT(gotoSelectTime()));
    connect(getPage(Page_SelectCar), SIGNAL(Next()), this, SLOT(gotoConfirm()));

    // Connections for confirm
    connect(getPage(Page_Confirm), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_Confirm), SIGNAL(Previous()), this, SLOT(gotoSelectCar()));
    connect(getPage(Page_Confirm), SIGNAL(Confirm()), this, SLOT(gotoMainMenu()));
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
