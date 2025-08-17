#ifndef CUSTOMGRAPH_H
#define CUSTOMGRAPH_H

#include <QDialog>
#include <QVector>

namespace Ui {
class CustomGraph;
}

class CustomGraph : public QDialog
{
    Q_OBJECT

public:
    explicit CustomGraph(QWidget *parent = nullptr);
    ~CustomGraph();

private:
    Ui::CustomGraph *ui;
    double xBegin, xEnd, step, variable;
    int numPoints;

    QVector<double> x, y;
};

#endif // CUSTOMGRAPH_H
