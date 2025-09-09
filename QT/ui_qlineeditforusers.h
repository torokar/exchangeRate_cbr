/********************************************************************************
** Form generated from reading UI file 'qlineeditforusers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLINEEDITFORUSERS_H
#define UI_QLINEEDITFORUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QLineEditForUsers
{
public:
    QLineEdit *Path;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonPath;
    QPushButton *pushButtonPath_2;

    void setupUi(QDialog *QLineEditForUsers)
    {
        if (QLineEditForUsers->objectName().isEmpty())
            QLineEditForUsers->setObjectName(QString::fromUtf8("QLineEditForUsers"));
        QLineEditForUsers->resize(261, 79);
        Path = new QLineEdit(QLineEditForUsers);
        Path->setObjectName(QString::fromUtf8("Path"));
        Path->setGeometry(QRect(60, 10, 191, 31));
        label = new QLabel(QLineEditForUsers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 51, 16));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        widget = new QWidget(QLineEditForUsers);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 241, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPath = new QPushButton(widget);
        pushButtonPath->setObjectName(QString::fromUtf8("pushButtonPath"));

        horizontalLayout->addWidget(pushButtonPath);

        pushButtonPath_2 = new QPushButton(widget);
        pushButtonPath_2->setObjectName(QString::fromUtf8("pushButtonPath_2"));

        horizontalLayout->addWidget(pushButtonPath_2);


        retranslateUi(QLineEditForUsers);

        QMetaObject::connectSlotsByName(QLineEditForUsers);
    } // setupUi

    void retranslateUi(QDialog *QLineEditForUsers)
    {
        QLineEditForUsers->setWindowTitle(QCoreApplication::translate("QLineEditForUsers", "Path Input", nullptr));
        label->setText(QCoreApplication::translate("QLineEditForUsers", "Path:", nullptr));
        pushButtonPath->setText(QCoreApplication::translate("QLineEditForUsers", "\320\222\320\262\320\276\320\264", nullptr));
        pushButtonPath_2->setText(QCoreApplication::translate("QLineEditForUsers", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLineEditForUsers: public Ui_QLineEditForUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLINEEDITFORUSERS_H
