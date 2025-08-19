#include "customgraph.h"
#include "../lib/qcustomplot/qcustomplot.h"
#include <QTimer>
#include "ui_customgraph.h"

CustomGraph::CustomGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomGraph)
{
    ui->setupUi(this);


    //Переменные
    step = 0.1;
    xBegin = -3;
    xEnd = 3 + step;

    ui->widget->xAxis->setRange(-4, 4);
    ui->widget->yAxis->setRange(0, 9);



    variable = xBegin;
    numPoints = (xEnd - xBegin) / step + 2;


    //Заполнения вектора точками графика
    for (variable = xBegin; variable <= xEnd; variable += step) {

        x.push_back(variable);
        y.push_back(variable * variable);

    }


    //Вывод графика
    ui->widget->addGraph();
    //Передача точек графика
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}


CustomGraph::~CustomGraph()
{
    delete ui;
}

void CustomGraph::on_pushButton_clicked()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeof()), this, SLOT(TimerSlot()));
    ui->widget->clearGraphs();
    timer = 0;
    timer->start(20);
    variable = xBegin;
    x.clear();
    y.clear();

}

void CustomGraph::TimerSlot()
{
    if (time <= 20 * numPoints) {
        if (variable <= xEnd) {
            x.push_back(variable);
            if (ui->radioButton->isChecked()) {
                y.push_back(variable * variable);
            }
            else if(ui->radioButton_2->isChecked()) {
                y.push_back(sin(variable));
            }
            variable += step;
        }
        time += 20;
    }
    else {
        time = 0;
        timer->stop();
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

