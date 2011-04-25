#include <QtGui>
#include <QTableView>

#include "page.h"
#include "bookingspage.h"

BookingsPage::BookingsPage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Mes réservations"));

    QTableView *bookings = new QTableView(this);
    addWidget(bookings);

    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    QWidget *optionsWidget = new QWidget(this);
    QHBoxLayout *options = new QHBoxLayout(this);
    QCheckBox *past = new QCheckBox(trUtf8("Passées"), this);
    QCheckBox *current = new QCheckBox(trUtf8("Courantes"), this);
    QCheckBox *futur = new QCheckBox(trUtf8("Futures"), this);
    options->addWidget(past);
    options->addWidget(current);
    options->addWidget(futur);
    optionsWidget->setLayout(options);
    addWidget(optionsWidget);

    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
}
