#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>


class Page : public QWidget
{
    Q_OBJECT
public:
    explicit Page(QWidget *parent = 0);

protected:
    void addWidget(QWidget *widget);
    void addBottomButtons(QPushButton *left, QPushButton *middle, QPushButton *right);
    void addTitle(QString s);

signals:

public slots:

private:
    QVBoxLayout *layout;

};

#endif // PAGE_H
