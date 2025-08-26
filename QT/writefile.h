#ifndef WRITEFILE_H
#define WRITEFILE_H
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <container.h>
#include <QMessageBox>
#include <QTimer>


class WriteFile
{
public:
    WriteFile() = default;

    static void WriteToFile(const QVector<Currence>& data);
    static void saveXML (QByteArray& xmlData, const QString& fileName);
private:

    static QString LengthCheck(const QString& string);



};

#endif // WRITEFILE_H
