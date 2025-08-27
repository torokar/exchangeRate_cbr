#ifndef LINEEDITFORUSERS_H
#define LINEEDITFORUSERS_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class LineEditForUsers;
}

class LineEditForUsers : public QDialog
{
    Q_OBJECT

public:
    explicit LineEditForUsers(QWidget *parent = nullptr);
    ~LineEditForUsers();

private:
    Ui::LineEditForUsers *ui;
};

#endif // LINEEDITFORUSERS_H
