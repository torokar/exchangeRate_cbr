#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <curl/curl.h>
#include <pqxx/pqxx>


void testPostgreSQLConnection() {
    qDebug() << "=== Testing PostgreSQL connectivity ===";

    try {
        // 1. Проверка версии libpqxx
        qDebug() << "Libpqxx version:" << PQXX_VERSION;

        // 2. Попытка подключения к базе данных
        try {
            pqxx::connection conn("dbname=mydb user=postgres password=20ufodop host=localhost");

            if (conn.is_open()) {
                qDebug() << "111Successfully connected to PostgreSQL!";
                qDebug() << "Database:" << conn.dbname();

                // Простой запрос для проверки
                pqxx::work txn(conn);
                pqxx::result res = txn.exec("SELECT version()");
                qDebug() << "PostgreSQL version:" << res[0][0].c_str();
                txn.commit();
            } else {
                qDebug() << "Connection failed!";
            }
        } catch (const pqxx::broken_connection &e) {
            qDebug() << "Connection error:" << e.what();
            qDebug() << "Please check:";
            qDebug() << "1. Is PostgreSQL running? (sudo systemctl status postgresql)";
            qDebug() << "2. Are credentials correct?";
            qDebug() << "3. Check pg_hba.conf for connection permissions";
        }
    } catch (const std::exception &e) {
        qDebug() << "General error:" << e.what();
    }
}

void testCurlFunctionality() {
    qDebug() << "\n=== Testing libcurl ===";

    CURL *curl = curl_easy_init();
    if (curl) {
        qDebug() << "libcurl initialized successfully";

        // Получаем информацию о версии
        curl_version_info_data *ver = curl_version_info(CURLVERSION_NOW);
        qDebug() << "Version:" << ver->version;
        qDebug() << "SSL support:" << (ver->features & CURL_VERSION_SSL ? "YES" : "NO");
        qDebug() << "HTTP/2 support:" << (ver->features & CURL_VERSION_HTTP2 ? "YES" : "NO");

        curl_easy_cleanup(curl);
    } else {
        qDebug() << "Failed to initialize libcurl";
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //qDebug() << "=== Starting application tests ===";

    // Тестируем подключения
    testPostgreSQLConnection();
    testCurlFunctionality();

    // Запускаем главное окно
    MainWindow w;
    w.show();

    qDebug() << "=== All tests completed ===";

    return a.exec();
}




/*
 *
 *пока не знаю куда это вставлять
 *
#include <curl/curl.h>
#include <pqxx/pqxx>
#include "Сurrency_Сontainer.h"
#include "config_parser.h"
#include "DATABASE.h"
#include "Write_to_file.h"

static size_t WriteCallback(void* contents, size_t size, size_t nmeb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmeb);
    return size * nmeb;
}

std::string encode_date(const std::string& date)
{
    std::string encoded = date;
    // Заменяем / на %2F
    size_t pos = 0;
    while ((pos = encoded.find('/', pos)) != std::string::npos)
    {
        encoded.replace(pos, 1, "%2F");
        pos += 3;
    }
    return encoded;
}



int main()
{
    setlocale(LC_ALL, "ru");

    std::string date, XmlData;
    std::vector<Currence> DataCurr;
    const std::string base_url = "https://www.cbr.ru/scripts/XML_daily.asp?date_req=";

    CURL* curl;
    //Выполняем запрос
    CURLcode resultat; /*Объект куда будет записанны данные*/

/*
curl = curl_easy_init();

date = "02/03/2002";

std::string encoded_date = encode_date(date);
std::string full_url = base_url + encoded_date;

if (!curl)
{
    std::cerr << "Error CURL!\n";
    return 1;
}

if (curl)
{
    //Задаем URL адрес
    curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());

    //Говорит libcurl использовать функцию для сохранения данных
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &XmlData);

    resultat = curl_easy_perform(curl);

    if (resultat != CURLE_OK)
    {
        std::cerr << "Error CURL " << curl_easy_strerror(resultat) << std::endl;
    }

    //Закрываем дескриптор
    curl_easy_cleanup(curl);
}


SubstrCurrensiFromXML(XmlData, DataCurr);
WriteFile(DataCurr);
ConnectedBD(DataCurr);

return 0;
}

*/


