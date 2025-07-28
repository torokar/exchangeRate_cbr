#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <pqxx/pqxx>
#include <QDebug>
#include <curl/curl.h>
#include <QString>
#include <QMessageBox>
#include <second_window.h>
#include <connection_cb.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_x_clicked()
// {
//     QString input;
//     QString inputUsers = MainWindow::ui->InputUser->text();
//     QString inputDB;
//     QString password;
//     QString Host;
//     //"dbname=mydb user=postgres password=20ufodop host=localhost"

//     qDebug() << "=== Testing PostgreSQL connectivity ===";

//     try {
//         // 1. Проверка версии libpqxx
//         qDebug() << "Libpqxx version:" << PQXX_VERSION;

//         // 2. Попытка подключения к базе данных
//         try {
//             pqxx::connection conn(inputUsers.toStdString());

//             if (conn.is_open()) {
//                 qDebug() << "Successfully connected to PostgreSQL!";
//                 qDebug() << "Database:" << conn.dbname();

//                 // Простой запрос для проверки
//                 pqxx::work txn(conn);
//                 pqxx::result res = txn.exec("SELECT version()");
//                 input += "PostgreSQL version:";
//                 input += res[0][0].c_str();
//                 txn.commit();
//             } else {
//                 qDebug() << "Connection failed!";
//             }
//         } catch (const pqxx::broken_connection &e) {
//             qDebug() << "Connection error:" << e.what();
//             qDebug() << "Please check:";
//             qDebug() << "1. Is PostgreSQL running? (sudo systemctl status postgresql)";
//             qDebug() << "2. Are credentials correct?";
//             qDebug() << "3. Check pg_hba.conf for connection permissions";
//         }
//     } catch (const std::exception &e) {
//         qDebug() << "General error:" << e.what();
//     }

//     MainWindow::ui->label->setText(input);
// }




void MainWindow::on_pushButton_clicked()
{
    int month = ui->spinMonth->value();
    qDebug() << month;
    int day = ui->spinDay->value();
    QString year = ui->InputYear->text();
    int yearInt = year.toInt();


    //Проверка корректности месяца
    if(month < 1 || month > 12)
    {
        QMessageBox::warning(this, "Error", "Месяц должен быть от 1 до 12.");
        return;
    }


    //Проверка корректности дня

    if(day <= 0 || day > 31)
    {
        QMessageBox::warning(this, "Error", "День должен быть от 1 до 31 (для выбранного месяца).");
        return;
    }

    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        QMessageBox::warning(this, "Erro", "В этом месяце не может быть больше 30 дней!");
        return;
    }


    //Проверка на февраль
    if(month == 2)
    {
        if(day > 28)
        {
            QMessageBox::warning(this, "Error", "Февраль не имеет больше 28 дней");
            return;
        }
    }



    //Проверка года
    if(yearInt < 1994 || yearInt > 2025)
    {
        QMessageBox::warning(this, "Error", "Год должен быть числом от 1994 до 2025.");
        return;
    }


    QString forDay = QString("%1").arg(day, 2, 10, QChar('0'));
    QString forMont = QString("%1").arg(month, 2, 10, QChar('0'));
    QString forYear = year;

    QString date = forDay + "/" + forMont + "/" + forYear;

    conn_cbRussian(date);


    second_window window;
    window.setModal(true);
    window.exec();

}





































