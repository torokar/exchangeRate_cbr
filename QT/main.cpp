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

    // Тестируем подключения
    //testPostgreSQLConnection();
    //testCurlFunctionality();

    // Запускаем главное окно
    MainWindow w;
    w.show();

    return a.exec();
}






