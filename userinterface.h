#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QtGui>
#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>

#include "pages/page.h"
#include "station.h"
#include "stationmodel.h"
#include "stationsortproxy.h"
#include "geoposition.h"

enum PageName { Page_MainMenu,
                Page_FindStation, Page_SelectPosition, Page_SelectStation, Page_SelectTime, Page_SelectCar, Page_Confirm,
                Page_Bookings, Page_Comments, Page_Unexpected, Page_Email, Page_WriteComment
              };

namespace Ui {
    class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(
        StationModel *smodel,
        QWidget *parent = 0);
    ~UserInterface();

private:
    Ui::UserInterface *ui;
    QMap<PageName, Page*> *pages;
    Page* getPage(PageName name);
    StationModel *stationModel;
    GeoPosition *currentPosition;
    StationSortProxy *stationProxy;

public slots:
    void gotoPage(PageName name);
    void gotoMainMenu();
    void gotoFindStationPage();
    void gotoSelectPosition();
    void gotoSelectStation();
    void gotoSelectTime();
    void gotoSelectCar();
    void gotoConfirm();
    void gotoCommentPage();
    void gotoUnexpected();
    void gotoBookings();
    void gotoEmailPage();
    void setCurrentPosition(GeoPosition pos);
    void gotoWriteComment();
};

#endif // USERINTERFACE_H
