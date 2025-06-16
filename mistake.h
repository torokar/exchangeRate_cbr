#pragma once
#include <iostream>
#include <string>

void Clear()
{
	std::cin.ignore(10000, '\n');
	std::cin.clear();
}