/********************************************************************************
** Form generated from reading UI file 'AIMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIMONITOR_H
#define UI_AIMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIMonitorClass
{
public:
    QAction *action;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QFrame *topFrame;
    QHBoxLayout *top;
    QLabel *projectLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *signalButton;
    QPushButton *closeButton;
    QWidget *contentWidget;
    QHBoxLayout *content;
    QFrame *leftFrame;
    QVBoxLayout *listviewFrame;
    QLabel *monitorLabel;
    QListWidget *listWidget;
    QLabel *videoLabel;
    QFrame *rightFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *dataLabel;
    QFrame *cameralMain;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cameralLabel;
    QFrame *cameralFrame;
    QVBoxLayout *verticalLayout_7;
    QLabel *cameralTextLabel;
    QLabel *cameralTotalLabel;
    QFrame *warningMain;
    QHBoxLayout *horizontalLayout_3;
    QLabel *warningLabel;
    QFrame *warningFrame;
    QVBoxLayout *verticalLayout_8;
    QLabel *warningTextLabel;
    QLabel *warningTotalLabel;
    QHBoxLayout *horizontalLayout_4;
    QFrame *bottom;
    QHBoxLayout *contentButtom;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;

    void setupUi(QMainWindow *AIMonitorClass)
    {
        if (AIMonitorClass->objectName().isEmpty())
            AIMonitorClass->setObjectName(QStringLiteral("AIMonitorClass"));
        AIMonitorClass->resize(1942, 1199);
        action = new QAction(AIMonitorClass);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(AIMonitorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(1960, 1110));
        centralWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(1920, 1080));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-size: contain;\n"
"border-image:url(:/AIMonitor/img/dabeijing.png);\n"
"border-top-left-radius:5px;\n"
"\n"
"border-top-right-radius:5px;\n"
"\n"
"border-bottom-left-radius:5px;\n"
"\n"
"border-bottom-right-radius:5px;\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 0, 1, 0);
        topFrame = new QFrame(frame);
        topFrame->setObjectName(QStringLiteral("topFrame"));
        topFrame->setMinimumSize(QSize(1076, 115));
        top = new QHBoxLayout(topFrame);
        top->setSpacing(0);
        top->setContentsMargins(11, 11, 11, 11);
        top->setObjectName(QStringLiteral("top"));
        top->setSizeConstraint(QLayout::SetDefaultConstraint);
        top->setContentsMargins(0, 0, 0, 0);
        projectLabel = new QLabel(topFrame);
        projectLabel->setObjectName(QStringLiteral("projectLabel"));
        projectLabel->setMinimumSize(QSize(350, 30));
        projectLabel->setMaximumSize(QSize(300, 39));
        projectLabel->setStyleSheet(QLatin1String("#projectLabel{\n"
"	color:#FFFFFF;\n"
"    font-size:20px;\n"
"    padding-left:15px;\n"
"	font-family: Microsoft YaHei;\n"
"	padding-top:12px;\n"
"}"));

        top->addWidget(projectLabel, 0, Qt::AlignTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        top->addItem(horizontalSpacer);

        title = new QLabel(topFrame);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(369, 50));
        title->setMaximumSize(QSize(369, 50));
        title->setStyleSheet(QLatin1String("#title{\n"
"	border-image: url(:/AIMonitor/img/logo--.png);\n"
"}"));

        top->addWidget(title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        top->addItem(horizontalSpacer_2);

        signalButton = new QPushButton(topFrame);
        signalButton->setObjectName(QStringLiteral("signalButton"));
        signalButton->setMaximumSize(QSize(35, 35));
        signalButton->setCursor(QCursor(Qt::PointingHandCursor));
        signalButton->setStyleSheet(QString::fromUtf8("#signalButton {  \n"
"	image: url(:/AIMonitor/img/xinhao.png);\n"
"	background: transparent; \n"
"	padding-top:12px; \n"
"	\n"
"}  \n"
"\n"
"/* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\347\232\204\346\225\210\346\236\234 */  \n"
"#miniButton:pressed {  \n"
"    /* \346\224\271\345\217\230\350\203\214\346\231\257\350\211\262 */  \n"
"    background-color:rgb(40,85,20);  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:6px;  \n"
"    padding-top:18px;  \n"
"}  \n"
"\n"
"/* \346\214\211\351\222\256\346\240\267\345\274\217 */  \n"
"#miniButton:flat {  \n"
"    border:2px solid red;  \n"
"}  "));
        QIcon icon;
        icon.addFile(QStringLiteral(":/AIMonitor/icons/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        signalButton->setIcon(icon);

        top->addWidget(signalButton, 0, Qt::AlignTop);

        closeButton = new QPushButton(topFrame);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMaximumSize(QSize(35, 35));
        closeButton->setCursor(QCursor(Qt::PointingHandCursor));
        closeButton->setStyleSheet(QString::fromUtf8("#closeButton {\n"
"	\n"
"	image: url(:/AIMonitor/img/guanbi.png);\n"
"	background: transparent; \n"
"	padding-top:12px;\n"
"}  \n"
"\n"
"/* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\347\232\204\346\225\210\346\236\234 */  \n"
"#closeButton:pressed {  \n"
"    /* \346\224\271\345\217\230\350\203\214\346\231\257\350\211\262 */  \n"
"    background-color:rgb(40,85,20);  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:6px;  \n"
"    padding-top:18px;  \n"
"}  \n"
"\n"
"/* \346\214\211\351\222\256\346\240\267\345\274\217 */  \n"
"#closeButton:flat {  \n"
"    border:2px solid red;  \n"
"}  "));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/AIMonitor/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon1);

        top->addWidget(closeButton, 0, Qt::AlignTop);

        top->setStretch(0, 1);
        top->setStretch(1, 5);
        top->setStretch(2, 20);
        top->setStretch(3, 8);
        top->setStretch(4, 1);
        top->setStretch(5, 1);

        verticalLayout_2->addWidget(topFrame);

        contentWidget = new QWidget(frame);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));
        content = new QHBoxLayout(contentWidget);
        content->setSpacing(7);
        content->setContentsMargins(11, 11, 11, 11);
        content->setObjectName(QStringLiteral("content"));
        content->setContentsMargins(62, 1, 60, 3);
        leftFrame = new QFrame(contentWidget);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        leftFrame->setMinimumSize(QSize(371, 758));
        leftFrame->setMaximumSize(QSize(371, 758));
        leftFrame->setStyleSheet(QLatin1String("#leftFrame{\n"
"	\n"
"	border-image: url(:/AIMonitor/img/xiaobeijingzuo.png);\n"
"}"));
        listviewFrame = new QVBoxLayout(leftFrame);
        listviewFrame->setSpacing(6);
        listviewFrame->setContentsMargins(11, 11, 11, 11);
        listviewFrame->setObjectName(QStringLiteral("listviewFrame"));
        listviewFrame->setContentsMargins(10, 40, 10, 280);
        monitorLabel = new QLabel(leftFrame);
        monitorLabel->setObjectName(QStringLiteral("monitorLabel"));
        monitorLabel->setStyleSheet(QLatin1String("color:#FFFFFF;\n"
"font-size:14px;\n"
"padding-left:15px;\n"
"font-family: Microsoft YaHei;"));

        listviewFrame->addWidget(monitorLabel);

        listWidget = new QListWidget(leftFrame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QLatin1String("#listWidget{\n"
" background-color:transparent;\n"
" font-size:14px;\n"
" padding-left:15px;\n"
" font-family: Microsoft YaHei;\n"
" color:white\n"
"}"));

        listviewFrame->addWidget(listWidget);


        content->addWidget(leftFrame);

        videoLabel = new QLabel(contentWidget);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));

        content->addWidget(videoLabel);

        rightFrame = new QFrame(contentWidget);
        rightFrame->setObjectName(QStringLiteral("rightFrame"));
        rightFrame->setMinimumSize(QSize(371, 758));
        rightFrame->setMaximumSize(QSize(371, 758));
        rightFrame->setStyleSheet(QLatin1String("#rightFrame{\n"
"	border-image: url(:/AIMonitor/img/xiaobeijingyou.png)\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(rightFrame);
        verticalLayout_3->setSpacing(8);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 40, 10, 280);
        dataLabel = new QLabel(rightFrame);
        dataLabel->setObjectName(QStringLiteral("dataLabel"));
        dataLabel->setMinimumSize(QSize(10, 20));
        dataLabel->setStyleSheet(QLatin1String("color:#FFFFFF;\n"
"font-size:14px;\n"
"padding-left:15px;\n"
"font-family: Microsoft YaHei;"));

        verticalLayout_3->addWidget(dataLabel, 0, Qt::AlignTop);

        cameralMain = new QFrame(rightFrame);
        cameralMain->setObjectName(QStringLiteral("cameralMain"));
        cameralMain->setMinimumSize(QSize(337, 84));
        cameralMain->setMaximumSize(QSize(337, 84));
        cameralMain->setStyleSheet(QLatin1String("#cameralMain{\n"
"border-image: url(:/AIMonitor/img/xiaokuang.png);\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(cameralMain);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 1, -1);
        cameralLabel = new QLabel(cameralMain);
        cameralLabel->setObjectName(QStringLiteral("cameralLabel"));
        cameralLabel->setMinimumSize(QSize(50, 50));
        cameralLabel->setMaximumSize(QSize(50, 50));
        cameralLabel->setStyleSheet(QStringLiteral("border-image: url(:/AIMonitor/img/zhuapai.png);"));

        horizontalLayout_2->addWidget(cameralLabel, 0, Qt::AlignLeft);

        cameralFrame = new QFrame(cameralMain);
        cameralFrame->setObjectName(QStringLiteral("cameralFrame"));
        cameralFrame->setMinimumSize(QSize(0, 0));
        cameralFrame->setMaximumSize(QSize(114514, 114514));
        cameralFrame->setStyleSheet(QStringLiteral("background-color:transparent"));
        verticalLayout_7 = new QVBoxLayout(cameralFrame);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 0, -1, -1);
        cameralTextLabel = new QLabel(cameralFrame);
        cameralTextLabel->setObjectName(QStringLiteral("cameralTextLabel"));
        cameralTextLabel->setMinimumSize(QSize(80, 22));
        cameralTextLabel->setMaximumSize(QSize(80, 22));
        cameralTextLabel->setStyleSheet(QLatin1String("#cameralTextLabel{\n"
"width: 64px;\n"
"height: 22px;\n"
"opacity: 0.6;\n"
"font-family: PingFangSC-Regular;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"letter-spacing: 0;\n"
"font-weight: 400;\n"
"padding-left:5px\n"
"}"));

        verticalLayout_7->addWidget(cameralTextLabel);

        cameralTotalLabel = new QLabel(cameralFrame);
        cameralTotalLabel->setObjectName(QStringLiteral("cameralTotalLabel"));
        cameralTotalLabel->setMinimumSize(QSize(75, 45));
        cameralTotalLabel->setMaximumSize(QSize(200, 45));
        cameralTotalLabel->setStyleSheet(QLatin1String("#cameralTotalLabel{\n"
"font-family: PingFangSC-Semibold;\n"
"font-size: 32px;\n"
"color: #00FFFD;\n"
"padding-bottom:10px;\n"
"letter-spacing: 0;\n"
"font-weight: 600;\n"
"\n"
"}"));
        cameralTotalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(cameralTotalLabel);


        horizontalLayout_2->addWidget(cameralFrame);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 15);

        verticalLayout_3->addWidget(cameralMain);

        warningMain = new QFrame(rightFrame);
        warningMain->setObjectName(QStringLiteral("warningMain"));
        warningMain->setMinimumSize(QSize(337, 84));
        warningMain->setMaximumSize(QSize(337, 84));
        warningMain->setStyleSheet(QLatin1String("#warningMain{\n"
"border-image: url(:/AIMonitor/img/xiaokuang.png);\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(warningMain);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 1, -1);
        warningLabel = new QLabel(warningMain);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setMinimumSize(QSize(50, 50));
        warningLabel->setMaximumSize(QSize(50, 50));
        warningLabel->setStyleSheet(QStringLiteral("border-image: url(:/AIMonitor/img/yujing.png);"));

        horizontalLayout_3->addWidget(warningLabel, 0, Qt::AlignLeft);

        warningFrame = new QFrame(warningMain);
        warningFrame->setObjectName(QStringLiteral("warningFrame"));
        warningFrame->setMinimumSize(QSize(0, 0));
        warningFrame->setMaximumSize(QSize(114514, 114514));
        verticalLayout_8 = new QVBoxLayout(warningFrame);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 0, -1, -1);
        warningTextLabel = new QLabel(warningFrame);
        warningTextLabel->setObjectName(QStringLiteral("warningTextLabel"));
        warningTextLabel->setStyleSheet(QLatin1String("#warningTextLabel{\n"
"width: 64px;\n"
"height: 22px;\n"
"opacity: 0.6;\n"
"font-family: PingFangSC-Regular;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"letter-spacing: 0;\n"
"font-weight: 400;\n"
"padding-left:5px\n"
"}"));

        verticalLayout_8->addWidget(warningTextLabel);

        warningTotalLabel = new QLabel(warningFrame);
        warningTotalLabel->setObjectName(QStringLiteral("warningTotalLabel"));
        warningTotalLabel->setMinimumSize(QSize(75, 45));
        warningTotalLabel->setMaximumSize(QSize(200, 45));
        warningTotalLabel->setStyleSheet(QLatin1String("#warningTotalLabel{\n"
"font-family: PingFangSC-Semibold;\n"
"font-size: 32px;\n"
"color: #00FFFD;\n"
"padding-bottom:10px;\n"
"letter-spacing: 0;\n"
"font-weight: 600;\n"
"\n"
"}"));
        warningTotalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(warningTotalLabel);


        horizontalLayout_3->addWidget(warningFrame);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 15);

        verticalLayout_3->addWidget(warningMain);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(3, 5);

        content->addWidget(rightFrame);

        content->setStretch(0, 5);
        content->setStretch(2, 5);

        verticalLayout_2->addWidget(contentWidget);

        bottom = new QFrame(frame);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setMinimumSize(QSize(0, 300));
        contentButtom = new QHBoxLayout(bottom);
        contentButtom->setSpacing(6);
        contentButtom->setContentsMargins(11, 11, 11, 11);
        contentButtom->setObjectName(QStringLiteral("contentButtom"));
        contentButtom->setContentsMargins(430, -1, 1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(bottom);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(bottom);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("width: 80px;\n"
"height: 28px;\n"
"font-family: PingFangSC-Regular;\n"
"font-size: 20px;\n"
"color: #FFFFFF;\n"
"letter-spacing: 0;\n"
"font-weight: 400;"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 2);

        contentButtom->addLayout(verticalLayout);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_4 = new QLabel(bottom);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_10->addWidget(label_4);

        label_3 = new QLabel(bottom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("width: 80px;\n"
"height: 28px;\n"
"font-family: PingFangSC-Regular;\n"
"font-size: 20px;\n"
"color: #FFFFFF;\n"
"letter-spacing: 0;\n"
"font-weight: 400;"));

        verticalLayout_10->addWidget(label_3, 0, Qt::AlignHCenter);

        verticalLayout_10->setStretch(0, 10);
        verticalLayout_10->setStretch(1, 2);

        contentButtom->addLayout(verticalLayout_10);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(bottom);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        label_5 = new QLabel(bottom);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("width: 80px;\n"
"height: 28px;\n"
"font-family: PingFangSC-Regular;\n"
"font-size: 20px;\n"
"color: #FFFFFF;\n"
"letter-spacing: 0;\n"
"font-weight: 400;"));

        verticalLayout_6->addWidget(label_5, 0, Qt::AlignHCenter);

        verticalLayout_6->setStretch(0, 10);
        verticalLayout_6->setStretch(1, 2);

        contentButtom->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_8 = new QLabel(bottom);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_7 = new QLabel(bottom);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("width: 80px;\n"
"height: 28px;\n"
"font-family: PingFangSC-Regular;\n"
"font-size: 20px;\n"
"color: #FFFFFF;\n"
"letter-spacing: 0;\n"
"font-weight: 400;"));

        verticalLayout_5->addWidget(label_7, 0, Qt::AlignHCenter);

        verticalLayout_5->setStretch(0, 10);
        verticalLayout_5->setStretch(1, 2);

        contentButtom->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

        contentButtom->addLayout(verticalLayout_4);

        contentButtom->setStretch(0, 10);
        contentButtom->setStretch(1, 10);
        contentButtom->setStretch(2, 10);
        contentButtom->setStretch(3, 10);
        contentButtom->setStretch(4, 17);

        verticalLayout_2->addWidget(bottom);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(1, 65);

        horizontalLayout->addWidget(frame);

        AIMonitorClass->setCentralWidget(centralWidget);

        retranslateUi(AIMonitorClass);

        QMetaObject::connectSlotsByName(AIMonitorClass);
    } // setupUi

    void retranslateUi(QMainWindow *AIMonitorClass)
    {
        AIMonitorClass->setWindowTitle(QApplication::translate("AIMonitorClass", "AIMonitor", Q_NULLPTR));
        action->setText(QApplication::translate("AIMonitorClass", "\345\205\263\351\227\255", Q_NULLPTR));
        projectLabel->setText(QApplication::translate("AIMonitorClass", "\345\205\254\345\217\270-\351\241\271\347\233\256", Q_NULLPTR));
        title->setText(QString());
#ifndef QT_NO_WHATSTHIS
        signalButton->setWhatsThis(QApplication::translate("AIMonitorClass", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        signalButton->setText(QString());
        closeButton->setText(QString());
        monitorLabel->setText(QApplication::translate("AIMonitorClass", "\346\234\254\345\214\272\347\233\221\346\216\247", Q_NULLPTR));
        videoLabel->setText(QApplication::translate("AIMonitorClass", "TextLabel", Q_NULLPTR));
        dataLabel->setText(QApplication::translate("AIMonitorClass", "\346\225\260\346\215\256\345\261\225\347\244\272", Q_NULLPTR));
        cameralLabel->setText(QString());
        cameralTextLabel->setText(QApplication::translate("AIMonitorClass", "\346\212\223\346\213\215\346\254\241\346\225\260", Q_NULLPTR));
        cameralTotalLabel->setText(QApplication::translate("AIMonitorClass", "0", Q_NULLPTR));
        warningLabel->setText(QString());
        warningTextLabel->setText(QApplication::translate("AIMonitorClass", "\350\277\235\350\247\204\346\254\241\346\225\260", Q_NULLPTR));
        warningTotalLabel->setText(QApplication::translate("AIMonitorClass", "0", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("AIMonitorClass", "\347\233\221\346\216\2471", Q_NULLPTR));
        label_4->setText(QString());
        label_3->setText(QApplication::translate("AIMonitorClass", "\347\233\221\346\216\2472", Q_NULLPTR));
        label_6->setText(QString());
        label_5->setText(QApplication::translate("AIMonitorClass", "\347\233\221\346\216\2473", Q_NULLPTR));
        label_8->setText(QString());
        label_7->setText(QApplication::translate("AIMonitorClass", "\347\233\221\346\216\2474", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AIMonitorClass: public Ui_AIMonitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIMONITOR_H
