#ifndef SELECTTIMEPAGE_H
#define SELECTTIMEPAGE_H

#include <QtGui>

#include "page.h"

class SelectTimePage : public Page
{
    Q_OBJECT
public:
    explicit SelectTimePage(QWidget *parent = 0);

signals:
    void selectedTime(QDateTime start, QDateTime end);

public slots:
    void setMinimalEndDateTime(QDateTime time);
    void emitDates();

private:
    QDateTimeEdit *startTime;
    QDateTimeEdit *endTime;

};

#endif // SELECTTIMEPAGE_H
