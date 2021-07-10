#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtCore/QTimer>
#include <QtCore/QThread>
#include "ui_AIMonitor.h"
#include "LoginWidget.h"
#include "Config.h"
#include <string.h>
#include <iostream>
#include "HIK.h"
#include <QtGUI/QImage>
#include <QtCore/QQueue>
#include "Capture.h"
#include "VideoDialog.h"
#include <iostream>
#include "yolo_v2_class.hpp" //引用动态链接库中的头文件
#include<fstream>
#pragma comment(lib, "opencv_world452d.lib") //引入OpenCV链接库
#pragma comment(lib, "yolo_cpp_dll.lib") //引入YOLO动态链接库
class AIMonitor : public QMainWindow
{
    Q_OBJECT

public:
    AIMonitor(QWidget *parent = Q_NULLPTR);
	LoginWidget loginWidget;
	Config *config;
	string ip;
	unsigned int port;
	string username;
	string password;
	HIK *hikvsion;
	void captureController();
	void itemClicked(int index);
	void setListWidget();
	void clearListWidget();
	int captureNum;
	int violatNum;
	int currentChannel;
	vector<int> captureChannels;
	vector<int> filter;
	void initChannel();
	~AIMonitor(void);
	Capture *capture = new Capture();
	QThread *captureThread;

public slots:
	void handleResults(QPixmap image,int channel);
	void updateImage(QImage mat);
	void updateStatistic(int captureNum, int violatNum, int helmtLess, int vestLess);
signals:
	void sendFlag(int flag);
	void operate();
	void complateShow(int flag);
	void startRealPlay(int flag);
	void toCapture();
private:
    Ui::AIMonitorClass ui;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void login();
	//记录鼠标，窗口位置
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
};
