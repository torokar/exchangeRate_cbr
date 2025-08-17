#include "customgraph.h"
#include "ui_customgraph.h"
#include "../lib/qcustomplot/qcustomplot.h"

CustomGraph::CustomGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomGraph)
{
    ui->setupUi(this);
}

CustomGraph::~CustomGraph()
{
    delete ui;
}
