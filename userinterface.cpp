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
#include "pages/commentspage.h"
#include "pages/unexpectedpage.h"
#include "pages/bookingspage.h"
#include "pages/mymessagespage.h"
#include "pages/writecommentpage.h"
#include "pages/infostationpage.h"

#include "station.h"
#include "stationmodel.h"
#include "stationsortproxy.h"
#include "reservation.h"
#include "reservationfilterproxy.h"

#include <QDebug>

#define DEFAULT_PAGE Page_MainMenu


UserInterface::UserInterface(
    StationModel *smodel,
    VehiculeModel *vmodel,
    UsagerModel *umodel,
    ReservationModel *rmodel,
    QWidget *parent) :
    QMainWindow(parent),
    stationModel(smodel),
    vehiculeModel(vmodel),
    usagerModel(umodel),
    reservationModel(rmodel),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);

    pages = new QMap<PageName, Page*>;

    reservation = new Reservation(QDateTime::currentDateTime(), QDateTime::currentDateTime(), 0, 0, 0, this);
    currentPosition = new GeoPosition(0, 0);

    stationProxy = new StationSortProxy(this);
    stationProxy->setSourceModel(stationModel);
    stationProxy->setDynamicSortFilter(true);
    stationProxy->sort(1);

    vehiculeProxy = new VehiculeFilterProxy(rmodel, reservation, this);
    vehiculeProxy->setSourceModel(vehiculeModel);
    vehiculeProxy->setDynamicSortFilter(true);

    reservationProxy = new ReservationFilterProxy(this);
    qDebug() << "new ReservationFilterProxy done";
    reservationProxy->setSourceModel(reservationModel);
    reservationProxy->setDynamicSortFilter(true);
}

void UserInterface::createPages() {
    pages->clear();
    pages->insert(Page_MainMenu, new MainMenuPage(this));
    pages->insert(Page_FindStation, new FindStationPage(this));
    pages->insert(Page_SelectPosition, new SelectPositionPage(this));
    pages->insert(Page_SelectStation, new SelectStationPage(stationProxy, this));
    pages->insert(Page_SelectTime, new SelectTimePage(this));
    pages->insert(Page_SelectCar, new SelectCarPage(vehiculeProxy, this));
    pages->insert(Page_Confirm, new ConfirmPage(reservation,
                                                usagerModel,
                                                vehiculeModel,
                                                stationModel,
                                                this));
    pages->insert(Page_Bookings, new BookingsPage(reservationProxy,
                                                  this));
    pages->insert(Page_Comments, new CommentsPage(this));           // comments main page
    pages->insert(Page_WriteComment, new WriteCommentPage(this));   // comment editing
    pages->insert(Page_Unexpected, new UnexpectedPage(this));
    pages->insert(Page_Email, new MyMessagesPage(this));

    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        QWidget *w = ui->stackedWidget->widget(i);
        ui->stackedWidget->removeWidget(w);
    }

    QMapIterator<PageName, Page*> iter(*pages);
    while (iter.hasNext()) {
        iter.next();
        ui->stackedWidget->addWidget(iter.value());
    }

    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(getPage(DEFAULT_PAGE)));

    // Connections for email
    connect(ui->btnEnveloppe, SIGNAL(clicked()), this, SLOT(gotoEmailPage()));

    // Connections for main menu
    connect(getPage(Page_MainMenu), SIGNAL(BookCar()), this, SLOT(gotoFindStationPage()));
    connect(getPage(Page_MainMenu), SIGNAL(BookCar()), this, SLOT(resetReservation()));
    connect(getPage(Page_MainMenu), SIGNAL(ViewBookings()), this, SLOT(gotoBookings()));
    connect(getPage(Page_MainMenu), SIGNAL(LeaveComment()), this, SLOT(gotoCommentPage()));
    connect(getPage(Page_MainMenu), SIGNAL(ReportUnexpected()), this, SLOT(gotoUnexpected()));

    // Connections for find station
    connect(getPage(Page_FindStation), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_FindStation), SIGNAL(SelectPosition()), this, SLOT(gotoSelectPosition()));
    connect(getPage(Page_FindStation), SIGNAL(UseCurrentPosition()), this, SLOT(gotoSelectStation()));

    // Connections for select position
    connect(getPage(Page_SelectPosition), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectPosition), SIGNAL(Previous()), this, SLOT(gotoFindStationPage()));
    connect(getPage(Page_SelectPosition), SIGNAL(Next()), this, SLOT(gotoSelectStation()));
    connect(getPage(Page_SelectPosition), SIGNAL(positionSelected(GeoPosition)), this, SLOT(setCurrentPosition(GeoPosition)));
    connect(getPage(Page_SelectPosition), SIGNAL(positionSelected(GeoPosition)), stationModel, SLOT(updateCurrentPosition(GeoPosition)));
    connect(getPage(Page_SelectPosition), SIGNAL(positionSelected(GeoPosition)), stationProxy, SLOT(invalidate()));

    // Connections for select station
    connect(getPage(Page_SelectStation), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectStation), SIGNAL(Previous()), this, SLOT(gotoSelectPosition()));
    connect(getPage(Page_SelectStation), SIGNAL(Next()), this, SLOT(gotoSelectTime()));
    connect(getPage(Page_SelectStation), SIGNAL(showInfoStation(Station*)), this, SLOT(showInfoStation(Station*)));
    connect(getPage(Page_SelectStation), SIGNAL(selectedStation(qint64)), this, SLOT(setStationId(qint64)));
    connect(getPage(Page_SelectStation), SIGNAL(selectedStation(qint64)), vehiculeProxy, SLOT(invalidate()));

    // Connections for select time
    connect(getPage(Page_SelectTime), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectTime), SIGNAL(Previous()), this, SLOT(gotoSelectStation()));
    connect(getPage(Page_SelectTime), SIGNAL(Next()), this, SLOT(gotoSelectCar()));
    connect(getPage(Page_SelectTime), SIGNAL(selectedTime(QDateTime, QDateTime)), this, SLOT(setTimes(QDateTime, QDateTime)));
    connect(getPage(Page_SelectTime), SIGNAL(selectedTime(QDateTime, QDateTime)), vehiculeProxy, SLOT(invalidate()));

    // Connections for select car
    connect(getPage(Page_SelectCar), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_SelectCar), SIGNAL(Previous()), this, SLOT(gotoSelectTime()));
    connect(getPage(Page_SelectCar), SIGNAL(Next()), this, SLOT(gotoConfirm()));
    connect(getPage(Page_SelectCar), SIGNAL(carSelected(qint64)), this, SLOT(setCarId(qint64)));
    connect(getPage(Page_SelectCar), SIGNAL(Next()), getPage(Page_Confirm), SLOT(setEditorText()));

    // Connections for confirm
    connect(getPage(Page_Confirm), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_Confirm), SIGNAL(Previous()), this, SLOT(gotoSelectCar()));
    connect(getPage(Page_Confirm), SIGNAL(Confirm()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_Confirm), SIGNAL(Confirm()), this, SLOT(saveReservation()));


    // Connections for bookings
    connect(getPage(Page_Bookings), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_Bookings), SIGNAL(includePastRes(bool)), reservationProxy, SLOT(includePastRes(bool)));
    connect(getPage(Page_Bookings), SIGNAL(includeCurrentRes(bool)), reservationProxy, SLOT(includeCurrentRes(bool)));
    connect(getPage(Page_Bookings), SIGNAL(includeFuturRes(bool)), reservationProxy, SLOT(includeFuturRes(bool)));

    // Connections for comments
    connect(getPage(Page_Comments), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_Comments), SIGNAL(VehiculeComment()), this, SLOT(gotoWriteComment()));
    connect(getPage(Page_Comments), SIGNAL(StationComment()), this, SLOT(gotoWriteComment()));
    connect(getPage(Page_Comments), SIGNAL(ReservationComment()), this, SLOT(gotoWriteComment()));
    //connect(getPage(Page_Comments), SIGNAL(ToUserComment()), this, SLOT(gotoWriteComment()));

    // Connections for writecomment
    connect(getPage(Page_WriteComment), SIGNAL(Previous()), this, SLOT(gotoCommentPage()));
    connect(getPage(Page_WriteComment), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
    connect(getPage(Page_WriteComment), SIGNAL(Send()), this, SLOT(gotoMainMenu()));

    // Connections for unexpected
    connect(getPage(Page_Unexpected), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));

    // Connections for email
    connect(getPage(Page_Email), SIGNAL(Menu()), this, SLOT(gotoMainMenu()));
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::setUser(qint64 id) {
    user = usagerModel->getUsager(id);
    qDebug() << "active user identified";
    reservationProxy->setUser(user);
    qDebug() << "setUser done";
    createPages();
    qDebug() << "createPages done";
    *currentPosition = user->getPosition();
    stationModel->updateCurrentPosition(*currentPosition);
    ui->lblUserName->setText(user->getNom());
    stationProxy->invalidate();
    vehiculeProxy->invalidate();
}

