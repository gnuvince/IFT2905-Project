#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>

class StationModel;
class NoteModel;
class VehiculeModel;
class ReservationModel;
class ReservationProxyModel;
class UsagerModel;
class Simulateur;
class Robot;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setupTables();

public slots:
    void updateTime(const QDateTime &date);
    void applyFilter();
    void updateDebutTimeEdit();
    void updateFinTimeEdit();
    void changeInterfaceUsager();
    void changeInterfaceUsagerId(qint64 id);

    void save();
    void open();

signals:
    void interfaceUsagerId(qint64 id);

private:
    Ui::MainWindow *ui;
    UsagerModel *umodel;
    NoteModel *nmodel;
    StationModel *smodel;
    VehiculeModel *vmodel;
    ReservationModel *rmodel;
    ReservationProxyModel *rproxy;
    Simulateur *simul;
        Robot *robot;
};

#endif // MAINWINDOW_H
