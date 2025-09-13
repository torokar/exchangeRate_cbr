#ifndef CONNECTIONBANK_H
#define CONNECTIONBANK_H
#include <curl/curl.h>
#include <pqxx/pqxx>
#include "container.h"
#include <QString>
#include <QDebug>
#include <container.h>
#include <writefile.h>
#include <QtConcurrent/QtConcurrent>
#include <databaseconfig.h>
#include <configparser.h>
#include <curl/curl.h>
#include <QDebug>

class ConnectionBank
{
public:

    ConnectionBank(QObject *parent = nullptr);

    static QVector<Currence> connCbRussian(const QString& dateUser);

    static QByteArray getAByteArray();

private:

            static QByteArray xmlData;
    static size_t writeCallBack(void* contents, size_t size, size_t nmemb, QByteArray* output);
};

#endif // CONNECTIONBANK_H
