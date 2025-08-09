#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <container.h>


// inline void WriteFile(const QVector<Currence>& data)
// {
//     // Создаем директорию, если ее нет
//     QDir().mkpath("data_file");

//     QFile file("data_file/data.txt");
//     if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//         qCritical() << "Could not open file for writing:" << file.errorString();
//         return;
//     }

//     QTextStream out(&file);
//     out.setCodec("UTF-8"); // Устанавливаем кодировку UTF-8

//     for (const auto& currency : data) {
//         // Заменяем запятые на точки в значении
//         QString value = currency.Value;
//         value.replace(',', '.');

//         // Формируем строку запроса
//         out << "INSERT INTO exc (CharCode, NameCurrency, Value) VALUES ('"
//             << currency.CharCode << "', '"
//             << currency.Name_currence << "', '"
//             << value << "');\n";
//     }

//     file.close();
//     qDebug() << "Successfully wrote" << data.size() << "records to file";
// }

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
        // Если не удалось открыть, выводим ошибку
        qDebug() << "Ошибка открытия файла:" << file.errorString();
        return;
    }

    for (const auto text : data) {

        // Ее краткое названия
        QString DataCurrence = text.CharCode;
        out << DataCurrence << " | ";

        //Названия валюты
        DataCurrence = text.Name_currence;
        out << DataCurrence << " | ";

        //Значение
        DataCurrence = text.Value;
        out << DataCurrence << " | ";

        //Дата
        DataCurrence = text.Date;
        out << DataCurrence << " | ";

    }

    qDebug() << "Будет создан файл:" << dir.filePath("currency_data.txt");

    file.close();

}





#endif // WRITE_TO_FILE_H
