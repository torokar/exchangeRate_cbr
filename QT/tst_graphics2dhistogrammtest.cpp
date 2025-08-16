// Graphics2DHistogrammTest.cpp
#include "tst_graphics2dhistogrammtest.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

Graphics2DHistogrammTest::Graphics2DHistogrammTest(QObject *parent) : QObject(parent) {}

void Graphics2DHistogrammTest::runTest()
{
    QGraphicsView *graphicsView = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene();
    graphicsView->setScene(scene);
    graphicsView->resize(520, 520);
    graphicsView->show();

    Graphics2DHistogramItem *histogramm = new Graphics2DHistogramItem();
    histogramm->setBrush(QBrush(Qt::red));

    QVector<float> absciss, ordinate;
    for(int i = 0; i <= 10; ++i) {
        absciss.append(-20 + 2 * i);
        ordinate.append(-30 + 2 * i);
    }

    histogramm->setData(absciss, ordinate);
    scene->addItem(histogramm);
    histogramm->setScale(4);
}
