#include <QtGui>
#include <QTableView>

#include "page.h"
#include "mymessagespage.h"

MyMessagesPage::MyMessagesPage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Mes messages"));

    QTableView *messages = new QTableView(this);
    addWidget(messages);
    QTextEdit *msgtext = new QTextEdit(this);
    addWidget(msgtext);

    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
}
