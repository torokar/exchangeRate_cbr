#include "qtprogresbar.h"

QTProgresBar::QTProgresBar(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant QTProgresBar::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex QTProgresBar::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex QTProgresBar::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int QTProgresBar::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int QTProgresBar::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant QTProgresBar::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
