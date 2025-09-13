#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include "container.h"
#include <QXmlStreamReader>
#include <QDebug>
#include <QLatin1String>

class ConfigParser
{
public:
    ConfigParser() = default;

    static void substrCurrensiFromXML(const QByteArray& xmlData, QVector<Currence>& result,
                                      const QString& date);

private:
    static bool checkForDuplicates(const QVector<Currence>& data, const QString& name,
                                   const double& value, const QString& charcode);
};

#endif // CONFIGPARSER_H
