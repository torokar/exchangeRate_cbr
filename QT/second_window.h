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
    explicit second_window(QWidget *parent = nullptr);
    ~second_window();

private:
    Ui::second_window *ui;
    QStandardItemModel *model;
};

#endif // SECOND_WINDOW_H
