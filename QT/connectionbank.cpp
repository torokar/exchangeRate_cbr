#include "connectionbank.h"
#include "configparser.h"
#include "databaseconfig.h"
#include <curl/curl.h>
#include <QDebug>
#include "container.h"


    QByteArray ConnectionBank::xmlData;

    QByteArray ConnectionBank::getAByteArray()
    {
        return xmlData;
    }


    size_t ConnectionBank::writeCallBack(void* contents, size_t size, size_t nmemb, QByteArray* output)
    {
        const size_t total_size = size * nmemb;
        output->append(static_cast<char*>(contents), total_size);
        return total_size;
    }


    QVector<Currency> ConnectionBank::connCbRussian(const QString& dateUser)
    {
        Currency writeData;
        QVector<Currency> dataCurr;
        const QString fullUrl = "https://www.cbr.ru/scripts/XML_daily.asp?date_req=" + dateUser;

        CURL* curl = curl_easy_init();
        if (!curl) {
            qCritical() << "Error initializing CURL!";
            return {};
        }

        // Настройка CURL
        curl_easy_setopt(curl, CURLOPT_URL, fullUrl.toStdString().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
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
        ConfigParser::substrCurrensiFromXML(xmlData, dataCurr, dateUser);
        writeData.xmlData = xmlData;

        try {
            DataBaseConfig::connectedDb(dataCurr);
        } catch (const std::exception& e) {
            qCritical() << "Database operation in conn_cbRussian failed:" << e.what();
        }

        curl_easy_cleanup(curl);
        return dataCurr;
    }
