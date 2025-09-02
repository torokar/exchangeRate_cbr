#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H
#include <QDebug>
#include <QThread>
#include <QDialog>

namespace  Ui {
class ProDialog;
}
class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = nullptr);

    ~ProgressDialog();
private:

    Ui::ProDialog * ui;
};

#endif // PROGRESSDIALOG_H
