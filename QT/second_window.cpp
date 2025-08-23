#include "second_window.h"
#include "ui_second_window.h"
#include <QStandardItemModel>
#include <pqxx/pqxx>
#include <QDebug>
#include <QStringConverter>
#include <convertCP1251.h>
#include "customgraph.h"
#include "write_to_file.h"
#include "connection_cb.h"
#include <QMessageBox>

second_window::second_window(QWidget *parent, const QString &date) :
    QDialog(parent),
    ui(new Ui::second_window),
    model(new QStandardItemModel(this)),
    date(date)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());



    model->setColumnCount(4);
    model->setHorizontalHeaderLabels({"Код", "Валюта", "Курс", "Дата"});

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    loadDataFromWebCB();
}

void second_window::setDate(const QString &newDate)
{
    date = newDate;
}

//Вставка данных в таблицу
void second_window::loadDataFromWebCB()
{
    currenceDataForSecondWindow = conn_cbRussian(date);

    model->removeRows(0, model->rowCount());

    for(const auto& cur : currenceDataForSecondWindow) {
        QList<QStandardItem*> rowItems;

        rowItems << new QStandardItem(cur.CharCode);
        rowItems << new QStandardItem(cur.Name_currence);


        //Числовой элемент в таблице для корректной работы сортировки в таблице
        QStandardItem* valueItem = new QStandardItem();
        valueItem->setData(cur.Value, Qt::UserRole); //Элемент для числовых значений
        valueItem->setData(QString::number(cur.Value, 'f', 4), Qt::DisplayRole); //Отображения в таблице
        rowItems << valueItem;

        rowItems << new QStandardItem(cur.Date);

        model->appendRow(rowItems);
    }
}

second_window::~second_window()
{
    delete ui;
}

void second_window::on_write_clicked()
{
    WriteFile(currenceDataForSecondWindow);
}


void second_window::on_graph_clicked()
{
    if (currenceDataForSecondWindow.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет данных для построения графика");
        return;
    }

    //Если Graph существует сначала удаляем
    if (Graph) {
        delete Graph;
        Graph = nullptr;
    }

    Graph = new CustomGraph(currenceDataForSecondWindow, nullptr);
    Graph->exec();
}
