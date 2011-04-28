#include <QtGui>
#include <QTableView>

#include "page.h"
#include "writecommentpage.h"

WriteCommentPage::WriteCommentPage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Écrire un commentaire"));

    QWidget *subjectsWidget = new QWidget(this);
    QHBoxLayout *subjectLayout = new QHBoxLayout(this);
    QLabel *subjectLabel = new QLabel("Sujet:");
    QComboBox *type = new QComboBox(this);
    type->addItem(trUtf8("Véhicule"));
    type->addItem(trUtf8("Station"));
    //type->addItem(trUtf8("Réservation"));
    subjectLayout->addWidget(subjectLabel);
    subjectLayout->addWidget(type);
    subjectsWidget->setLayout(subjectLayout);
    addWidget(subjectsWidget);

    QWidget *commentWidget = new QWidget(this);
    QHBoxLayout *commentLayout = new QHBoxLayout(this);
    QLabel *commentLabel = new QLabel("Commentaire:");
    QTextEdit *comment = new QTextEdit(this);
    commentLayout->addWidget(commentLabel);
    commentLayout->addWidget(comment);
    commentWidget->setLayout(commentLayout);
    addWidget(commentWidget);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    QPushButton *btnSend = new QPushButton(trUtf8("Envoyer"), this);
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(btnPrevious, btnMenu, btnSend);

    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnSend, SIGNAL(clicked()), SIGNAL(Send()));
}
