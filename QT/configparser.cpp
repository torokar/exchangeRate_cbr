#include "configparser.h"

bool ConfigParser::CheckForDuplicates(const QVector<Currence>& data, const QString& name,
                                      const double& value, const QString& charcode)
{
    for (const auto& item : data) {
        if (item.Name_currence == name || item.Value == value || item.CharCode == charcode) {
            return true;
        }
    }
    return false;
}

void ConfigParser::SubstrCurrensiFromXML(const QByteArray &xmlData, QVector<Currence> &result, const QString &date)
{
    QXmlStreamReader xml(xmlData);
    Currence current;
    bool hasDate = false;

    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();

        if (xml.isStartElement() && xml.name() == QLatin1String("ValCurs")) {
            current.Date = xml.attributes().value("Date").toString();
            hasDate = true;
        }

        if (xml.isStartElement() && xml.name() == QLatin1String("Valute")) {
            current = Currence();
            if (hasDate) {
                current.Date = date;
            }
        }
        else if (xml.isStartElement()) {
            if (xml.name() == QLatin1String("CharCode")) {
                current.CharCode = xml.readElementText();
            }
            else if (xml.name() == QLatin1String("Name")) {
                current.Name_currence = xml.readElementText();
            }
            else if (xml.name() == QLatin1String("Value")) {
                QString valueStr = xml.readElementText();
                valueStr.replace(',','.');

                bool ok;
                double value = valueStr.toDouble(&ok);
                if (ok) {
                    current.Value = value;
                }
                else{
                    qWarning() << "Ошибка вытягивания значения валюты: " << valueStr;
                    current.Value = 0.0;
                }
            }
        }
        else if (xml.isEndElement() && xml.name() == QLatin1String("Valute")) {
            if (!current.CharCode.isEmpty()) {
                if (!CheckForDuplicates(result, current.Name_currence, current.Value, current.CharCode)) {
                    result.append(current);
                }
            }
        }
    }

    if (xml.hasError()) {
        qWarning() << "XML parsing error:" << xml.errorString();
    }
}
