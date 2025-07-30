#include "second_window.h"
#include "ui_second_window.h"
#include <pqxx/pqxx>
#include <QMessageBox>
#include <getFromPostgres.h>

second_window::second_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::second_window)
{
    ui->setupUi(this);

}

second_window::~second_window()
{
    delete ui;
}

void second_window::on_loadTable_clicked()
{

}

