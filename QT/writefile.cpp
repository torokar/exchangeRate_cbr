#include "writefile.h"
#include "dialogprogress.h"

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


void WriteFile::saveXML(QByteArray& xmlData, const QString& fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Ошибка открытия файла:" << file.errorString();
        return;
    }

    QTextStream out(&file);

    out << xmlData;

    DialogProgress progressCon;
    int progressValue = 0;
    progressCon.Progress(progressValue, "Запись в текстовый файл...");

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

void WriteFile::WriteToFile(const QVector<Currence>& data)
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



    DialogProgress progressCon;
    int progressValue = 0;
    progressCon.Progress(progressValue, "Запись в текстовый файл...");

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

