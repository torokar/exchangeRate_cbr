#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H
#include <pqxx/pqxx>
#include <iconv.h>
#include <cerrno>
#include <cstring>
#include <convertCP1251.h>
#include "container.h"
#include <QVector>
#include <QMessageBox>


class DataBaseConfig
{
public:
    DataBaseConfig() = default;
    static void ConnectedBD(const QVector<Currence>& Data);

};

#endif // DATABASECONFIG_H
