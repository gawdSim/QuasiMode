/********************************************************************************
** Form generated from reading UI file 'acttemporalview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTTEMPORALVIEW_H
#define UI_ACTTEMPORALVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActTemporalViewClass
{
public:

    void setupUi(QWidget *ActTemporalViewClass)
    {
        if (ActTemporalViewClass->objectName().isEmpty())
            ActTemporalViewClass->setObjectName(QString::fromUtf8("ActTemporalViewClass"));
        ActTemporalViewClass->resize(400, 300);

        retranslateUi(ActTemporalViewClass);

        QMetaObject::connectSlotsByName(ActTemporalViewClass);
    } // setupUi

    void retranslateUi(QWidget *ActTemporalViewClass)
    {
        ActTemporalViewClass->setWindowTitle(QApplication::translate("ActTemporalViewClass", "ActTemporalView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActTemporalViewClass: public Ui_ActTemporalViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTTEMPORALVIEW_H
