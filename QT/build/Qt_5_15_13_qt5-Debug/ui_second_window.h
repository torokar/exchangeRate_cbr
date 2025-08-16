/********************************************************************************
** Form generated from reading UI file 'second_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_WINDOW_H
#define UI_SECOND_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_second_window
{
public:
    QTableView *tableView;

    void setupUi(QDialog *second_window)
    {
        if (second_window->objectName().isEmpty())
            second_window->setObjectName(QString::fromUtf8("second_window"));
        second_window->resize(776, 528);
        tableView = new QTableView(second_window);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 771, 521));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));

        retranslateUi(second_window);

        QMetaObject::connectSlotsByName(second_window);
    } // setupUi

    void retranslateUi(QDialog *second_window)
    {
        second_window->setWindowTitle(QCoreApplication::translate("second_window", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class second_window: public Ui_second_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_WINDOW_H
