#ifndef CUSTOMGRAPH_H
#define CUSTOMGRAPH_H

#include <QDialog>
#include <QVector>
#include <QTimer>

namespace Ui {
class CustomGraph;
}

class CustomGraph : public QDialog
{
    Q_OBJECT

public:
    explicit CustomGraph(QWidget *parent = nullptr);
    ~CustomGraph();

private slots:
    // void on_pushButton_clicked();
    // void TimerSlot();

private:
    Ui::CustomGraph *ui;
    QTimer *timer;

    double step;
    double xBegin;
    double xEnd;
    double variable;
    int numPoints;
    int time;
    QVector<double> x, y;
};

#endif // CUSTOMGRAPH_H
