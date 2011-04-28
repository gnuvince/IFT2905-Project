#include <QtGui>
#include <QTableView>
#include <QModelIndex>

#include "page.h"
#include "bookingspage.h"
#include "reservationfilterproxy.h"


BookingsPage::BookingsPage(
        ReservationFilterProxy *rproxy,
        QWidget *parent) :
        Page(parent),
        reservationProxy(rproxy)
{
    addTitle(trUtf8("Mes réservations"));

    QTableView *bookings = new QTableView(this);
    bookings->setModel(reservationProxy);
    bookings->setSelectionBehavior(QAbstractItemView::SelectRows);
    bookings->setSelectionMode(QAbstractItemView::SingleSelection);
    bookings->verticalHeader()->hide();
    bookings->hideColumn(0);
    bookings->resizeColumnToContents(2);
    bookings->resizeColumnToContents(3);
    bookings->resizeColumnToContents(4);
    bookings->resizeColumnToContents(5);
    bookings->resizeColumnToContents(6);
    bookings->resizeRowsToContents();
    bookings->setAlternatingRowColors(true);
    addWidget(bookings);

    QFont font = bookings->font();
    font.setPointSize(8);
    bookings->setFont(font);

    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    QWidget *optionsWidget = new QWidget(this);
    QHBoxLayout *options = new QHBoxLayout(this);
    QCheckBox *past = new QCheckBox(trUtf8("Passées"), this);
    QCheckBox *current = new QCheckBox(trUtf8("Courantes"), this);
    QCheckBox *futur = new QCheckBox(trUtf8("Futures"), this);

    emit past->setChecked(true);
    emit current->setChecked(true);
    emit futur->setChecked(true);

    options->addWidget(past);
    options->addWidget(current);
    options->addWidget(futur);
    optionsWidget->setLayout(options);
    addWidget(optionsWidget);

    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(past, SIGNAL(clicked(bool)), SIGNAL(includePastRes(bool)));
    connect(current, SIGNAL(clicked(bool)), SIGNAL(includeCurrentRes(bool)));
    connect(futur, SIGNAL(clicked(bool)), SIGNAL(includeFuturRes(bool)));
}
