#pragma once
#include "Сurrency_Сontainer.h"
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>

void ConnectedBD(const std::vector<Currence>& data)
{
    pqxx::connection conn("dbname= mydb user=postgres password=20ufodop1 host=127.0.0.1 port=5432");
    try {
        if (conn.is_open()) {
            std::cout << "Óñïåøíîå ïîäêëþ÷åíèå ê áàçå: " << conn.dbname() << std::endl;
        }
        else {
            std::cout << "Îøèáêà ïîäêëþ÷åíèÿ." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Îøèáêà: " << e.what() << std::endl;
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
        std::cout << "Îøèáêà " << ex.what() << std::endl;
    }


    txn.exec("insert into exdc (CharCode, NameCurrency, Value) values ('RUS', 'âûçàåáàëèìåíÿ', '213');");

    //std::ifstream file("data_file/data.txt");
    //if (!file.is_open())
    //{
    //    std::cerr << "Íå óäàëîñü îòêðûòü ôàéë" << std::endl;
    //    return;
    //}

    //std::string DataFromFile;
    //while (std::getline(file, DataFromFile))
    //{
    //    if (!DataFromFile.empty())
    //    {
    //        txn.exec(DataFromFile);
    //    }
    //}

    txn.commit();

}


//#include <pqxx/pqxx>
//#include <iostream>
//#include <locale>
//#include <clocale>
//
//void Con(const std::vector<Currence>& data) {
//    try {
//        // Óñòàíàâëèâàåì ëîêàëü äëÿ êîíñîëè è ïðîãðàììû
//        std::setlocale(LC_ALL, "ru_RU.UTF-8");
//        std::locale::global(std::locale("ru_RU.UTF-8"));
//        std::cout.imbue(std::locale());
//
//        // Ïîäêëþ÷àåìñÿ ê ÁÄ
//        pqxx::connection conn("dbname=your_database_name user=postgres password=20ufodop1 host=127.0.0.1 port=5432");
//
//        // Ïðîâåðÿåì ñîåäèíåíèå
//        if (!conn.is_open()) {
//            throw std::runtime_error("Íå óäàëîñü ïîäêëþ÷èòüñÿ ê áàçå äàííûõ");
//        }
//
//        // Óñòàíàâëèâàåì êîäèðîâêó ñîåäèíåíèÿ
//        pqxx::nontransaction set_enc(conn);
//        set_enc.exec("SET client_encoding TO 'UTF-8'");
//        set_enc.commit();
//
//        pqxx::work txn(conn);
//
//        // Ñîçäà¸ì òàáëèöó (ïîëíóþ âåðñèþ)
//        txn.exec(
//            "CREATE TABLE IF NOT EXISTS exc("
//            "CharCode VARCHAR(3) NOT NULL, "
//            "NameCurrency VARCHAR(50) NOT NULL, "
//            "Value VARCHAR(12) NOT NULL)");
//
//        // Âñòàâëÿåì äàííûå - 3 ðàçíûõ ñïîñîáà:
//
//        // 1. Ïðÿìîé SQL ñ ðóññêèì òåêñòîì
//        txn.exec("INSERT INTO exc (CharCode, NameCurrency, Value) VALUES ('RUR', 'Ðóáëü', '1.00')");
//
//        txn.commit();
//        std::cout << "Äàííûå äîáàâëåíû!\n";
//
//    }
//    catch (const std::exception& e)
//    {
//        std::cerr << "Îøèáêà " << e.what() << std::endl;
//    }
//}
