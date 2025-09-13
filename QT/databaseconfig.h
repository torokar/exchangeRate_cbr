#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H
#include <pqxx/pqxx>
#include <iconv.h>
#include <cerrno>
#include <cstring>
#include <QVector>
#include <QMessageBox>
#include "container.h"

class DataBaseConfig
{
public:
    DataBaseConfig() = default;
    static void connectedDb(const QVector<Currence>& Data);
};

#endif // DATABASECONFIG_H
