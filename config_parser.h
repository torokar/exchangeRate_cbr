#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Ñurrency_Ñontainer.h"

void SubstrCurrensiFromXML(const std::string nameValue, const std::string XMLdata)
{
	std::string name_value;
	size_t Value_Start = XMLdata.find(nameValue);
	size_t Value_end = XMLdata.find("</", Value_Start);
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos = Value_end - Value_Start;
		name_value = XMLdata.substr(Value_Start, end_pos);
		std::cout << name_value;
	}
}

void Choice_Name_Value()
{
	int number_currenci;
	std::cout << "Âûáåðèòå âàëþòó: ";
	std::cin >> number_currenci;

	switch (number_currenci)
	{
	case 1:


	default:
		break;
	}



}