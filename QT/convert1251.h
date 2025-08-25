#ifndef CONVERT1251_H
#define CONVERT1251_H
#include <string>
#include <iconv.h>
#include <cerrno>
#include <cstring>
#include <iostream>


class Convert1251
{
public:
    Convert1251() = default;

private:

    static std::string ConvertCP1251ToUTF8(const std::string& cp1251Str);
};

#endif // CONVERT1251_H
