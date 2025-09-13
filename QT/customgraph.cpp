#include "customgraph.h"
#include "ui_customgraph.h"
#include <QDebug>

CustomGraph::CustomGraph(const QVector<Currence> &data, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomGraph)
    , currenceData(data)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    for (int i = 0; i < data.size(); ++i) {
        xValues.push_back(i);
        yValues.push_back(data[i].Value);
    }
    ui->widget->xAxis->setRange(0, currenceData.size());
    ui->widget->yAxis->setRange(0, 100);

    viewGraph();
}

CustomGraph::~CustomGraph()
{
    clearPoints();
    delete ui;
}

void CustomGraph::clearPoints()
{
    //Удаляет все подписи
    for (QCPItemText *textLabel : textLabels) {
        ui->widget->removeItem(textLabel);
        delete textLabel;
    }
    textLabels.clear();
}

void CustomGraph::addPoint()
{
    clearPoints();
    //Настройка отображения точек
    for (int i = 0; i < currenceData.size(); ++i) {
        const Currence &cur = currenceData[i];
        QCPItemText *textPoint = new QCPItemText(ui->widget);
        textPoint->setPositionAlignment(Qt::AlignCenter | Qt::AlignBottom);
        textPoint->position->setType(QCPItemPosition::ptPlotCoords);
        textPoint->position->setCoords(xValues[i], cur.Value + 5);
        textPoint->setText(QString::number(cur.Value));
        textPoint->setFont(QFont(font().family(), 8));
        textPoint->setPen(QPen(Qt::black));
        textPoint->setBrush(QBrush(Qt::white));
        textPoint->setPadding(QMargins(2,2,2,2));

        textLabels.append(textPoint);
    }
}

void CustomGraph::plotDrawting()
{
    ui->widget->replot();
    ui->widget->update();
}

void CustomGraph::viewGraph()
{
    //Настройка графика
    ui->widget->clearGraphs(); //Очистка графика
    ui->widget->addGraph();
    ui->widget->graph(0);
    ui->widget->graph(0)->setPen(QColor(Qt::green));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->widget->graph(0)->setData(xValues, yValues);

    //Передвижение по графику
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);

    addPoint();
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);

    for (int i = 0; i < currenceData.size(); ++i) {
        const Currence &cur = currenceData[i];
        QString str = cur.CharCode;
        textTicker->addTick(i, str);
    }

    ui->widget->xAxis->setTicker(textTicker);
    ui->widget->xAxis->setLabel("Валюта");
    ui->widget->yAxis->setLabel("Курс рубля");

    plotDrawting();
}
