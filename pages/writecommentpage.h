#ifndef WRITECOMMENTPAGE_H
#define WRITECOMMENTPAGE_H

#include <QtGui>

#include "page.h"

class WriteCommentPage : public Page
{
    Q_OBJECT
public:
    explicit WriteCommentPage(QWidget *parent = 0);

signals:
    void Previous();
    void Menu();
    void Send();

public slots:

};

#endif // WRITECOMMENTPAGE_H
