#ifndef CONNECTION_CB_H
#define CONNECTION_CB_H
#include <curl/curl.h>
#include <pqxx/pqxx>
#include "container.h"
#include "config_parser.h"
#include "DATABASE.h"
#include <QString>
#include <iostream>
#include <QDebug>
#include <container.h>
#include <write_to_file.h>
#include <QtConcurrent/QtConcurrent>

//Подключение к сайты ЦБ

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

void conn_cbRussian(const QString& dateUser)
{
    setlocale(LC_ALL, "ru");

    std::string XmlData;
    std::vector<Currence> DataCurr;
    const std::string base_url = "https://www.cbr.ru/scripts/XML_daily.asp?date_req=";

    CURL* curl;
    CURLcode result;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl)
    {
        std::cerr << "Error initializing CURL!" << std::endl;
        return;
    }

    // полный URL
    std::string full_url = base_url + dateUser.toStdString();

    curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &XmlData);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    result = curl_easy_perform(curl);

    if (result != CURLE_OK)
    {
        std::cerr << "CURL error: " << curl_easy_strerror(result) << std::endl;
    }
    else
    {
        // Парсим XML и работаем с данными
        auto xmlDataCopy = XmlData;
        auto dateCopy = dateUser;

        SubstrCurrensiFromXML(XmlData, DataCurr);
        WriteFile(DataCurr);
        ConnectedBD(DataCurr);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

#endif // CONNECTION_CB_H
