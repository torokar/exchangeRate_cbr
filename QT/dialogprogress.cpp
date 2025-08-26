#include "dialogprogress.h"
#include "ui_dialogprogress.h"
#include <QApplication>
#include <QProgressDialog>
#include <QThread>
#include <QDebug>
#include <QScreen>
#include <cstdlib>
#include <ctime>

DialogProgress::DialogProgress(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogProgress)
{
    ui->setupUi(this);
}

void DialogProgress::Progress(int &value, const QString &text)
{
    QProgressDialog progressBar(text, "Отмена", 0, 100, this);

    progressBar.setWindowTitle("Обработка");
    progressBar.setMinimumDuration(0);

    progressBar.setModal(true);


    QRect screen = QGuiApplication::primaryScreen()->geometry();
    int x = (screen.width() - progressBar.width()) / 2;
    int y = (screen.height() - progressBar.height()) / 2;
    progressBar.move(x, y);



    progressBar.setValue(value);
    QThread::msleep(80);
    for (value ; value <= 100 ; ++value) {


        int randomZeroOne = rand() % 2;
        if (randomZeroOne == 1) {
            QThread::msleep(70);
        }

        progressBar.setValue(value);
        qApp->processEvents();

    }


    if (progressBar.wasCanceled()) {
        return;
    }



    if (!progressBar.wasCanceled()) {
        progressBar.setValue(100);
    }
}

DialogProgress::~DialogProgress()
{
    delete ui;
}
