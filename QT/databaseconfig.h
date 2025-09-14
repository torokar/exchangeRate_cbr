#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H
#include "container.h"

class DataBaseConfig
{
public:
    DataBaseConfig() = default;
    static void connectedDb(const QVector<Currency>& Data);
};

#endif // DATABASECONFIG_H
