#pragma once

#include "Ñurrency_Ñontainer.h"
#include <pqxx/pqxx>
#include <iostream>

void ConnectDB(const std::vector<Currence>& data)
{
	pqxx::connection conn("dbname=mydb user=postgres password=20ufodop1 host=127.0.0.1 port=5432");
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
	txn.exec("CREATE TABLE IF NOT EXISTS exchange_rate ("
		"CharCode VARCHAR(3) PRIMARY KEY, "
		"NameCurrency VARCHAR(50) NOT NULL, "
		"Value VARCHAR(13) NOT NULL)");


	for (int i = 0; i < data.size(); i++)
	{
		std::string charCode = data[i].CharCode;  
		std::string name = data[i].Name_currence;
		double value = data[i].Value;		
			
		std::string query = "insert into exchange_rate (CharCode, NameCurrency, Value) values ('" +
			charCode + "', '" + name + "', '" + value + "');";

		std::cout << query;

		txn.exec(query);
	}
		txn.commit();


	//pqxx::nontransaction NT(conn);
	//pqxx::result res = NT.exec("SELECT id, name, age FROM users");

	//std::cout << res.size() << std::endl;

	//for (const auto& row : res)
	//{
	//	std::cout << row[0].as<int>() << std::endl;
	//	std::cout << row[1].as<std::string>() << std::endl;
	//	std::cout << row[2].as<int>() << std::endl;
	//}

}