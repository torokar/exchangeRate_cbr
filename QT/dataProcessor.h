#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <string>
#include <vector>
#include <container.h>

class DataPro : public QObject
{
    Q_OBJECT
public:
    explicit DataPro(const std::string& xmlData, QObject* parent)
};

#endif // DATAPROCESSOR_H
