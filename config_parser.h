#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Сurrency_Сontainer.h"

void SubstrCurrensiFromXML(/*const std::string nameValue,*/ const std::string XMLdata
	, std::vector<Currence>&conclusion)
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
	
	std::string name_curr, exchange_rate, CharCode;
	std::string subNameCurrencsi = XMLdata;
	
	size_t pos = 0;
	size_t end_cycle = subNameCurrencsi.find("</ValCurs>");
	while (true)
	{
		Currence curr;

		//Извлечения названия валюты
		size_t Value_Start = subNameCurrencsi.find("<Name>");
		size_t Value_end = subNameCurrencsi.find("</Name>");
		if (Value_Start != std::string::npos && Value_end != std::string::npos)
		{
			size_t end_pos = Value_end - Value_Start;
			name_curr = subNameCurrencsi.substr(Value_Start + 6, end_pos - 6);
			curr.Name_currence = name_curr;
			std::cout << name_curr;
		}

		//Извлечения значения валюты
		Value_Start = subNameCurrencsi.find("<Value>");
		Value_end = subNameCurrencsi.find("</Value>");
		if (Value_Start != std::string::npos && Value_end != std::string::npos)
		{
			size_t end_pos_cur = Value_end - Value_Start;
			exchange_rate = subNameCurrencsi.substr(Value_Start + 7, end_pos_cur - 7);
			std::cout << " " << exchange_rate << " ";
			curr.Value = exchange_rate;
			
		}

		//Извлечения краткого названия валюты
		Value_Start = subNameCurrencsi.find("<CharCode>");
		Value_end = subNameCurrencsi.find("</CharCode>");
		if (Value_Start != std::string::npos && Value_end != std::string::npos)
		{
			size_t end_pos_charCode = Value_end - Value_Start;
			CharCode = subNameCurrencsi.substr(Value_Start + 10, end_pos_charCode - 10);
			std::cout << CharCode << std::endl << std::endl;
			curr.CharCode = CharCode;

		}

		//Обрезка обработаную часть 
		subNameCurrencsi = subNameCurrencsi.substr(Value_end + 7); //Решение 1.1
		
		conclusion.push_back(curr);

		if (subNameCurrencsi.find("</Value>") == std::string::npos || subNameCurrencsi.size() < 10) //Решение 1.0
		{
			break;
		}

	}
}


void Choice_Name_Currencsi()
{
	int number_currenci;
	std::cout << "Выберите валюту: ";
	std::cin >> number_currenci;

	switch (number_currenci)
	{
	case 1:


	default:
		break;
	}



}


/*
while (true)
{
	Currence curr;

	bool hasName = false, hasValue = false, hasCharCode = false;

	// Название валюты
	size_t Value_Start = subNameCurrencsi.find("<Name>");
	size_t Value_end = subNameCurrencsi.find("</Name>");
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos = Value_end - Value_Start;
		name_curr = subNameCurrencsi.substr(Value_Start + 6, end_pos - 6);
		curr.Name_currence = name_curr;
		hasName = true;
		std::cout << name_curr;
	}

	// Значение валюты
	Value_Start = subNameCurrencsi.find("<Value>");
	Value_end = subNameCurrencsi.find("</Value>");
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos_cur = Value_end - Value_Start;
		exchange_rate = subNameCurrencsi.substr(Value_Start + 7, end_pos_cur - 7);
		curr.Value = exchange_rate;
		hasValue = true;
		std::cout << " " << exchange_rate << " ";
	}

	// Код валюты
	Value_Start = subNameCurrencsi.find("<CharCode>");
	Value_end = subNameCurrencsi.find("</CharCode>");
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos_charCode = Value_end - Value_Start;
		CharCode = subNameCurrencsi.substr(Value_Start + 10, end_pos_charCode - 10);
		curr.CharCode = CharCode;
		hasCharCode = true;
		std::cout << CharCode << std::endl << std::endl;
	}

	// Добавляем только если нашли всё
	if (hasName && hasValue && hasCharCode)
	{
		conclusion.push_back(curr);
		// обрезаем только после успешной обработки
		subNameCurrencsi = subNameCurrencsi.substr(Value_end + 7);
	}
	else
	{
		break; // если какой-то из тегов не найден — значит конец данных
	}

	if (subNameCurrencsi.find("</Value>") == std::string::npos || subNameCurrencsi.size() < 10)
	{
		break;
	}
}



*/