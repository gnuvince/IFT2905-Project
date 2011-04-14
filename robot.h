#ifndef ROBOT_H
#define ROBOT_H

#include <QDateTime>
#include <QObject>


class ReservationModel;
class UsagerModel;
class StationModel;
class NoteModel;
class VehiculeModel;

class ReservationProxyModel;

class Usager;


class Robot : public QObject
{
    Q_OBJECT
public:
    explicit Robot(ReservationModel* rmodel,VehiculeModel* vmodel,StationModel* smodel,UsagerModel* umodel,NoteModel* nmodel,QObject *parent = 0);

    void simulInitialise(QDateTime now);
    bool tenteUneReservation(QDateTime debut,QDateTime fin,qint64 v,qint64 sDepart,qint64 sRetour);
    bool tentePlusieursReservations(QDateTime debut,QDateTime fin,qint64 v,qint64 sDepart,qint64 sRetour, int nb);

    void ajouteReservationAuHasard(QDateTime now);
    void ajouteNotePersonnelleAuHasard(QDateTime now);

signals:

public slots:
    void updateTime(QDateTime now);


private:
    QDateTime last; // derniere fois qu'on a recu un updateTime()
    // les modeles pour faire plein d'operations
    ReservationModel *rmodel;
    VehiculeModel* vmodel;
    StationModel* smodel;
    UsagerModel* umodel;
    NoteModel* nmodel;

    Usager* admin;
    ReservationProxyModel* proxy;

};

#endif // ROBOT_H
