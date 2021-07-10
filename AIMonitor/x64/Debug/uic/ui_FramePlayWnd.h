/********************************************************************************
** Form generated from reading UI file 'FramePlayWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEPLAYWND_H
#define UI_FRAMEPLAYWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CFramePlayWndClass
{
public:
    QFrame *framePlayWnd;

    void setupUi(QFrame *CFramePlayWndClass)
    {
        if (CFramePlayWndClass->objectName().isEmpty())
            CFramePlayWndClass->setObjectName(QStringLiteral("CFramePlayWndClass"));
        CFramePlayWndClass->resize(476, 379);
        framePlayWnd = new QFrame(CFramePlayWndClass);
        framePlayWnd->setObjectName(QStringLiteral("framePlayWnd"));
        framePlayWnd->setGeometry(QRect(20, 20, 441, 341));
        framePlayWnd->setFrameShape(QFrame::StyledPanel);
        framePlayWnd->setFrameShadow(QFrame::Raised);

        retranslateUi(CFramePlayWndClass);

        QMetaObject::connectSlotsByName(CFramePlayWndClass);
    } // setupUi

    void retranslateUi(QFrame *CFramePlayWndClass)
    {
        CFramePlayWndClass->setWindowTitle(QApplication::translate("CFramePlayWndClass", "CFramePlayWnd", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CFramePlayWndClass: public Ui_CFramePlayWndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEPLAYWND_H
