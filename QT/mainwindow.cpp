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
#include <getFromPostgres.h>

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

void MainWindow::on_pushButton_clicked()
{
    int month = ui->spinMonth->value();
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



    QString forDay = QString("%1").arg(day, 2, 10, QChar('0'));
    QString forMont = QString("%1").arg(month, 2, 10, QChar('0'));
    QString forYear = year;

    QString date = forDay + "/" + forMont + "/" + forYear;

    //Имитация загрузки данных)
    QMessageBox msgBox;
    msgBox.setWindowTitle("Информация");
    msgBox.setText("Идет загрузка данных...");
    msgBox.setIcon(QMessageBox::Information);
    QTimer::singleShot(3000, &msgBox, &QMessageBox::accept);
    msgBox.exec();

    //Фоновый вызов с передачей даты в поток
    QtConcurrent::run([this, date]()
                      { QMetaObject::invokeMethod(this, "handData", Qt::QueuedConnection, Q_ARG(QString, date)); });
}

void MainWindow::handData(const QString &date)
{
    second_window window(nullptr, date);
    window.setModal(true);
    window.exec();
}

