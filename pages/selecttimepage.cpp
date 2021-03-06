#include <QtGui>
#include <QDateTimeEdit>

#include "page.h"
#include "selecttimepage.h"

#define TIME_FORMAT "dd MMM yyyy hh:mm"

SelectTimePage::SelectTimePage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Choisir la date et l'heure\n(4 / 5)"));

    QHBoxLayout *startLayout = new QHBoxLayout(this);
    QHBoxLayout *endLayout = new QHBoxLayout(this);

    startTime = new QDateTimeEdit(this);
    endTime = new QDateTimeEdit(this);

    startTime->setDisplayFormat(QString(TIME_FORMAT));
    endTime->setDisplayFormat(QString(TIME_FORMAT));


    QDateTime today;
    today = QDateTime::currentDateTime();
    QTime now = today.time();
    now.setHMS(now.hour()+1, 0, 0);
    today.setTime(now);

    startLayout->addWidget(new QLabel(trUtf8("Départ:"), this));
    startLayout->addWidget(startTime);

    endLayout->addWidget(new QLabel(trUtf8("Retour:"), this));
    endLayout->addWidget(endTime);

    QWidget *startWidget = new QWidget(this);
    QWidget *endWidget = new QWidget(this);

    startWidget->setLayout(startLayout);
    endWidget->setLayout(endLayout);

    addWidget(startWidget);
    addWidget(endWidget);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    QPushButton *btnNext = new QPushButton(this);
    btnNext->setIcon(QIcon(":/icones/data/icons/arrow_right.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(btnPrevious, btnMenu, btnNext);

    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnNext, SIGNAL(clicked()), SIGNAL(Next()));
    connect(btnNext, SIGNAL(clicked()), this, SLOT(emitDates()));

    // Connections for time selectors
    startTime->setMinimumDateTime(today);
    startTime->setMaximumDateTime(today.addMonths(3));
    connect(startTime, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(setMinimalEndDateTime(QDateTime)));
    emit setMinimalEndDateTime(today);
}

void SelectTimePage::setMinimalEndDateTime(QDateTime time) {
    QDateTime oneHourLater = time.addSecs(60 * 60);
    QDateTime threeDaysLater = time.addDays(3);
    endTime->setMinimumDateTime(oneHourLater);
    endTime->setMaximumDateTime(threeDaysLater);
}


void SelectTimePage::emitDates() {
    emit selectedTime(startTime->dateTime(), endTime->dateTime());
}
