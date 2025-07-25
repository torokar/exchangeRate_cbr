#include <curl/curl.h>
#include <pqxx/pqxx>
#include "Сurrency_Сontainer.h"
#include "config_parser.h"
#include "DATABASE.h"
#include "Write_to_file.h"

static size_t WriteCallback(void* contents, size_t size, size_t nmeb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmeb);
	return size * nmeb;
}

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
	
	date = "02/03/2002";
	
	std::string encoded_date = encode_date(date);
	std::string full_url = base_url + encoded_date;

	if (!curl)
	{
		std::cerr << "Error CURL!\n";
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
			std::cerr << "Error CURL " << curl_easy_strerror(resultat) << std::endl;
		}

		//Закрываем дескриптор
		curl_easy_cleanup(curl);
	}


	SubstrCurrensiFromXML(XmlData, DataCurr);
	WriteFile(DataCurr);
	ConnectedBD(DataCurr);

	return 0;
}
