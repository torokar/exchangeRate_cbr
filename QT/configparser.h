#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include <QLatin1String>
#include "container.h"

class ConfigParser
{
public:
    ConfigParser() = default;

    static void substrCurrensiFromXML(const QByteArray& xmlData, QVector<Currency>& result,
                                      const QString& date);

private:
    static bool checkForDuplicates(const QVector<Currency>& data, const QString& name,
                                   const double& value, const QString& charcode);
};

#endif // CONFIGPARSER_H
