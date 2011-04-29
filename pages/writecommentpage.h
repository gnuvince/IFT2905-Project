#ifndef WRITECOMMENTPAGE_H
#define WRITECOMMENTPAGE_H

#include <QtGui>

#include "page.h"
#include "stationmodel.h"
#include "vehiculemodel.h"
#include "reservationmodel.h"
#include "notemodel.h"

class WriteCommentPage : public Page
{
    Q_OBJECT
public:
    explicit WriteCommentPage(qint64 uid, NoteModel *nmodel, ReservationModel *rmodel, StationModel *smodel, VehiculeModel *vmodel, QWidget *parent = 0);

private:
    StationModel *stationModel;
    VehiculeModel *vehiculeModel;
    ReservationModel *reservationModel;
    NoteModel *noteModel;
    QComboBox *subject;
    QComboBox *type;
    QPushButton *btnSend;
    QTextEdit *comment;
    qint64 userId;

signals:
    void Previous();
    void Menu();
    void Send();

public slots:
    void updateSubjects(int x=0);
    void addNote();
    void enableSend();

};

#endif // WRITECOMMENTPAGE_H
