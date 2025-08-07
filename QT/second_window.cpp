#include "second_window.h"
#include "ui_second_window.h"
#include <QStandardItemModel>
#include <pqxx/pqxx>
#include <QDebug>
#include "connection_cb.h"
#include <QTextCodec>
#include <convertCP1251.h>

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

    loadDataFromDatabase();
}

void second_window::setDate(const QString &newDate)
{
    date = newDate;
}


//Вставка данных в таблицу
void second_window::loadDataFromDatabase()
{
    std::vector<Currence> dataCurr;
    dataCurr = conn_cbRussian(date);
    std::string convert;

    // for (int i = 0; i < dataCurr.size(); ++i) {

    //     convert = dataCurr[i].Name_currence;
    //     ConvertCP1251ToUTF8(convert);

    //     dataCurr[i].Name_currence = convert;
    // }

    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");


    model->removeRows(0, model->rowCount());

    for(const auto& cur : dataCurr )
    {
        QList<QStandardItem*> rowItems;

        QString name = codec->toUnicode(cur.Name_currence.c_str());

       rowItems << new QStandardItem(QString::fromStdString(cur.CharCode));
       rowItems << new QStandardItem(QString::fromStdString(cur.Name_currence));
       rowItems << new QStandardItem(QString::fromStdString(cur.Value));
       rowItems << new QStandardItem(QString::fromStdString(cur.Date));

       model->appendRow(rowItems);
    }

    // model->sort(3, Qt::DescendingOrder);


}

second_window::~second_window()
{
    delete ui;
}
