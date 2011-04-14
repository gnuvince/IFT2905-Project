#include "page.h"

#include <QDebug>

Page::Page(QWidget *parent) :
    QWidget(parent),
    layout(new QVBoxLayout)
{
    setLayout(layout);
}

void Page::addWidget(QWidget *widget) {
    layout->addWidget(widget);
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
    addWidget(widget);
}
