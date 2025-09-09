/********************************************************************************
** Form generated from reading UI file 'customgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMGRAPH_H
#define UI_CUSTOMGRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "../lib/qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CustomGraph
{
public:
    QCustomPlot *widget;

    void setupUi(QDialog *CustomGraph)
    {
        if (CustomGraph->objectName().isEmpty())
            CustomGraph->setObjectName(QString::fromUtf8("CustomGraph"));
        CustomGraph->resize(600, 433);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("appointment-new")));
        CustomGraph->setWindowIcon(icon);
        widget = new QCustomPlot(CustomGraph);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 10, 581, 411));

        retranslateUi(CustomGraph);

        QMetaObject::connectSlotsByName(CustomGraph);
    } // setupUi

    void retranslateUi(QDialog *CustomGraph)
    {
        CustomGraph->setWindowTitle(QCoreApplication::translate("CustomGraph", "Currence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomGraph: public Ui_CustomGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMGRAPH_H
