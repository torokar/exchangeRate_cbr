#ifndef CUSTOMGRAPH_H
#define CUSTOMGRAPH_H

#include <QDialog>
#include <QVector>
#include "container.h"
#include "../lib/qcustomplot/qcustomplot.h"

namespace Ui {
class CustomGraph;
}

class CustomGraph : public QDialog
{
    Q_OBJECT

public:
    explicit CustomGraph(const QVector<Currence> &data, QWidget *parent = nullptr);
    ~CustomGraph();
    void setCurrenceData(const QVector<Currence> &data); //Для обновления и получения данных

    void addPoint();
    void plot();
    void clearPoints();
    void plotDrawting();
    void viewGraph();

private:
    Ui::CustomGraph *ui;

    QVector<QCPItemText*> textLabels;
    QVector<double> xValues, yValues;
    QVector<Currence> currenceData; // Вектор данных
};

#endif // CUSTOMGRAPH_H
