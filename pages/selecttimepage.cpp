#include <QtGui>
#include <QDateTimeEdit>

#include "page.h"
#include "selecttimepage.h"

SelectTimePage::SelectTimePage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Choisir la date et l'heure\n(4 / 5)"));

    QHBoxLayout *startLayout = new QHBoxLayout(this);
    QHBoxLayout *endLayout = new QHBoxLayout(this);

    QDateTimeEdit *startTime = new QDateTimeEdit(this);
    QDateTimeEdit *endTime = new QDateTimeEdit(this);

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
}
