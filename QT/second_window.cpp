#include "second_window.h"
#include "ui_second_window.h"
#include <QStandardItemModel>
#include <pqxx/pqxx>
#include <QDebug>

second_window::second_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_window),
    model(new QStandardItemModel(this))
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

void second_window::loadDataFromDatabase()
{
    try {

        pqxx::connection conn(
            "host=localhost "
            "port=5432 "
            "dbname=mydb "
            "user=service "
            "password=11111111 "
            "options='-c client_encoding=UTF8'"
            );

        if (conn.is_open()) {
            pqxx::work txn(conn);

            pqxx::result res = txn.exec("SELECT CharCode, NameCurrency, Value,"
                                        " Date FROM exdc ORDER BY Date DESC");

            // Очищаем модель перед загрузкой новых данных
            model->removeRows(0, model->rowCount());

            //Загрузка данных в таблицу из БД
            for (const auto& row : res) {
                QList<QStandardItem*> items;
                items << new QStandardItem(QString::fromStdString(row["CharCode"].as<std::string>()));
                items << new QStandardItem(QString::fromStdString(row["NameCurrency"].as<std::string>()));
                items << new QStandardItem(QString::fromStdString(row["Value"].as<std::string>()));
                items << new QStandardItem(QString::fromStdString(row["Date"].as<std::string>()));
                model->appendRow(items);
            }

            txn.commit();
            //Если нет данных
        } else {
            qDebug() << "Не удалось подключиться к базе данных";
            QList<QStandardItem*> rowItems;
            rowItems << new QStandardItem("Нет данных");
            rowItems << new QStandardItem("");
            rowItems << new QStandardItem("");
            rowItems << new QStandardItem("");
            model->appendRow(rowItems);
        }
    } catch (const std::exception& e) {
        qDebug() << "Ошибка при загрузке данных:" << e.what();
    }
}

second_window::~second_window()
{
    delete ui;
}
