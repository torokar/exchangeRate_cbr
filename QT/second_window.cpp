#include "second_window.h"
#include "ui_second_window.h"
#include <QStandardItemModel>

second_window::second_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::second_window)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    model->setColumnCount(4);
    model->setHorizontalHeaderLabels({"Код валюты", "Названия", "Значения", "Дата"});

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem("Данные отсутствуют");
    rowItems << new QStandardItem("");
    rowItems << new QStandardItem("");
    rowItems << new QStandardItem("");
    model->appendRow(rowItems);
}

second_window::~second_window()
{
    delete ui;
}
