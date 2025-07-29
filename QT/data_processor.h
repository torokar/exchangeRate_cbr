#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
#include <string>
#include <vector>


struct Currence;

class DataProcessor : public QObject
{
    Q_OBJECT
public:
    explicit DataProcessor(QObject *parent = nullptr);

public slots:
    void processData(const std::string &xmlData);

signals:
    void processingFinished();
    void errorOccurred(QString error);
};

#endif
