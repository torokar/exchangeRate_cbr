#pragma once
#include "Сurrency_Сontainer.h"
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>

void ConnectedBD(const std::vector<Currence>& data)
{
    pqxx::connection conn("dbname=mydb user=service password=20ufodop1 host=127.0.0.1 port=5432");
    try {
        if (conn.is_open()) {
            std::cout << "Connected to the database: " << conn.dbname() << std::endl;
        }
        else {
            std::cout << "The client is not connected to the database." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error(#1): " << e.what() << std::endl;
    }


    pqxx::work txn(conn);
    try
    {
        txn.exec(
            "CREATE TABLE IF NOT EXISTS exdc ("
            "CharCode VARCHAR(3) NOT NULL, "
            "NameCurrency VARCHAR(50) NOT NULL, "
            "Value VARCHAR(12) NOT NULL)");

        std::cout << "Òàáëèöà ñîçäàíà\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "Îøèáêà(#2) " << ex.what() << std::endl;
    }


    txn.exec("insert into exdc (CharCode, NameCurrency, Value) values ('RUS', 'âûçàåáàëèìåíÿ', '213');");
    txn.commit();

}
