/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 14 11:33:52 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Enregistrer;
    QAction *action_Ouvrir;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *labelHeure;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *scaleBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *usagerBox;
    QPushButton *usagerBut;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *intervalleBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *passeBox;
    QCheckBox *actifBox;
    QCheckBox *futurBox;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *inverseBox;
    QCheckBox *procheBox;
    QCheckBox *ignoreBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QDateTimeEdit *debutTEdit;
    QPushButton *dMtntBut;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QDateTimeEdit *finTEdit;
    QPushButton *eMtntBut;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *vehiculeBox;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *vEdit;
    QCheckBox *vInverseBox;
    QGroupBox *stationBox;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *sEdit;
    QCheckBox *sInverseBox;
    QVBoxLayout *verticalLayout_5;
    QPushButton *applyBut;
    QTableView *tableView_3;
    QTableView *tableView_4;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_9;
    QTableView *tableView_5;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_8;
    QTableView *tableView_6;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(695, 776);
        action_Enregistrer = new QAction(MainWindow);
        action_Enregistrer->setObjectName(QString::fromUtf8("action_Enregistrer"));
        action_Ouvrir = new QAction(MainWindow);
        action_Ouvrir->setObjectName(QString::fromUtf8("action_Ouvrir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        labelHeure = new QLabel(centralWidget);
        labelHeure->setObjectName(QString::fromUtf8("labelHeure"));
        labelHeure->setFrameShape(QFrame::Box);
        labelHeure->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(labelHeure);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        scaleBox = new QComboBox(centralWidget);
        scaleBox->setObjectName(QString::fromUtf8("scaleBox"));

        horizontalLayout_3->addWidget(scaleBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        usagerBox = new QComboBox(centralWidget);
        usagerBox->setObjectName(QString::fromUtf8("usagerBox"));
        usagerBox->setEditable(false);

        horizontalLayout_3->addWidget(usagerBox);

        usagerBut = new QPushButton(centralWidget);
        usagerBut->setObjectName(QString::fromUtf8("usagerBut"));

        horizontalLayout_3->addWidget(usagerBut);


        verticalLayout->addLayout(horizontalLayout_3);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayout_2 = new QVBoxLayout(tab_1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(tab_1);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableView);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setAlternatingRowColors(true);
        tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_2->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);

        verticalLayout_3->addWidget(tableView_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        intervalleBox = new QGroupBox(tab_3);
        intervalleBox->setObjectName(QString::fromUtf8("intervalleBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(intervalleBox->sizePolicy().hasHeightForWidth());
        intervalleBox->setSizePolicy(sizePolicy);
        intervalleBox->setAlignment(Qt::AlignCenter);
        intervalleBox->setFlat(false);
        verticalLayout_7 = new QVBoxLayout(intervalleBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(2, 2, 2, 2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        passeBox = new QCheckBox(intervalleBox);
        passeBox->setObjectName(QString::fromUtf8("passeBox"));

        horizontalLayout_7->addWidget(passeBox);

        actifBox = new QCheckBox(intervalleBox);
        actifBox->setObjectName(QString::fromUtf8("actifBox"));

        horizontalLayout_7->addWidget(actifBox);

        futurBox = new QCheckBox(intervalleBox);
        futurBox->setObjectName(QString::fromUtf8("futurBox"));

        horizontalLayout_7->addWidget(futurBox);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        inverseBox = new QCheckBox(intervalleBox);
        inverseBox->setObjectName(QString::fromUtf8("inverseBox"));

        horizontalLayout_8->addWidget(inverseBox);

        procheBox = new QCheckBox(intervalleBox);
        procheBox->setObjectName(QString::fromUtf8("procheBox"));

        horizontalLayout_8->addWidget(procheBox);

        ignoreBox = new QCheckBox(intervalleBox);
        ignoreBox->setObjectName(QString::fromUtf8("ignoreBox"));
        ignoreBox->setChecked(true);

        horizontalLayout_8->addWidget(ignoreBox);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(intervalleBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        debutTEdit = new QDateTimeEdit(intervalleBox);
        debutTEdit->setObjectName(QString::fromUtf8("debutTEdit"));

        horizontalLayout_9->addWidget(debutTEdit);

        dMtntBut = new QPushButton(intervalleBox);
        dMtntBut->setObjectName(QString::fromUtf8("dMtntBut"));

        horizontalLayout_9->addWidget(dMtntBut);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_2 = new QLabel(intervalleBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_10->addWidget(label_2);

        finTEdit = new QDateTimeEdit(intervalleBox);
        finTEdit->setObjectName(QString::fromUtf8("finTEdit"));

        horizontalLayout_10->addWidget(finTEdit);

        eMtntBut = new QPushButton(intervalleBox);
        eMtntBut->setObjectName(QString::fromUtf8("eMtntBut"));

        horizontalLayout_10->addWidget(eMtntBut);


        verticalLayout_7->addLayout(horizontalLayout_10);


        horizontalLayout_6->addWidget(intervalleBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        vehiculeBox = new QGroupBox(tab_3);
        vehiculeBox->setObjectName(QString::fromUtf8("vehiculeBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vehiculeBox->sizePolicy().hasHeightForWidth());
        vehiculeBox->setSizePolicy(sizePolicy1);
        vehiculeBox->setAlignment(Qt::AlignCenter);
        vehiculeBox->setFlat(false);
        horizontalLayout_4 = new QHBoxLayout(vehiculeBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        vEdit = new QLineEdit(vehiculeBox);
        vEdit->setObjectName(QString::fromUtf8("vEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(vEdit->sizePolicy().hasHeightForWidth());
        vEdit->setSizePolicy(sizePolicy2);
        vEdit->setMaximumSize(QSize(70, 16777215));
        vEdit->setMaxLength(5);

        horizontalLayout_4->addWidget(vEdit);

        vInverseBox = new QCheckBox(vehiculeBox);
        vInverseBox->setObjectName(QString::fromUtf8("vInverseBox"));

        horizontalLayout_4->addWidget(vInverseBox);


        verticalLayout_4->addWidget(vehiculeBox);

        stationBox = new QGroupBox(tab_3);
        stationBox->setObjectName(QString::fromUtf8("stationBox"));
        sizePolicy1.setHeightForWidth(stationBox->sizePolicy().hasHeightForWidth());
        stationBox->setSizePolicy(sizePolicy1);
        stationBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_5 = new QHBoxLayout(stationBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        sEdit = new QLineEdit(stationBox);
        sEdit->setObjectName(QString::fromUtf8("sEdit"));
        sizePolicy2.setHeightForWidth(sEdit->sizePolicy().hasHeightForWidth());
        sEdit->setSizePolicy(sizePolicy2);
        sEdit->setMaximumSize(QSize(70, 16777215));
        sEdit->setMaxLength(5);

        horizontalLayout_5->addWidget(sEdit);

        sInverseBox = new QCheckBox(stationBox);
        sInverseBox->setObjectName(QString::fromUtf8("sInverseBox"));

        horizontalLayout_5->addWidget(sInverseBox);


        verticalLayout_4->addWidget(stationBox);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        applyBut = new QPushButton(tab_3);
        applyBut->setObjectName(QString::fromUtf8("applyBut"));
        sizePolicy2.setHeightForWidth(applyBut->sizePolicy().hasHeightForWidth());
        applyBut->setSizePolicy(sizePolicy2);
        applyBut->setMinimumSize(QSize(0, 100));

        verticalLayout_5->addWidget(applyBut);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_6);

        tableView_3 = new QTableView(tab_3);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableView_3->sizePolicy().hasHeightForWidth());
        tableView_3->setSizePolicy(sizePolicy3);
        tableView_3->setAlternatingRowColors(true);
        tableView_3->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_3->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableView_3->setSortingEnabled(false);

        verticalLayout_6->addWidget(tableView_3);

        tableView_4 = new QTableView(tab_3);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setEnabled(true);
        sizePolicy3.setHeightForWidth(tableView_4->sizePolicy().hasHeightForWidth());
        tableView_4->setSizePolicy(sizePolicy3);
        tableView_4->setAlternatingRowColors(true);
        tableView_4->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_4->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableView_4->setSortingEnabled(true);

        verticalLayout_6->addWidget(tableView_4);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_9 = new QVBoxLayout(tab_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tableView_5 = new QTableView(tab_4);
        tableView_5->setObjectName(QString::fromUtf8("tableView_5"));
        tableView_5->setAlternatingRowColors(true);
        tableView_5->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_5->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout_9->addWidget(tableView_5);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_8 = new QVBoxLayout(tab_5);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableView_6 = new QTableView(tab_5);
        tableView_6->setObjectName(QString::fromUtf8("tableView_6"));
        tableView_6->setAlternatingRowColors(true);
        tableView_6->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_6->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);

        verticalLayout_8->addWidget(tableView_6);

        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 695, 22));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QString::fromUtf8("menu_Fichier"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menu_Fichier->addAction(action_Enregistrer);
        menu_Fichier->addAction(action_Ouvrir);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Enregistrer->setText(QApplication::translate("MainWindow", "&Enregistrer", 0, QApplication::UnicodeUTF8));
        action_Ouvrir->setText(QApplication::translate("MainWindow", "&Ouvrir", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Temps courant :", 0, QApplication::UnicodeUTF8));
        labelHeure->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        usagerBut->setText(QApplication::translate("MainWindow", "Afficher", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Stations", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "V\303\251hicules", 0, QApplication::UnicodeUTF8));
        intervalleBox->setTitle(QApplication::translate("MainWindow", "Intervalle", 0, QApplication::UnicodeUTF8));
        passeBox->setText(QApplication::translate("MainWindow", "Pass\303\251", 0, QApplication::UnicodeUTF8));
        actifBox->setText(QApplication::translate("MainWindow", "Actif", 0, QApplication::UnicodeUTF8));
        futurBox->setText(QApplication::translate("MainWindow", "Futur", 0, QApplication::UnicodeUTF8));
        inverseBox->setText(QApplication::translate("MainWindow", "Inverse", 0, QApplication::UnicodeUTF8));
        procheBox->setText(QApplication::translate("MainWindow", "+ proche", 0, QApplication::UnicodeUTF8));
        ignoreBox->setText(QApplication::translate("MainWindow", "Ignore", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "D\303\251but :", 0, QApplication::UnicodeUTF8));
        dMtntBut->setText(QApplication::translate("MainWindow", "Maintenant", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Fin :", 0, QApplication::UnicodeUTF8));
        eMtntBut->setText(QApplication::translate("MainWindow", "Maintenant", 0, QApplication::UnicodeUTF8));
        vehiculeBox->setTitle(QApplication::translate("MainWindow", "V\303\251hicule", 0, QApplication::UnicodeUTF8));
        vEdit->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        vInverseBox->setText(QApplication::translate("MainWindow", "Inverse", 0, QApplication::UnicodeUTF8));
        stationBox->setTitle(QApplication::translate("MainWindow", "station", 0, QApplication::UnicodeUTF8));
        sEdit->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        sInverseBox->setText(QApplication::translate("MainWindow", "Inverse", 0, QApplication::UnicodeUTF8));
        applyBut->setText(QApplication::translate("MainWindow", "Appliquer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "R\303\251servations", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Usagers", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        menu_Fichier->setTitle(QApplication::translate("MainWindow", "&Fichier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
