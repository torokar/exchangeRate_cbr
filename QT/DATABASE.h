#ifndef DATABASE_H
#define DATABASE_H
#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include "container.h"
#include <iconv.h>
#include <cerrno>
#include <cstring>

// Функция преобразования CP1251 -> UTF-8
inline std::string ConvertCP1251ToUTF8(const std::string& cp1251Str) {
    iconv_t cd = iconv_open("UTF-8", "CP1251");
    if (cd == (iconv_t)-1) {
        std::cerr << "Error opening iconv: " << strerror(errno) << std::endl;
        return cp1251Str;
    }

    size_t inbytesleft = cp1251Str.size();
    char* inbuf = const_cast<char*>(cp1251Str.data());
    size_t outbytesleft = inbytesleft * 4; // UTF-8 max size
    std::string out(outbytesleft, '\0');
    char* outbuf = &out[0];

    if (iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft) == (size_t)-1) {
        std::cerr << "Conversion error: " << strerror(errno) << std::endl;
        iconv_close(cd);
        return cp1251Str;
    }

    iconv_close(cd);
    out.resize(out.size() - outbytesleft);
    return out;
}

inline void ConnectedBD(const std::vector<Currence>& data) {
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

        for (const auto& currency : data) {
            txn.exec_params(
                "INSERT INTO exdc (CharCode, NameCurrency, Value, Date) "
                "VALUES ($1, $2, $3, $4)"
                "ON CONFLICT (Date, CharCode) DO NOTHING",
                currency.CharCode,
                ConvertCP1251ToUTF8(currency.Name_currence),
                currency.Value,
                currency.Date
                );
        }

        txn.commit();
        std::cout << "The data has been sent to the database.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error(#1): " << e.what() << std::endl;
    }
}



#endif // DATABASE_H