Page* UserInterface::getPage(PageName name) {
    return pages->value(name);
}


void UserInterface::gotoPage(PageName name) {
    int i = ui->stackedWidget->indexOf(getPage(name));
    ui->stackedWidget->setCurrentIndex(i);
}


void UserInterface::gotoEmailPage() {
    gotoPage(Page_Email);
}

void UserInterface::gotoMainMenu() {
    gotoPage(Page_MainMenu);
}

void UserInterface::gotoFindStationPage() {
    gotoPage(Page_FindStation);
}

void UserInterface::gotoBookings() {
    gotoPage(Page_Bookings);
}

void UserInterface::gotoCommentPage() {
    gotoPage(Page_Comments);
}

void UserInterface::gotoWriteComment() {
    gotoPage(Page_WriteComment);
}

void UserInterface::gotoUnexpected() {
    gotoPage(Page_Unexpected);
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

void UserInterface::setCurrentPosition(GeoPosition pos) {
    currentPosition->setLat(pos.getLat());
    currentPosition->setLon(pos.getLon());
}

void UserInterface::showInfoStation(Station *station) {
    InfoStationPage *infoStationPage = new InfoStationPage(*station, this);
    ui->stackedWidget->addWidget(infoStationPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(infoStationPage));
    connect(infoStationPage, SIGNAL(Previous()), this, SLOT(gotoSelectStation()));
}

void UserInterface::setTimes(QDateTime start, QDateTime end) {
    reservation->setDebut(start);
    reservation->setFin(end);
}

void UserInterface::setStationId(qint64 stationId) {
    reservation->setStation(stationId);
}

void UserInterface::setCarId(qint64 carId) {
    reservation->setVehicule(carId);
}


void UserInterface::resetReservation() {
    reservation->setDebut(QDateTime::currentDateTime());
    reservation->setFin(QDateTime::currentDateTime());
    reservation->setStation(0);
    reservation->setVehicule(0);
    reservation->setUsager(user->getId());
}


void UserInterface::saveReservation() {
    reservationModel->addReservation(reservation);
}
