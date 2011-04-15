#include <QtGui>

#include "page.h"
#include "confirmpage.h"

ConfirmPage::ConfirmPage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Confirmer la réservation"));

    QPlainTextEdit *editor = new QPlainTextEdit(this);
    addWidget(editor);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    QPushButton *btnConfirm= new QPushButton(trUtf8("Confirmer"), this);
    btnConfirm->setIcon(QIcon(":/icones/data/icons/tick.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(btnPrevious, btnMenu, btnConfirm);

    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnConfirm, SIGNAL(clicked()), SIGNAL(Confirm()));
}
