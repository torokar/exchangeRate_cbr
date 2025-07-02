#pragma once
#include <curl/curl.h>
#include <pqxx/pqxx>
#include "Сurrency_Сontainer.h"
#include "mistake.h"
#include "config_parser.h"
#include "DATABASE.h"
#include <fstream>

//recording data into a file received from the website of the Central Bank of Russia
void WriteFile(const std::vector<Currence>& data)
{
    std::ofstream out("data_file/data.txt", std::ios::out | std::ios::binary);

    if (out.is_open())
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::string value_fixed = data[i].Value;
            std::replace(value_fixed.begin(), value_fixed.end(), ',', '.');

            std::string request = "insert into exc (CharCode, NameCurrency, Value) values ('";
            request += data[i].CharCode;
            request += "', '";
            request += data[i].Name_currence;
            request += "', '";
            request += value_fixed;
            request += "');";

            out << request << std::endl;
        }
        std::cout << "The data has been written to the file.!" << std::endl;
    }
    else
    {
        std::cerr << "Data was not written to the file.!\n";
    }

    out.close();
}
