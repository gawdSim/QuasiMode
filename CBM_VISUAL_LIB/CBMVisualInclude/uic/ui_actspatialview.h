/********************************************************************************
** Form generated from reading UI file 'actspatialview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTSPATIALVIEW_H
#define UI_ACTSPATIALVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActSpatialViewClass
{
public:

    void setupUi(QWidget *ActSpatialViewClass)
    {
        if (ActSpatialViewClass->objectName().isEmpty())
            ActSpatialViewClass->setObjectName(QString::fromUtf8("ActSpatialViewClass"));
        ActSpatialViewClass->resize(400, 300);

        retranslateUi(ActSpatialViewClass);

        QMetaObject::connectSlotsByName(ActSpatialViewClass);
    } // setupUi

    void retranslateUi(QWidget *ActSpatialViewClass)
    {
        ActSpatialViewClass->setWindowTitle(QApplication::translate("ActSpatialViewClass", "ActSpatialView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActSpatialViewClass: public Ui_ActSpatialViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTSPATIALVIEW_H
