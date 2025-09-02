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
    line.setPathText(QDir::homePath()); // Установить путь по умолчанию
    if (line.exec() != QDialog::Accepted) {
        QMessageBox::information(nullptr, "Отмена", "Сохранение файла отменено.");
        return;
    }

    QString LineDir = QDir::cleanPath(line.pathUser());

    if (LineDir.isEmpty()) {
        QMessageBox::critical(nullptr, "Ошибка", "Путь не указан!");
        return;
    }

    QFileInfo parentDirInfo(LineDir);
    if (!parentDirInfo.exists() || !parentDirInfo.isWritable()) {
        QMessageBox::critical(nullptr, "Ошибка",
                              QString("Нет прав на запись в директорию: %1").arg(LineDir));
        return;
    }

    QDir dir(LineDir + "/XMLdata");
    if (!dir.exists()) {
        if (!dir.mkpath(LineDir + "/XMLdata")) {
            QMessageBox::critical(nullptr, "Ошибка",
                                  QString("Ошибка создания директории %1! Проверьте права доступа").arg(LineDir + "/XMLdata"));
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
    QMessageBox::information(nullptr, "Внимание!", "Введите путь сохранения вручную");

    QLineEditForUsers line;
    line.setPathText(QDir::homePath());
    if (line.exec() != QDialog::Accepted) {
        QMessageBox::information(nullptr, "Отмена", "Сохранение файла отменено.");
        return;
    }

    QString LineDir = QDir::cleanPath(line.pathUser());

    if (LineDir.isEmpty()) {
        QMessageBox::critical(nullptr, "Ошибка", "Путь не указан!");
        return;
    }

    QFileInfo parentDirInfo(LineDir);
    if (!parentDirInfo.exists() || !parentDirInfo.isWritable()) {
        QMessageBox::critical(nullptr, "Ошибка",
                              QString("Нет прав на запись в директорию: %1").arg(LineDir));
        return;
    }

    QDir dir(LineDir + "/data");
    if (!dir.exists()) {
        if (!dir.mkpath(LineDir + "/data")) {
            QMessageBox::critical(nullptr, "Ошибка",
                                  QString("Ошибка создания директории %1! Проверьте права доступа").arg(LineDir + "/data"));
            return;
        }
    }

    QString filePath = dir.filePath("currency_data.txt");
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла:" << file.errorString();
        QMessageBox::critical(nullptr, "Ошибка",
                              QString("Ошибка открытия файла: %1").arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << "|======================================================================|\n";
    out << "|      Code      |      Name       |      Value      |     Date        |\n";
    out << "|======================================================================|\n";

    for (const auto &text : data) {
        out << "|" << LengthCheck(text.CharCode).leftJustified(13) << " | ";
        out << LengthCheck(text.Name_currence).leftJustified(13) << " | ";
        QString valueStr = QString::number(text.Value, 'f', 3);
        out << LengthCheck(valueStr).leftJustified(13) << " | ";
        out << LengthCheck(text.Date).leftJustified(13) << " | \n";
        out << "|----------------------------------------------------------------------|\n";
    }

    if (out.status() != QTextStream::Ok) {
        qCritical() << "Ошибка записи в файл!";
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка записи в файл!");
    } else {
        QMessageBox::information(nullptr, "Информация", "Данные записаны в файл");
    }

    file.close();
}
