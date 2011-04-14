/********************************************************************************
** Form generated from reading UI file 'cartewidget.ui'
**
** Created: Thu Apr 14 11:33:52 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTEWIDGET_H
#define UI_CARTEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarteWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_3;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *CarteWidget)
    {
        if (CarteWidget->objectName().isEmpty())
            CarteWidget->setObjectName(QString::fromUtf8("CarteWidget"));
        CarteWidget->resize(280, 251);
        verticalLayout = new QVBoxLayout(CarteWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_2 = new QToolButton(CarteWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/data/images/icons/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);

        horizontalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(CarteWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/data/images/icons/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);

        horizontalLayout->addWidget(toolButton);

        comboBox = new QComboBox(CarteWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_3 = new QToolButton(CarteWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icones/data/images/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);

        horizontalLayout->addWidget(toolButton_3);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(CarteWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(CarteWidget);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CarteWidget);
    } // setupUi

    void retranslateUi(QWidget *CarteWidget)
    {
        CarteWidget->setWindowTitle(QApplication::translate("CarteWidget", "Form", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QString());
        toolButton->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CarteWidget", "50%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CarteWidget", "100%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CarteWidget", "200%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CarteWidget", "400%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CarteWidget", "800%", 0, QApplication::UnicodeUTF8)
        );
        toolButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CarteWidget: public Ui_CarteWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTEWIDGET_H
