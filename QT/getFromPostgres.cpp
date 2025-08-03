#include "getFromPostgres.h"
#include <pqxx/pqxx>
#include <QDebug>

void readDataTable()
{
    try {
        pqxx::connection conn(
            "host=localhost "
            "port=5432 "
            "dbname=mydb "
            "user=service "
            "password=11111111 "
            "options='-c client_encoding=UTF8'"
            );

        if (conn.is_open()) {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT * FROM exdc;");

            for(const auto& row : res) {
                qDebug() << "Date:" << QString::fromStdString(row["Date"].as<std::string>())
                         << "CharCode:" << QString::fromStdString(row["CharCode"].as<std::string>());
            }
        }
    } catch (const std::exception& e) {
        qDebug() << "Error:" << e.what();
    }
}
