#pragma once

#include "AIMonitor.h"
#include<QtGui/qevent.h>
#include <QtGui/QPainter>
#include <QtCore/QTimer>
#include <QtGUI/QImage>
#include <QtGUI/QWindow>
#include<QtWidgets/QGraphicsDropShadowEffect>
#include<QtCore/QThread>
#include<QtCore/QMutex>
QMutex AImutex;
AIMonitor::AIMonitor(QWidget *parent)
    : QMainWindow(parent)
{
	qRegisterMetaType<Mat>("Mat");
	hikvsion = new HIK();
	hikvsion->Init();
	this->config = new Config("./config.ini");
	config->printConfig();

	this->ip = "113.128.185.203";
	this->port = 8001;
	this->username = "admin";
	this->password = "knaf12345";
	bool result  = hikvsion->DoLogin(ip,port,username,password);
	cout <<"登录userid:" << hikvsion->m_lLoginID << endl;
	cout <<"起始通道:"<<hikvsion->m_struDeviceInfo.iIPStartChan << endl;
	cout << "起始通道:" << hikvsion->m_struDeviceInfo.iEnableChanNum << endl;
	this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
	connect(hikvsion, &HIK::sendImage, this, &AIMonitor::updateImage);
	hikvsion->GetConfig();   //获取海康配置
	initChannel();          //初始化当前通道currentChannel
    ui.setupUi(this);
	this->setListWidget();        //设置listWidget
	this->captureController();    //连接槽函数
	/*********暂时写死后期用request库拉取配置***********/
	this->captureNum = 0;
	this->violatNum = 0;
	this->setFocusPolicy(Qt::ClickFocus);
	this->setAttribute(Qt::WA_TranslucentBackground);

	
	this->show();
	hikvsion->g_nPort = 0;
	
	//this->loginWidget.show();
	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
	// 阴影偏移
	shadowEffect->setOffset(0, 0);
	// 阴影颜色;
	shadowEffect->setColor(Qt::black);
	// 阴影半径;
	shadowEffect->setBlurRadius(10);
	// 给窗口设置上当前的阴影效果;
	this->setGraphicsEffect(shadowEffect);
	connect(this, &AIMonitor::startRealPlay,hikvsion,&HIK::show);

	
	emit startRealPlay(1);
}

/*
Time:2021年7月1日16:36:14
Creator:whl
Discription:captureController，负责控制系统线程将实例出的抓图对象移入到子线程中;
return:void
*/
void AIMonitor::captureController() {
	capture->hikvsion = this->hikvsion;
	connect(capture, &Capture::sendImage, this, &AIMonitor::handleResults);
	connect(capture, &Capture::sendStatistic, this, &AIMonitor::updateStatistic);
	captureThread = new QThread();
	connect(this, &AIMonitor::toCapture, capture, &Capture::run);
	capture->moveToThread(captureThread);
	captureThread->start();
	emit toCapture();
}
/****************************************以下下均为修改前端UI的槽函数************************************************************/
void AIMonitor::itemClicked(int index) {
	auto items = this->ui.listWidget->selectedItems();
	if (items.size() == 1) {
		this->hikvsion->currentChannel = this->hikvsion->indexChannelMap[index];
		auto selectItem = items[0];
		this->hikvsion->stop();
		emit startRealPlay(1);
	}
}


/*
Time:2021年7月1日16:36:14
Creator:whl
Discription:设置ListWidget，显示通道列表;
return:void
*/
void AIMonitor::setListWidget()
{
	int cnt = 0;
	filter = config->getChannel();
	if (filter.size() == 0) {
		for (auto i = hikvsion->enable_pStruPicCfgV30.begin();i != hikvsion->enable_pStruPicCfgV30.end();i++) {
			this->ui.listWidget->insertItem(cnt, QString::fromLocal8Bit(hikvsion->byteToString(i->second.sChanName).data()));
			if (this->hikvsion->currentChannel == -1) {
				this->hikvsion->currentChannel = i->first;
			}
			this->hikvsion->indexChannelMap[cnt] = i->first;
			cnt++;
		}
	}
	else {
		for (auto i = hikvsion->enable_pStruPicCfgV30.begin();i != hikvsion->enable_pStruPicCfgV30.end();i++) {
			for (int j = 0;j < filter.size();j++) {
				if (i->first == filter[j]) {
					this->ui.listWidget->insertItem(cnt, QString::fromLocal8Bit(hikvsion->byteToString(i->second.sChanName).data()));
					//break;
					if (this->hikvsion->currentChannel==-1) {
						this->hikvsion->currentChannel = i->first;
					}
					this->hikvsion->indexChannelMap[cnt] = i->first;
				}
			}
			cnt++;
		}
	}
}

