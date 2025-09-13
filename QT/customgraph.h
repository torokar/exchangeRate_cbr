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
    //Для обновления и получения данных
    void setCurrenceData(const QVector<Currence> &data);
    void addPoint();
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
