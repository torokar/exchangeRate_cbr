#include "writefile.h"
#include "dialogprogress.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QCoreApplication>
#include <QStringDecoder>
#include <QLineEdit>
#include "qlineeditforusers.h"


QString WriteFile::LengthCheck(const QString& string)
{
    const int maxlen = 15;
    if (string.length() > maxlen) {
        return string.left(maxlen - 3) + "...";
    }
    else {
        return string.leftJustified(maxlen);
    }
}

QByteArray convertWindows1251ToUtf8(const QByteArray& windows1251Data)
{
    QStringDecoder decoder("Windows-1251");
    QString text = decoder.decode(windows1251Data);

    if (decoder.hasError()) {
        qCritical() << "Ошибка декодирования Windows-1251!";
        return windows1251Data;
    }

    return text.toUtf8();
}

void WriteFile::saveXML(QByteArray& xmlData, const QString& fileName)
{

    QMessageBox::information(nullptr, "Внимание!", "Введите путь сохранения вручную");

    QLineEditForUsers line;

    QString LineDir = line.pathUser();
    if (line.exec() != QDialog::Accepted) { // Проверяем результат диалога
        QMessageBox::information(nullptr, "Отмена", "Сохранение файла отменено.");
        return;
    }

    QDir dir(LineDir + "/XMLdata");

    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Ошибка создания директории! Проверьте права доступа");
            return;
        }
    }

    QString filePath = dir.filePath(fileName + ".xml");
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка",
                              "Ошибка открытия файла: " + file.errorString());
        return;
    }

    QByteArray utf8Data = convertWindows1251ToUtf8(xmlData);

    if (utf8Data.contains("windows-1251")) {
        utf8Data.replace("windows-1251", "UTF-8");
    } else if (!utf8Data.contains("UTF-8")) {
        // Если кодировка не указана, добавляем UTF-8 в заголовок
        utf8Data.replace("<?xml version=\"1.0\"?>",
                         "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    }

    qint64 bytesWritten = file.write(utf8Data);
    file.close();

    if (bytesWritten == -1) {
        QMessageBox::critical(nullptr, "Ошибка",
                              "Ошибка записи в файл: " + file.errorString());
    } else {
        QMessageBox::information(nullptr, "Успех",
                                 QString("Данные записаны в файл!"));
    }
}



void WriteFile::WriteToFile(const QVector<Currence>& data)
{
    //Получения пути к директории

    QMessageBox::information(nullptr, "Внимание!", "Введите путь сохранения вручную");

    QLineEditForUsers line;

    QString LineDir = line.pathUser();
    if (line.exec() != QDialog::Accepted) { // Проверяем результат диалога
        QMessageBox::information(nullptr, "Отмена", "Сохранение файла отменено.");
        return;
    }
    //Создания подпапки
    QDir dir(LineDir + "/data");
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            QMessageBox::critical(nullptr, "Ошибка","Ошибка создания директории! Проверте права доступа.");
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

    for (const auto &text : data) {
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
        msgBox.exec();
    }

    file.close();

}

