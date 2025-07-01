#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Сurrency_Сontainer.h"


//Проверка на дубликаты
bool CheckForDuplicates(const std::vector<Currence>& data, const std::string& name,
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


void SubstrCurrensiFromXML(const std::string XMLdata
	, std::vector<Currence>& conclusion)
{
	{
		/*
			Парсинг валюты значения и его сокращенного названия и запись его в структуру

			****************************************************************************
			Вообщем вся логика держиться только на заголовка которые поступают с сайта ЦентральногоБанкаРоссии
			в формате XML т.е нужные значения помещаются между двумя строками
			Например: <Name>Фунт стерлингов</Name>
			Я записываю из поступающего файла в формате XML в обычную строку(string)
			и ищу в этой строке ключевые слова Например: <Value> и </Value> и вырезаю значения между в отдельную строковую переменную
			после я обрезаю всю строку с данными до значения </Value> и пушу его в структуру

			Логика работы:
			1) Последовательно ищет в XML-строке теги для каждой валюты
			2) Извлекает значения между тегами с помощью substr()
			3) Сохраняет данные в структуру Currence и добавляет в вектор

			Особенности реализации:
			1) После обработки каждой валюты обрезает обработанную часть XML-строки
			1) Цикл продолжается, пока не достигнет конца данных (тег </ValCurs>)

			Проблемы:
			1)Я не мог завершить корректно цикл, который проходил через весь файл решения 1.0 получался либо бесконечный цикл, либо он завершал работу сразу
			2)Не мог корректно обрезать строку, после первого прохода, потому что после обрезка функция substr() возвращала 0 т.к </Value> после обрезки находился
			сразу на 0 позиции и получается что в расчетах Пример: size_t end_pos_cur = Value_end - Value_Start. Значение Value_end принимало 0 а Value_Start = 141(случайное значение)
			Решение: 1.1 я просто взял и прибавил к значению размер значения </Value>. Надеюсь объяснения получилось нормальным =)
		*/
	}

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

		//Извлечения значения валюты
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
