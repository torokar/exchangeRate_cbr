#include "qlineeditforusers.h"
#include "ui_qlineeditforusers.h"
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>

QLineEditForUsers::QLineEditForUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QLineEditForUsers)
    ,pathUsers("")
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

QString QLineEditForUsers::pathUser()
{
    return pathUsers;
}


QLineEditForUsers::~QLineEditForUsers()
{
    delete ui;
}

void QLineEditForUsers::on_pushButtonPath_clicked()
{
    pathUsers = ui->Path->text();
    accept();
}


void QLineEditForUsers::on_pushButtonPath_2_clicked()
{
    reject();
}

