#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>
#include <QStandardItem>

namespace Ui {
class second_window;
}

class second_window : public QDialog
{
    Q_OBJECT

public:
    //передача даты, для которой нужно показать курс
    explicit second_window(QWidget *parent = nullptr, const QString &date = "");
    ~second_window();
    void setDate(const QString &date);

private:
    Ui::second_window *ui;
    QStandardItemModel *model;
    void loadDataFromDatabase();
    QString date;
};

#endif // SECOND_WINDOW_H
