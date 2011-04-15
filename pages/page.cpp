#include "page.h"

#include <QtGui>

Page::Page(QWidget *parent) :
    QWidget(parent),
    layout(new QVBoxLayout)
{
    setLayout(layout);
}

void Page::addWidget(QWidget *widget) {
    layout->addWidget(widget);
}

void Page::addTitle(QString s) {
    QLabel *label = new QLabel(s);
    label->setAlignment(Qt::AlignCenter);
    QFont font = label->font();
    font.setPointSize(12);
    label->setFont(font);
    addWidget(label);
}

void Page::addBottomButtons(QPushButton *left, QPushButton *middle, QPushButton *right) {
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    if (left != 0)
        bottomLayout->addWidget(left);
    bottomLayout->addStretch();

    bottomLayout->addWidget(middle);

    bottomLayout->addStretch();
    if (right!= 0)
        bottomLayout->addWidget(right);

    QWidget *widget = new QWidget;
    widget->setLayout(bottomLayout);
    layout->addStretch();
    addWidget(widget);
}
