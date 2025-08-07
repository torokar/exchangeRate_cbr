#ifndef CONVERTCP1251_H
#define CONVERTCP1251_H

#include <iostream>
#include <iconv.h>
#include <cerrno>
#include <cstring>

// Функция преобразования CP1251 -> UTF-8
inline std::string ConvertCP1251ToUTF8(const std::string& cp1251Str) {
    iconv_t cd = iconv_open("UTF-8", "CP1251");
    if (cd == (iconv_t)-1) {
        std::cerr << "Error opening iconv: " << strerror(errno) << std::endl;
        return cp1251Str;
    }

    size_t inbytesleft = cp1251Str.size();
    char* inbuf = const_cast<char*>(cp1251Str.data());
    size_t outbytesleft = inbytesleft * 4; // UTF-8 max size
    std::string out(outbytesleft, '\0');
    char* outbuf = &out[0];

    if (iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft) == (size_t)-1) {
        std::cerr << "Conversion error: " << strerror(errno) << std::endl;
        iconv_close(cd);
        return cp1251Str;
    }

    iconv_close(cd);
    out.resize(out.size() - outbytesleft);
    return out;
}


#endif // CONVERTCP1251_H
