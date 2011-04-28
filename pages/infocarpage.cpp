#include <QtGui>

#include "infocarpage.h"
#include "vehicule.h"
#include "note.h"
#include "notemodel.h"

QLabel* InfoCarPage::titleLabel(QString title) {
    QLabel *label = new QLabel(title);
    QFont font = label->font();
    font.setPointSize(8);
    font.setBold(true);
    label->setFont(font);
    return label;
}

InfoCarPage::InfoCarPage(Vehicule &vehicule, NoteModel &noteModel, QWidget *parent) :
    Page(parent),
    vehicule(vehicule)
{
    addTitle(trUtf8("Info-Véhicule"));

    QVBoxLayout *layout = new QVBoxLayout(this);

    QString vehiculeName = QString("%1 %2").arg(vehicule.getMarque()).arg(vehicule.getModele());
    QLabel *nameLabel = new QLabel(vehiculeName, this);

    QFont normalFont = nameLabel->font();
    normalFont.setPointSize(8);

    nameLabel->setWordWrap(true);

    QLabel *descriptionLabel = new QLabel(vehicule.getDescription(), this);
    descriptionLabel->setFont(normalFont);
    descriptionLabel->setWordWrap(true);


    QPixmap photo = vehicule.getPhoto().scaled(QSize(220, 1), Qt::KeepAspectRatioByExpanding);
    QLabel *photoLabel = new QLabel();
    photoLabel->setPixmap(photo);

    QPlainTextEdit *comments = new QPlainTextEdit(this);
    QString commentsString;
    foreach (Note* note, noteModel.getNotes()) {
        if (note->getType() == Note::TYPE_VEHICULE && note->getDestinataire() == vehicule.getId()) {
            commentsString.append(QString("%1:\n%2\n\n").arg(note->getDate().toString("dd MMM yyyy")).arg(note->getDescription()));
        }
    }
    comments->setPlainText(commentsString);
    comments->setReadOnly(true);

    layout->addWidget(nameLabel);
    layout->addWidget(titleLabel(trUtf8("Description:")));
    layout->addWidget(descriptionLabel);
    layout->addWidget(titleLabel(trUtf8("Photo:")));
    layout->addWidget(photoLabel);
    layout->addWidget(titleLabel(trUtf8("Commentaires:")));
    layout->addWidget(comments);

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
