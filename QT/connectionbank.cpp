#include "connectionbank.h"
#include "configparser.h"
#include "databaseconfig.h"
#include <curl/curl.h>
#include <QDebug>
#include "progresbar.h"
#include "container.h"


    QByteArray ConnectionBank::xmlData;

    QByteArray ConnectionBank::GetAByteArray()
    {
        return xmlData;
    }


    size_t ConnectionBank::WriteCallback(void* contents, size_t size, size_t nmemb, QByteArray* output)
    {
        const size_t total_size = size * nmemb;
        output->append(static_cast<char*>(contents), total_size);
        return total_size;
    }


    QVector<Currence> ConnectionBank::conn_cbRussian(const QString& dateUser)
    {
        Currence writeData;
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
        ConfigParser::SubstrCurrensiFromXML(xmlData, dataCurr, dateUser);
        writeData.xmlData = xmlData;

        try {
            DataBaseConfig::ConnectedBD(dataCurr);
        } catch (const std::exception& e) {
            qCritical() << "Database operation in conn_cbRussian failed:" << e.what();
        }

        curl_easy_cleanup(curl);
        return dataCurr;
    }
