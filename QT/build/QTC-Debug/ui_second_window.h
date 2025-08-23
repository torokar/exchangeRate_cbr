/********************************************************************************
** Form generated from reading UI file 'second_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *write;
    QPushButton *graph;

    void setupUi(QDialog *second_window)
    {
        if (second_window->objectName().isEmpty())
            second_window->setObjectName("second_window");
        second_window->resize(567, 528);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("zoom-in");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        second_window->setWindowIcon(icon);
        second_window->setInputMethodHints(Qt::ImhNone);
        second_window->setModal(false);
        tableView = new QTableView(second_window);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 561, 501));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        tableView->setSortingEnabled(true);
        widget = new QWidget(second_window);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 500, 222, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        write = new QPushButton(widget);
        write->setObjectName("write");

        horizontalLayout->addWidget(write);

        graph = new QPushButton(widget);
        graph->setObjectName("graph");

        horizontalLayout->addWidget(graph);


        retranslateUi(second_window);

        QMetaObject::connectSlotsByName(second_window);
    } // setupUi

    void retranslateUi(QDialog *second_window)
    {
        second_window->setWindowTitle(QCoreApplication::translate("second_window", "Currence", nullptr));
        write->setText(QCoreApplication::translate("second_window", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        graph->setText(QCoreApplication::translate("second_window", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class second_window: public Ui_second_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_WINDOW_H
