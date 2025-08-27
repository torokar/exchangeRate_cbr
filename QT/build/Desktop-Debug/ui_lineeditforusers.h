/********************************************************************************
** Form generated from reading UI file 'lineeditforusers.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEEDITFORUSERS_H
#define UI_LINEEDITFORUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_LineEditForUsers
{
public:

    void setupUi(QDialog *LineEditForUsers)
    {
        if (LineEditForUsers->objectName().isEmpty())
            LineEditForUsers->setObjectName("LineEditForUsers");
        LineEditForUsers->resize(400, 300);

        retranslateUi(LineEditForUsers);

        QMetaObject::connectSlotsByName(LineEditForUsers);
    } // setupUi

    void retranslateUi(QDialog *LineEditForUsers)
    {
        LineEditForUsers->setWindowTitle(QCoreApplication::translate("LineEditForUsers", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineEditForUsers: public Ui_LineEditForUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEEDITFORUSERS_H
