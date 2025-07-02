#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>
#include "Сurrency_Сontainer.h"

// Функция преобразования CP1251 -> UTF-8
/*std::string ConvertCP1251ToUTF8(const std::string& cp1251Str) {
    int wsize = MultiByteToWideChar(1251, 0, cp1251Str.c_str(), -1, NULL, 0);
    std::wstring wstr(wsize, 0);
    MultiByteToWideChar(1251, 0, cp1251Str.c_str(), -1, &wstr[0], wsize);

    int utf8size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    std::string utf8str(utf8size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &utf8str[0], utf8size, NULL, NULL);

    // Убираем нулевые байты в конце
    utf8str.resize(utf8str.size() - 1);
    return utf8str;
}*/

void ConnectedBD(const std::vector<Currence>& data) {
    std::vector<std::string> curr;
    std::vector<std::string> curr2;
    std::vector<std::string> curr3;

    for (const auto& currency : data) {
        curr.push_back(currency.CharCode);
        curr2.push_back(currency.Name_currence);
        curr3.push_back(currency.Value);
    }

    try {
        pqxx::connection conn(
            "host=localhost "
            "port=5432 "
            "dbname=mydb "
            "user=service "
            "password=20ufodop1 "
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

        txn.exec(
            "CREATE TABLE IF NOT EXISTS exdc ("
            "CharCode VARCHAR(10) NOT NULL, "
            "NameCurrency VARCHAR(50) NOT NULL, "
            "Value VARCHAR(50) NOT NULL)"
        );

        for (size_t i = 0; i < curr.size(); ++i) {
            txn.exec_params(
                "INSERT INTO exdc (CharCode, NameCurrency, Value) VALUES ($1, $2, $3)",
                curr[i],
                curr2[i],  // добавляем название в UTF-8
                curr3[i]
            );
        }

        txn.commit();
        std::cout << "The data has been sent to the database.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error(#1): " << e.what() << std::endl;
    }
}

