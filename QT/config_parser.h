#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H
#pragma once
#include <string>
#include <vector>
#include "container.h""


//Парсинг данных с сайта
//Проверка на дубликаты
inline bool CheckForDuplicates(const std::vector<Currence>& data, const std::string& name,
                        const std::string& value, const std::string& charcode)
{
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i].Name_currence == name || data[i].Value == value || data[i].CharCode == charcode)
        {
            return true;
        }
    }
    return false;
}


//Вытягивание данных с сайта ЦБ России
inline void SubstrCurrensiFromXML(const std::string XMLdata
                           , std::vector<Currence>& conclusion)
{

    Currence curr;
    std::string name_curr, exchange_rate, CharCode, Date;
    std::string subNameCurrencsi = XMLdata;

    size_t end_pos;
    size_t pos = 0;
    size_t end_cycle = subNameCurrencsi.find("</ValCurs>");

    //Извлечения даты
    size_t Value_Start = subNameCurrencsi.find("Date=");
    size_t Value_end = subNameCurrencsi.find("name=");
    if (Value_Start != std::string::npos && Value_end != std::string::npos)
    {
        end_pos = Value_end - Value_Start;
        Date = subNameCurrencsi.substr(Value_Start + 5, end_pos - 5);
        curr.Date = Date;
    }

    while (true)
    {
        //Извлечения краткого названия валюты
        Value_Start = subNameCurrencsi.find("<CharCode>");
        Value_end = subNameCurrencsi.find("</CharCode>");
        if (Value_Start != std::string::npos && Value_end != std::string::npos)
        {
            end_pos = Value_end - Value_Start;
            CharCode = subNameCurrencsi.substr(Value_Start + 10, end_pos - 10);
            curr.CharCode = CharCode;
        }

        //Извлечения названия валюты
        Value_Start = subNameCurrencsi.find("<Name>");
        Value_end = subNameCurrencsi.find("</Name>");
        if (Value_Start != std::string::npos && Value_end != std::string::npos)
        {
            end_pos = Value_end - Value_Start;
            name_curr = subNameCurrencsi.substr(Value_Start + 6, end_pos - 6);
            curr.Name_currence = name_curr;
        }

        //Извлечения значения валютыa
        Value_Start = subNameCurrencsi.find("<Value>");
        Value_end = subNameCurrencsi.find("</Value>");
        if (Value_Start != std::string::npos && Value_end != std::string::npos)
        {
            end_pos = Value_end - Value_Start;
            exchange_rate = subNameCurrencsi.substr(Value_Start + 7, end_pos - 7);
            curr.Value = exchange_rate;
        }

        if (CheckForDuplicates(conclusion, name_curr, exchange_rate, CharCode) == false)
        {
            conclusion.push_back(curr);
        }

        //Обрезка обработаную часть
        subNameCurrencsi = subNameCurrencsi.substr(Value_end + 10); //Решение 1.1

        if (subNameCurrencsi.find("</Value>") == std::string::npos || subNameCurrencsi.size() < 10) //Решение 1.0
        {
            break;
        }

    }
}
#endif // CONFIG_PARSER_H
