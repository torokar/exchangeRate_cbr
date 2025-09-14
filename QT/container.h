#ifndef CONTAINER_H
#define CONTAINER_H
#include <QString>
#include <QByteArray>

struct Currency
{
    QString CharCode;
    QString NameCurrency;
    double Value;
    QString Date;
    QByteArray xmlData;
};
#endif // CONTAINER_H
