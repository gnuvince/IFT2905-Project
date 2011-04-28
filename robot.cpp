
#include "robot.h"

#include "reservationmodel.h"
#include "usagermodel.h"
#include "stationmodel.h"
#include "notemodel.h"
#include "vehiculemodel.h"
#include "reservationproxymodel.h"


#include <QDebug>
#include <QtCore>
#include <cstdlib>

Robot::Robot(ReservationModel* rmodel,VehiculeModel* vmodel,StationModel* smodel,
             UsagerModel* umodel,NoteModel *nmodel,QObject *parent) :
    rmodel(rmodel),
    vmodel(vmodel),
    smodel(smodel),
    umodel(umodel),
    nmodel(nmodel),
    QObject(parent)
{
    proxy=new ReservationProxyModel(this);
    proxy->setSourceModel(rmodel);
    //on ne le met pas dynamique parce qu'on a pas besoin qu'il s'auto-update
    //le proxy n'a besoin d'être en mode dynamique que lorsqu'il est associé à une vue
    //et qu'on veut un filtrage dynamique. ici on n'a juste besoin des résultats
    //on appelle getFilteredReservations quand on a besoin d'un résultat à jour
}


//
// Ajoute une reservation au hasard
// entre les dates A et B
// pour un vehicule specifique v (peut etre -1 si n'importe quel)
// la station de depart peut etre donnee (-1 si n'importe quelle station)
// La station de retour peut etre donnee. Sinon, retour-depart.
//
bool Robot::tenteUneReservation(QDateTime debut,QDateTime fin,qint64 vId,qint64 sIdDepart,qint64 sIdRetour)
{
    ReservationProxyModel::Options opt;

    if( vId>=0 && vmodel->getVehicule(vId)==0 ) return false; // ID vehicule illegal
    if( sIdDepart>=0 && smodel->getStation(sIdDepart)==0 ) return false; // ID station illegal
    if( sIdRetour>=0 && smodel->getStation(sIdRetour)==0 ) return false; // ID station illegal

    // on veut savoir ce qui est disponible (selon v et sDepart)

    opt=ReservationProxyModel::Passe
         |ReservationProxyModel::PlusProche;
    proxy->setFilterFields(debut,fin,vId,sIdDepart,opt);

    // extrait les reservations
    QList<Reservation*> disponibles = proxy->getFilteredReservations();

    if( disponibles.count()==0 ) {
        //qDebug()<<"Aucun vehicule disponible! (pas de vehicule du tout)";
        return false;
    }

    // verification de l'intervalle (actif)
    // toute reservation ici indique que c'est pas disponible...
    opt=ReservationProxyModel::Actif;
    proxy->setFilterFields(debut,fin,vId,sIdDepart,opt);

    QList<Reservation*> actifs = proxy->getFilteredReservations();

    foreach(Reservation* r,disponibles) {
        bool found=false;
        foreach(Reservation* x,actifs) {
            if( x->getVehicule() == r->getVehicule() ) { found=true;break;}
        }
        if( !found ) {
               // ajoute la reservation!!!
            if( sIdRetour<0 ) sIdRetour=r->getStation();
            vId=r->getVehicule();
            rmodel->addReservation(new Reservation(debut,fin,vId,admin->getId(),sIdRetour,rmodel));
            return true;
        }
    }

    return false;
}


//
// Ajoute une reservation au hasard
// entre les dates A et B
// pour un vehicule specifique v (peut etre -1 si n'importe quel)
// la station de depart peut etre donnee (-1 si n'importe quelle station)
// La station de retour peut etre donnee. Sinon, retour-depart.
//
bool Robot::tentePlusieursReservations(QDateTime debut,QDateTime fin,qint64 vId,qint64 sIdDepart,qint64 sIdRetour, int nb)
{
    ReservationProxyModel::Options opt;

    if( vId>=0 && vmodel->getVehicule(vId)==0 ) return false; // ID vehicule illegal
    if( sIdDepart>=0 && smodel->getStation(sIdDepart)==0 ) return false; // ID station illegal
    if( sIdRetour>=0 && smodel->getStation(sIdRetour)==0 ) return false; // ID station illegal

    // on veut savoir ce qui est disponible (selon v et sDepart)
    opt=ReservationProxyModel::Passe
         |ReservationProxyModel::PlusProche;
    proxy->setFilterFields(debut,fin,vId,sIdDepart,opt);

    // extrait les reservations
    QList<Reservation*> disponibles = proxy->getFilteredReservations();

    if( disponibles.count()==0 ) {
        return false;
    }


    // verification de l'intervalle (actif)
    // toute reservation ici indique que c'est pas disponible...
    opt=ReservationProxyModel::Actif;
    proxy->setFilterFields(debut,fin,vId,sIdDepart,opt);

    QList<Reservation*> actifs = proxy->getFilteredReservations();
    QList< QPair<qint64,qint64> > res;

    foreach(Reservation* r,disponibles) {
        bool found=false;
        foreach(Reservation* x,actifs) {
            if( x->getVehicule() == r->getVehicule() ) { found=true;break;}
        }
        if( !found ) {
               // ajoute la reservation!!!
            if( sIdRetour<0 ) sIdRetour=r->getStation();
            vId=r->getVehicule();
            res.append(qMakePair(vId, sIdRetour));
        }
    }

    QList<Reservation*> fRes;
    for (int i=0; i<qMin(nb, res.count()); ++i)
        fRes.append(new Reservation(debut, fin, res[i].first, admin->getId(), res[i].second, rmodel));

    rmodel->addReservations(fRes);

    return true;
}



