#include "lineeditforusers.h"
#include "ui_lineeditforusers.h"

LineEditForUsers::LineEditForUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LineEditForUsers)
{
    QLabel *name = new QLabel("Path: ", this);
    name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *le1 = new QLineEdit(this);


    QGridLayout *grid = new QGridLayout();

    grid->addWidget(name, 0, 0);
    grid->addWidget(le1, 0, 1);

    setLayout(grid);

}

LineEditForUsers::~LineEditForUsers()
{
    delete ui;
}
