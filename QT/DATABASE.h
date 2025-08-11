#ifndef DATABASE_H
#define DATABASE_H
#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include <iconv.h>
#include <cerrno>
#include <cstring>
#include <convertCP1251.h>
#include "container.h"
#include <QVector>

inline void ConnectedBD(const QVector<Currence>& Data) {
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
        txn.exec("SET client_encoding TO 'UTF8'");


        try {
            //Создания табли если она не существует
            txn.exec(
                "CREATE TABLE IF NOT EXISTS exdc ("
                "CharCode VARCHAR(10) NOT NULL, "
                "NameCurrency VARCHAR(50) NOT NULL, "
                "Value VARCHAR(50) NOT NULL, "
                "Date DATE NOT NULL, "
                "UNIQUE(Date, CharCode)"
                ")"
                );
        }
        catch (const pqxx::sql_error&e) {
            if(std::string(e.what()).find("already exists") != std::string::npos)
            {
                std::cout << "Table already exists " << std::endl;
                txn.abort();
            }
            else
            {
                throw;
            }
        }

        for (const auto& currency : Data) {
            txn.exec_params(
                "INSERT INTO exdc (CharCode, NameCurrency, Value, Date) "
                "VALUES ($1, $2, $3, $4)"
                "ON CONFLICT (Date, CharCode) DO NOTHING",
                currency.CharCode.toStdString(),
                currency.Name_currence.toStdString(),
                currency.Value.toStdString(),
                currency.Date.toStdString()
                );
        }

        txn.commit();
    }
    catch (const std::exception& e) {
        std::cerr << "Error(#1): " << e.what() << std::endl;
    }
}

#endif // DATABASE_H
