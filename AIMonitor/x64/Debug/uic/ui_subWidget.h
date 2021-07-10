/********************************************************************************
** Form generated from reading UI file 'SubWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWIDGET_H
#define UI_SUBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWidget
{
public:

    void setupUi(QWidget *SubWidget)
    {
        if (SubWidget->objectName().isEmpty())
            SubWidget->setObjectName(QStringLiteral("SubWidget"));
        SubWidget->resize(400, 300);

        retranslateUi(SubWidget);

        QMetaObject::connectSlotsByName(SubWidget);
    } // setupUi

    void retranslateUi(QWidget *SubWidget)
    {
        SubWidget->setWindowTitle(QApplication::translate("SubWidget", "SubWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SubWidget: public Ui_SubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWIDGET_H
