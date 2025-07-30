#ifndef GETFROMPOSTGRES_H
#define GETFROMPOSTGRES_H
#include <container.h>
#include <pqxx/pqxx>
#include <DATABASE.h>

inline void readDataTable()
{
    try {
        //Подключение к базе
        pqxx::connection conn(
            "host=localhost "
            "port=5432 "
            "dbname=mydb "
            "user=service "
            "password=11111111 "
            "options='-c client_encoding=UTF8'"
            );

        if (conn.is_open()) {
            std::cout << "Successful connection to the database: " << conn.dbname() << std::endl;
        } else {
            std::cerr << "Error connection." << std::endl;
            return;
        }

        pqxx::work txn(conn);
        pqxx::result res = txn.exec("SELECT * FROM exdc;");

        for(const auto& row : res)
        {
            std::cout << "Date: " << row["Date"].as<std::string>()
                      << ", CharCode: " << row["CharCode"].as<std::string>()
                      << ", NameCur: " << row["NameCurrency"].as<std::string>()
                      << ", Value: " << row["Value"].as<std::string>()
                      <<  std::endl;

        }

        txn.commit();

    }
    catch (const std::exception& e) {
        std::cerr << "Error(#1): " << e.what() << std::endl;
    }

}

#endif // GETFROMPOSTGRES_H
