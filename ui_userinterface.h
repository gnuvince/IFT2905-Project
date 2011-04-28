/********************************************************************************
** Form generated from reading UI file 'userinterface.ui'
**
** Created: Thu Apr 28 13:27:40 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEnveloppe;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblUserName;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QString::fromUtf8("UserInterface"));
        UserInterface->resize(330, 400);
        centralwidget = new QWidget(UserInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnEnveloppe = new QPushButton(centralwidget);
        btnEnveloppe->setObjectName(QString::fromUtf8("btnEnveloppe"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/data/icons/email.png"), QSize(), QIcon::Normal, QIcon::On);
        btnEnveloppe->setIcon(icon);
        btnEnveloppe->setFlat(true);

        horizontalLayout->addWidget(btnEnveloppe);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lblUserName = new QLabel(centralwidget);
        lblUserName->setObjectName(QString::fromUtf8("lblUserName"));

        horizontalLayout->addWidget(lblUserName);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setStyleSheet(QString::fromUtf8("border: 1px solid #000000;"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        UserInterface->setCentralWidget(centralwidget);

        retranslateUi(UserInterface);

        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterface)
    {
        UserInterface->setWindowTitle(QApplication::translate("UserInterface", "Auto-Partage", 0, QApplication::UnicodeUTF8));
        btnEnveloppe->setText(QString());
        label_2->setText(QApplication::translate("UserInterface", "Auto-Partage", 0, QApplication::UnicodeUTF8));
        lblUserName->setText(QApplication::translate("UserInterface", "Tania", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
