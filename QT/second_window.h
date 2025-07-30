#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>

namespace Ui {
class second_window;
}

class second_window : public QDialog
{
    Q_OBJECT

public:
    explicit second_window(QWidget *parent = nullptr);
    ~second_window();


private slots:
    void on_loadTable_clicked();

private:
    Ui::second_window *ui;

};

#endif // SECOND_WINDOW_H
