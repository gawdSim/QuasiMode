/********************************************************************************
** Form generated from reading UI file 'bufdispwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUFDISPWINDOW_H
#define UI_BUFDISPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BufDispWindowClass
{
public:

    void setupUi(QWidget *BufDispWindowClass)
    {
        if (BufDispWindowClass->objectName().isEmpty())
            BufDispWindowClass->setObjectName(QString::fromUtf8("BufDispWindowClass"));
        BufDispWindowClass->resize(400, 300);

        retranslateUi(BufDispWindowClass);

        QMetaObject::connectSlotsByName(BufDispWindowClass);
    } // setupUi

    void retranslateUi(QWidget *BufDispWindowClass)
    {
        BufDispWindowClass->setWindowTitle(QApplication::translate("BufDispWindowClass", "BufDispWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BufDispWindowClass: public Ui_BufDispWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUFDISPWINDOW_H
