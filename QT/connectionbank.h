#ifndef CONNECTIONBANK_H
#define CONNECTIONBANK_H
#include <QDebug>
#include <container.h>
#include <curl/curl.h>

class ConnectionBank
{
public:

    ConnectionBank(QObject *parent = nullptr);

    static QVector<Currency> connCbRussian(const QString& dateUser);

    static QByteArray getAByteArray();

private:

            static QByteArray xmlData;
    static size_t writeCallBack(void* contents, size_t size, size_t nmemb, QByteArray* output);
};

#endif // CONNECTIONBANK_H
