#include "data_processor.h"
#include "container.h"
#include "config_parser.h"
#include "write_to_file.h"
#include "DATABASE.h"

DataProcessor::DataProcessor(QObject *parent) : QObject(parent) {}

void DataProcessor::processData(const std::string &xmlData)
{
    try {
        std::vector<Currence> data;
        SubstrCurrensiFromXML(xmlData, data);
        WriteFile(data);
        ConnectedBD(data);
        emit processingFinished();
    } catch (const std::exception &e) {
        emit errorOccurred(QString("Ошибка: %1").arg(e.what()));
    }
}
