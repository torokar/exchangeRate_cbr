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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_second_window
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *write;
    QPushButton *writeXML;
    QPushButton *graph;

    void setupUi(QDialog *second_window)
    {
        if (second_window->objectName().isEmpty())
            second_window->setObjectName(QString::fromUtf8("second_window"));
        second_window->resize(567, 528);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("zoom-in");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        second_window->setWindowIcon(icon);
        second_window->setInputMethodHints(Qt::ImhNone);
        second_window->setModal(false);
        tableView = new QTableView(second_window);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 561, 501));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableView->setSortingEnabled(true);
        layoutWidget = new QWidget(second_window);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 500, 561, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        write = new QPushButton(layoutWidget);
        write->setObjectName(QString::fromUtf8("write"));

        horizontalLayout->addWidget(write);

        writeXML = new QPushButton(layoutWidget);
        writeXML->setObjectName(QString::fromUtf8("writeXML"));

        horizontalLayout->addWidget(writeXML);

        graph = new QPushButton(layoutWidget);
        graph->setObjectName(QString::fromUtf8("graph"));

        horizontalLayout->addWidget(graph);


        retranslateUi(second_window);

        QMetaObject::connectSlotsByName(second_window);
    } // setupUi

    void retranslateUi(QDialog *second_window)
    {
        second_window->setWindowTitle(QCoreApplication::translate("second_window", "Currence", nullptr));
        write->setText(QCoreApplication::translate("second_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\274 \321\204\320\260\320\271\320\273\320\265", nullptr));
        writeXML->setText(QCoreApplication::translate("second_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 XML", nullptr));
        graph->setText(QCoreApplication::translate("second_window", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class second_window: public Ui_second_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_WINDOW_H
