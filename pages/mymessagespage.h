#ifndef MYMESSAGESPAGE_H
#define MYMESSAGESPAGE_H

#include <QtGui>

#include "page.h"
#include "notemodel.h"

class MyMessagesPage : public Page
{
    Q_OBJECT
public:
    explicit MyMessagesPage(qint64 uid, NoteModel *nmodel, QWidget *parent = 0);

private:
    qint64 uid;
    NoteModel *noteModel;
    QTextEdit *msgtext;

signals:

public slots:
    void updateMessages();

};

#endif // MYMESSAGESPAGE_H
