#ifndef CONNECTION_CB_H
#define CONNECTION_CB_H
#include <curl/curl.h>
#include <pqxx/pqxx>
#include "container.h"
#include "config_parser.h"
#include <QString>
#include <QDebug>
#include <container.h>
#include <write_to_file.h>
#include <QtConcurrent/QtConcurrent>
#include <DATABASE.h>
#include <write_to_file.h>

//Подключение к сайты ЦБ

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, QByteArray* output) {
    const size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

inline QVector<Currence> conn_cbRussian(const QString& dateUser)
{

    QByteArray xmlData;
    QVector<Currence> dataCurr;
    const QString full_url = "https://www.cbr.ru/scripts/XML_daily.asp?date_req=" + dateUser;

    CURL* curl = curl_easy_init();
    if (!curl) {
        qCritical() << "Error initializing CURL!";
        return {};
    }

    // Настройка CURL
    curl_easy_setopt(curl, CURLOPT_URL, full_url.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &xmlData);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        qCritical() << "CURL error:" << curl_easy_strerror(result);
        curl_easy_cleanup(curl);
        return {};
    }

    // Парсинг XML
    SubstrCurrensiFromXML(xmlData, dataCurr, dateUser);

    QtConcurrent::run([data = dataCurr]() { // Используем копию

        ConnectedBD(data);
    });


    curl_easy_cleanup(curl);
    return dataCurr;
}

#endif // CONNECTION_CB_H
