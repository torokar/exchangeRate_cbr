/*
Цель: Получить курс доллара с публичного API и вывести его в консоль.


API центробанка https://cbr.ru/scripts/XML_daily.asp?date_req=02/03/2002

*/

#include <curl/curl.h>
#include "Сurrency_Сontainer.h"
#include "mistake.h"
#include "config_parser.h"



static size_t WriteCallback(void* contents, size_t size, size_t nmeb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmeb);
	return size * nmeb;
}
/*
	void*contents - это пачка данных от сервера. Сервер присылает данные не целмком
	а отдельными кусочками
	size_t size и size_t nmeb - размер одного данных (в байтах 1)
	nmeb - сколько таких кусочков пришло
	Вместе size * nmemb - это общий размер данных в этой "пачке"

	void* userp - это коробка для писем в нашем случае std::string куда мы будем складывать данные

	((std::string*)userp)->append - append добавляет новые данные в конец строки (char*)contents
	преобразует данные в текст
	size * nmeb - сколько байт нужно добавить
*/

std::string encode_date(const std::string& date) 
{
	std::string encoded = date;
	// Заменяем / на %2F
	size_t pos = 0;
	while ((pos = encoded.find('/', pos)) != std::string::npos) 
	{
		encoded.replace(pos, 1, "%2F");
		pos += 3;
	}
	return encoded;
}



int main()
{
	setlocale(LC_ALL, "ru");

	std::string date, XmlData;
	std::vector<Currence> DataCurr;
	const std::string base_url = "https://www.cbr.ru/scripts/XML_daily.asp?date_req=";

	CURL* curl;
	//Выполняем запрос
	CURLcode resultat; /*Объект куда будет записанны данные*/
	curl = curl_easy_init();


	std::cout << "Формат ввода даты **02/03/2002**";
	std::cout << "\nВведите дата: ";
	std::getline(std::cin, date);

	std::string encoded_date = encode_date(date);
	std::string full_url = base_url + encoded_date;

	if (!curl)
	{
		std::cerr << "Ошибка CURL!\n";
		return 1;
	}

	if (curl)
	{
		//Задаем URL адрес
		curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());

		//Говорит libcurl использовать функцию для сохранения данных
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &XmlData);

		resultat = curl_easy_perform(curl);

		if (resultat != CURLE_OK)
		{
			std::cerr << "Ошибка CURL " << curl_easy_strerror(resultat) << std::endl;
		}

		//Закрываем дескриптор
		curl_easy_cleanup(curl);
	}


	SubstrCurrensiFromXML(XmlData, DataCurr);
	//Choice_Name_Currencsi();
	

	for (int i = 0; i < DataCurr.size(); i++)
	{
		std::cout << DataCurr[i].CharCode << " " << DataCurr[i].Name_currence << " " << DataCurr[i].Value << "\n";
	}

	return 0;
}

