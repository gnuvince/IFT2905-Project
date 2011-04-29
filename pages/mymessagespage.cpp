#include <QtGui>
#include <QTableView>

#include "page.h"
#include "mymessagespage.h"
#include "note.h"

MyMessagesPage::MyMessagesPage(qint64 uid, NoteModel *nmodel, QWidget *parent) :
    Page(parent),
    uid(uid),
    noteModel(nmodel)
{
    addTitle(trUtf8("Mes messages"));

    msgtext = new QTextEdit(this);
    msgtext->setFont(QFont("Courier"));
    addWidget(msgtext);

    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);

    addBottomButtons(0, btnMenu, 0);

    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
}

void MyMessagesPage::updateMessages() {
    msgtext->clear();

    QString s;
    foreach (Note* n, noteModel->getNotes()) {
        if (n->getUsager() == uid) {
            s.append(n->getDescription());
            s.append("\n\n");
        }
    }
    msgtext->setPlainText(s);
}
