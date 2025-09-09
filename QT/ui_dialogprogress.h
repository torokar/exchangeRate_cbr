/********************************************************************************
** Form generated from reading UI file 'dialogprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPROGRESS_H
#define UI_DIALOGPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogProgress
{
public:

    void setupUi(QDialog *DialogProgress)
    {
        if (DialogProgress->objectName().isEmpty())
            DialogProgress->setObjectName(QString::fromUtf8("DialogProgress"));
        DialogProgress->resize(400, 300);

        retranslateUi(DialogProgress);

        QMetaObject::connectSlotsByName(DialogProgress);
    } // setupUi

    void retranslateUi(QDialog *DialogProgress)
    {
        DialogProgress->setWindowTitle(QCoreApplication::translate("DialogProgress", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogProgress: public Ui_DialogProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPROGRESS_H
