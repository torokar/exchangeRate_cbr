#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <container.h>
#include <QMessageBox>
#include <QTimer>

inline QString LengthCheck(const QString& string)
{
    const int maxlen = 15;
    if (string.length() > maxlen) {
        return string.left(maxlen - 3) + "...";
    }
    else {
        return string.leftJustified(maxlen);
    }
}


inline void WriteFile(const QVector<Currence>& data)
{
    //Получения пути к директории
    QString Dir = QCoreApplication::applicationDirPath();


    //Создания подпапки
    QDir dir(Dir + "/data");
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qCritical() << "Ошибка создания директории! Проверте права доступа.";
            return;
        }
    }

    QString filePath = dir.filePath("currency_data.txt");

    QFile file(filePath);

    QTextStream out(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла:" << file.errorString();
        return;
    }

    out << "|======================================================================|\n";
    out << "|      Code      |      Name       |      Value      |     Date        |\n";
    out << "|======================================================================|\n";

    for (const auto text : data) {
        // Ее краткое названия
        out << "|" << LengthCheck(text.CharCode).leftJustified(13) << " | ";

        //Названия валюты
        out << LengthCheck(text.Name_currence).leftJustified(13) << " | ";

        //Значение
        QString valueStr = QString::number(text.Value, 'f', 3);
        out << LengthCheck(valueStr).leftJustified(13) << " | ";

        //Дата
        out << LengthCheck(text.Date).leftJustified(13) << " | \n";

        out << "|----------------------------------------------------------------------|\n";

    }

    if(out.status() != QTextStream::Ok){
        qCritical() << "Ошибка записи в файл!";
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Информация");
        msgBox.setText("Данные записаны в файл");
        msgBox.setIcon(QMessageBox::Information);
        QTimer::singleShot(2000, &msgBox, &QMessageBox::accept);
        msgBox.exec();
    }

    file.close();

}





#endif // WRITE_TO_FILE_H
