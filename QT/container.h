#ifndef CONTAINER_H
#define CONTAINER_H
#pragma once
#include <QString>
#include <QByteArray>

struct Currence
{
    QString CharCode;
    QString Name_currence;
    double Value;
    QString Date;
    QByteArray xmlData;
};
#endif // CONTAINER_H