/*
Time:2021年7月1日16:36:14
Creator:whl
Discription:清除ListWidget，然后重绘即可
return:void
*/

void AIMonitor::clearListWidget() {
	QListWidgetItem *item1;
	for(int i=0;i<this->ui.listWidget->count();i++){
		item1 = this->ui.listWidget->takeItem(0);
		this->ui.listWidget->removeItemWidget(item1);
		delete item1;
	}
}
/*
Time:2021年7月1日16:36:14
Creator:whl
Discription:处理发送的QPixmap,并在前台显示
return:void
*/
void AIMonitor::handleResults(QPixmap image,int channel)
{
	if (this->currentChannel == channel) {
		//this->ui.videoLabel->setPixmap(image);
		//this->ui.videoLabel->resize(image.size());
		//this->ui.videoLabel->show();
	}
	emit complateShow(1);
}

/*
Time:2021年7月1日16:36:14
Creator:whl
Discription:另一种更新图像的方式，暂未开始使用
return:void
*/
void AIMonitor::updateImage(QImage mat)
{
	if (this->hikvsion->g_BGRImage.data) {
		this->ui.videoLabel->setPixmap(QPixmap::fromImage(mat));
		Sleep(10);
	}
}

/*
Time:2021年7月1日16:36:14
Creator:whl
Discription:更新统计数据
return:void
*/
void AIMonitor::updateStatistic(int captureNum, int violatNum,int helmtLess,int vestLess)
{
	this->captureNum++;
	this->ui.cameralTotalLabel->setText(QString::number(this->captureNum));
	if (helmtLess!=0||vestLess!=0) {
		this->violatNum++;
		this->ui.warningTotalLabel->setText(QString::number(this->violatNum));
	}
}


/**************************************************************************************************************************/
/*
Time:2021-5-22 21:58:00
Creator:whl
Discription:处理鼠标移动事件，隐藏边框后，界面无法移动，
			需要按照如下写法添加鼠标拖动事件。（mousePressEvent和mouseMoveEvent需配合使用）
return:void
*/
void AIMonitor::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();       // 获得部件当前位置
	this->mousePos = event->globalPos(); // 获得鼠标位置
	this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}
 
void AIMonitor::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}
/*
Time:2021-5-22 21:58:00
Creator:whl
Discription:处理登录事件，隐藏登录窗口，显示主窗口，并进行异步校验
return:void
*/
void AIMonitor::login()
{
	this->show();
	this->loginWidget.hide();
}

/*
Time:2021年7月2日22:06:38
Creator:whl
Discription:初始化当前通道，filter为空则选则第一个通道，不为空则从filter中选择第一个通道
return:void
*/
void AIMonitor::initChannel() {
	if (this->filter.size() == 0) {
		auto iter = this->hikvsion->enable_pStruPicCfgV30.begin();
		if (iter != this->hikvsion->enable_pStruPicCfgV30.end()) {
			this->currentChannel = iter->first;
		}
	}
	else {
		for (int j = 0;j < filter.size();j++) {
			for (auto i = hikvsion->enable_pStruPicCfgV30.begin();i != hikvsion->enable_pStruPicCfgV30.end();i++) {
				if (i->first == filter[j]) {
					this->currentChannel = filter[j];
					break;
				}
			}
		}
	}
}


AIMonitor::~AIMonitor() {
	delete capture;
}