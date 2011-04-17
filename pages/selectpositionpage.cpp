#include <QtGui>

#include "page.h"
#include "selectpositionpage.h"

#include "cartewidget.h"
#include "cartescene.h"

SelectPositionPage::SelectPositionPage(QWidget *parent) :
    Page(parent)
{
    addTitle(trUtf8("Choisir une position\n(2 / 5)"));

    CarteScene *scene = CarteScene::readSceneFile("data/xml/map_montreal.osm");
    CarteWidget::setScene(scene);

    CarteWidget *mapWidget = new CarteWidget(this);
    addWidget(mapWidget);

    QPushButton *btnPrevious = new QPushButton(this);
    btnPrevious->setIcon(QIcon(":/icones/data/icons/arrow_left.png"));
    btnNext = new QPushButton(this);
    btnNext->setIcon(QIcon(":/icones/data/icons/arrow_right.png"));
    QPushButton *btnMenu = new QPushButton(trUtf8("Menu"), this);
    btnNext->setEnabled(false);

    addBottomButtons(btnPrevious, btnMenu, btnNext);

    connect(mapWidget, SIGNAL(editFinished()), this, SLOT(enableNextButton()));
    connect(btnPrevious, SIGNAL(clicked()), SIGNAL(Previous()));
    connect(btnMenu, SIGNAL(clicked()), SIGNAL(Menu()));
    connect(btnNext, SIGNAL(clicked()), SIGNAL(Next()));
}

void SelectPositionPage::enableNextButton() {
    btnNext->setEnabled(true);
}
