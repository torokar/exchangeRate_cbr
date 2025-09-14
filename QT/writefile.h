#ifndef WRITEFILE_H
#define WRITEFILE_H
#include <container.h>

class WriteFile
{
public:
    WriteFile() = default;
    static void writeToFile(const QVector<Currency>& data);
    static void saveXml (QByteArray& xmlData, const QString& fileName);
private:
    static QString lengthCheck(const QString& string);
};

#endif // WRITEFILE_H
