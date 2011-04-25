#ifndef COMMENTSPAGE_H
#define COMMENTSPAGE_H

#include <QtGui>
#include "page.h"

class CommentsPage : public Page
{
    Q_OBJECT

public:
    explicit CommentsPage(QWidget *parent = 0);

public slots:

signals:
    void VehiculeComment();
    void StationComment();
    void ReservationComment();
    void ToUserComment();
};

#endif // COMMENTSPAGE_H
