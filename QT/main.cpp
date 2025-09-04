#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <curl/curl.h>
#include <pqxx/pqxx>
#include <QScreen>

int main() {

    int c = 1;
    char** v = (char**)("Currence");
    QApplication a(c, v);

    // Запускаем главное окно
    MainWindow w;
    w.setWindowTitle("Currence"); //Названия окна
    w.resize(600,600);

    //Получения размера экрана
    QRect screen = QGuiApplication::primaryScreen()->geometry();
    int x = (screen.width() - w.width()) / 2;
    int y = (screen.height() - w.height()) / 2;
    w.move(x, y);
    w.show();

    return a.exec();
}


