#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>
#include <QStandardItem>
#include <QXmlStreamReader>
#include <QVector>
#include <container.h>

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

private slots:
    void on_write_clicked();
    void on_graph_clicked();

private:
    Ui::second_window *ui;
    QStandardItemModel *model;
    void loadDataFromWebCB();
    QVector<Currence> currenceDataForSecondWindow;
    QString date;
};

#endif // SECOND_WINDOW_H