//
// simulation initiale.
//
// creation de reservations de départ:
//   - pour chaque voiture on choisi une station.
//
void Robot::simulInitialise(QDateTime now)
{
    // affiche la liste des chars
    QList<Vehicule*> vehicules = vmodel->getVehicules();
    QList<Usager*> usagers = umodel->getUsagers();
    QList<Station*> stations = smodel->getStations();
    QList<Note*> notes = nmodel->getNotes();
    QList<Reservation*> reservations = rmodel->getReservations();

    //
    // usagers: l'usager 0 est un administrateur qui fait les reservations de depart
    //
    admin=new Usager(trUtf8("Admin"),GeoPosition(10.5,45.3),umodel);
    umodel->addUsager(admin);
    umodel->addUsager(new Usager(trUtf8("Sébastien"),GeoPosition(25.1,41.9),umodel));
    umodel->addUsager(new Usager(trUtf8("Nicolas"),GeoPosition(15.1,42.9),umodel));
    umodel->addUsager(new Usager(trUtf8("Maria"),GeoPosition(34.8,49.1),umodel));
    umodel->addUsager(new Usager(trUtf8("Vincent"),GeoPosition(45.301944, -74.303889),umodel));
    umodel->addUsager(new Usager(trUtf8("Eric"),GeoPosition(45.525, -73.877),umodel));

    nmodel->addNote(new Note(4, QDateTime::currentDateTime(), Note::TYPE_STATION, 2, tr("Place noire et dangeureuse!!!"), this));


    //
    // chaque voiture se fait associer a une station
    // reservation instantanee, dans le passe (now-1jour)
    //
    QList<Reservation*> iRes;


    QDateTime hier=now.addDays(-1);
    Station* s;
    foreach(Vehicule* v,vehicules) {
        // choisi une station au hasard
        s=stations[qrand()%stations.count()];
        iRes.append(new Reservation(hier,hier,v->getId(),admin->getId(),s->getId(),rmodel));
    }

    //c'est beaucoup plus efficace d'appeler addReservations() que addReservation() plusieurs fois
    //c'est d'autant plus efficace si le proxy est en mode dynamique ...
    //en mode dynamique appeler n fois addReservation prend n fois plus de temps ...
    rmodel->addReservations(iRes);

    tentePlusieursReservations(now.addSecs(3600), now.addSecs(5400),-1,-1,-1,50);
}

//
// tente une reservation au hasard dans une heure et pour
//
void Robot::ajouteReservationAuHasard(QDateTime now)
{
    tenteUneReservation(now.addSecs(3600),now.addSecs(25000),-1,-1,-1);
}

//
// ajoute une note d'une personne vers une autre, au hasard.
//
void Robot::ajouteNotePersonnelleAuHasard(QDateTime now)
{
    // choisi deux personnes au hasard
    QList<Usager*> usagers=umodel->getUsagers();

    Usager *from=usagers[qrand()%usagers.count()];
    Usager *to=usagers[qrand()%usagers.count()];

    QString msg=QString(trUtf8("L'usager %1 dit bonjour à l'usager %2.")).arg(from->getNom()).arg(to->getNom());

    nmodel->addNote(new Note(from->getId(),now,Note::TYPE_USAGER,to->getId(),msg,nmodel));
}


void Robot::updateTime(QDateTime now)
{
    int i;
    int nb;
    double p,prob;
    if( !last.isValid() ) {
        simulInitialise(now);
        last=now;
    }

    // le delta temps est en secondes
    // en bas de 1 seconde, on ne genere aucun evenement.
    double delta=last.msecsTo(now)/1000.0;

    //
    // ajoute de reservations au hasard
    //
    prob=10/60.0;  // 10 reservations par minute, remis en secondes
    for(i=0,nb=0;i<delta;i++) {
        if( qrand() < prob*RAND_MAX ) { ajouteReservationAuHasard(now.addSecs(i));nb++; }
        if( (nb+1)%10==0 ) qApp->processEvents();
        if( nb>10 ) break;
    }
    qDebug() << "robot genere"<<nb<<"ajouteReservationAuHasard";

    //
    // Envoi d'une note d'un usager à un autre
    //
    prob=3/60.0;
    for(i=0,nb=0;i<delta;i++) {
        if( qrand() < prob*RAND_MAX ) { ajouteNotePersonnelleAuHasard(now.addSecs(delta*i/nb));nb++; }
        if( (nb+1)%10==0 ) qApp->processEvents();
        if( nb>10 ) break;
    }
    qDebug() << "robot genere"<<nb<<"ajouteNotePersonnelleAuHasard";

    // a la fin... se rappeller de l'heure
    last=now;
}
