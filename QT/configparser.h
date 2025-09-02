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

    static void SubstrCurrensiFromXML(const QByteArray& xmlData, QVector<Currence>& result,
                                      const QString& date);

private:
    //функции
    static bool CheckForDuplicates(const QVector<Currence>& data, const QString& name,
                                   const double& value, const QString& charcode);
};

#endif // CONFIGPARSER_H
