#include "convert1251.h"
#include <iostream>

// Функция преобразования CP1251 -> UTF-8
std::string Convert1251::ConvertCP1251ToUTF8(const std::string& cp1251Str) {
    iconv_t cd = iconv_open("UTF-8", "CP1251");
    if (cd == (iconv_t)-1) {
        std::cerr << "Error opening iconv: " << strerror(errno) << std::endl;
        return cp1251Str;
    }

    size_t inbytesleft = cp1251Str.size();
    char* inbuf = const_cast<char*>(cp1251Str.data());
    size_t outbyresleft = inbytesleft * 4;
    std::string out(outbyresleft, '\0');
    char* outbuf = &out[0];

    if (iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbyresleft) == (size_t)-1) {
        std::cerr << "Conversion error: " << strerror(errno) << std::endl;
        iconv_close(cd);
        return cp1251Str;
    }

    iconv_close(cd);
    out.resize(out.size() - outbyresleft);
    return out;
}
