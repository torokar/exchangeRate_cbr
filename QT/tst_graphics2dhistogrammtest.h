
#ifndef GRAPHICS2DHISTOGRAMMTEST_H
#define GRAPHICS2DHISTOGRAMMTEST_H

#include <QObject>
#include "GraphicsDataItem.h"

class Graphics2DHistogrammTest : public QObject
{
    Q_OBJECT
public:
    explicit Graphics2DHistogrammTest(QObject *parent = nullptr);
    void runTest();
};

#endif // GRAPHICS2DHISTOGRAMMTEST_H
