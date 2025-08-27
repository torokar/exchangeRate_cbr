#ifndef QLINEEDITFORUSERS_H
#define QLINEEDITFORUSERS_H

#include <QDialog>

namespace Ui {
class QLineEditForUsers;
}

class QLineEditForUsers : public QDialog
{
    Q_OBJECT

public:
    explicit QLineEditForUsers(QWidget *parent = nullptr);
    ~QLineEditForUsers();
    QString pathUser();

private slots:
    void on_pushButtonPath_clicked();

    void on_pushButtonPath_2_clicked();

private:
    Ui::QLineEditForUsers *ui;
    QString pathUsers;

};

#endif // QLINEEDITFORUSERS_H
