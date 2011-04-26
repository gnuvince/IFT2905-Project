#include <QtGui>

#include "page.h"
#include "station.h"
#include "infostationpage.h"


QLabel* titleLabel(QString title) {
    QLabel *label = new QLabel(title);
    QFont font = label->font();
    font.setPointSize(8);
    font.setBold(true);
    label->setFont(font);
    return label;
}

InfoStationPage::InfoStationPage(Station &station, QWidget *parent) :
    Page(parent),
    station(station)
{
    addTitle(trUtf8("Info-Station"));

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *nameLabel = new QLabel(station.getNom(), this);

    QFont normalFont = nameLabel->font();
    normalFont.setPointSize(8);

    nameLabel->setWordWrap(true);

    QLabel *descriptionLabel = new QLabel(station.getDescription(), this);
    descriptionLabel->setFont(normalFont);
    descriptionLabel->setWordWrap(true);

    QLabel *coffretLabel = new QLabel(station.getCoffret());
    coffretLabel->setFont(normalFont);
    coffretLabel->setWordWrap(true);

    QPixmap photo = station.getPhoto().scaled(QSize(220, 1), Qt::KeepAspectRatioByExpanding);
    QLabel *photoLabel = new QLabel();
    photoLabel->setPixmap(photo);

    QPixmap map = station.getCarte().scaled(QSize(220, 1), Qt::KeepAspectRatioByExpanding);;
    QLabel *mapLabel = new QLabel();
    mapLabel->setPixmap(map);

    layout->addWidget(nameLabel);
    layout->addWidget(titleLabel(trUtf8("Description:")));
    layout->addWidget(descriptionLabel);
    layout->addWidget(titleLabel(trUtf8("Coffret:")));
    layout->addWidget(coffretLabel);
    layout->addWidget(titleLabel(trUtf8("Photo:")));
    layout->addWidget(photoLabel);
    layout->addWidget(titleLabel(trUtf8("Carte:")));
    layout->addWidget(mapLabel);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);

    QScrollArea *scroller = new QScrollArea(this);
    scroller->setWidget(widget);

    addWidget(scroller);

    QPushButton *returnButton = new QPushButton(trUtf8("Retour"));
    returnButton->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));

    addBottomButtons(0, returnButton, 0);

    connect(returnButton, SIGNAL(clicked()), SIGNAL(Previous()));
}
