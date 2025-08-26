#ifndef DIALOGPROGRESS_H
#define DIALOGPROGRESS_H

#include <QDialog>

namespace Ui {
class DialogProgress;
}

class DialogProgress : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProgress(QWidget *parent = nullptr);
    ~DialogProgress();
        void Progress(int &value, const QString &text);
private:
    Ui::DialogProgress *ui;

};

#endif // DIALOGPROGRESS_H
