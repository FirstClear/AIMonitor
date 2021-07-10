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
	cout <<"��¼userid:" << hikvsion->m_lLoginID << endl;
	cout <<"��ʼͨ��:"<<hikvsion->m_struDeviceInfo.iIPStartChan << endl;
	cout << "��ʼͨ��:" << hikvsion->m_struDeviceInfo.iEnableChanNum << endl;
	this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
	connect(hikvsion, &HIK::sendImage, this, &AIMonitor::updateImage);
	hikvsion->GetConfig();   //��ȡ��������
	initChannel();          //��ʼ����ǰͨ��currentChannel
    ui.setupUi(this);
	this->setListWidget();        //����listWidget
	this->captureController();    //���Ӳۺ���
	/*********��ʱд��������request����ȡ����***********/
	this->captureNum = 0;
	this->violatNum = 0;
	this->setFocusPolicy(Qt::ClickFocus);
	this->setAttribute(Qt::WA_TranslucentBackground);

	
	this->show();
	hikvsion->g_nPort = 0;
	
	//this->loginWidget.show();
	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
	// ��Ӱƫ��
	shadowEffect->setOffset(0, 0);
	// ��Ӱ��ɫ;
	shadowEffect->setColor(Qt::black);
	// ��Ӱ�뾶;
	shadowEffect->setBlurRadius(10);
	// �����������ϵ�ǰ����ӰЧ��;
	this->setGraphicsEffect(shadowEffect);
	connect(this, &AIMonitor::startRealPlay,hikvsion,&HIK::show);

	
	emit startRealPlay(1);
}

/*
Time:2021��7��1��16:36:14
Creator:whl
Discription:captureController���������ϵͳ�߳̽�ʵ������ץͼ�������뵽���߳���;
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
/****************************************�����¾�Ϊ�޸�ǰ��UI�Ĳۺ���************************************************************/
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
Time:2021��7��1��16:36:14
Creator:whl
Discription:����ListWidget����ʾͨ���б�;
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
Time:2021��7��1��16:36:14
Creator:whl
Discription:���ListWidget��Ȼ���ػ漴��
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
Time:2021��7��1��16:36:14
Creator:whl
Discription:�����͵�QPixmap,����ǰ̨��ʾ
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
Time:2021��7��1��16:36:14
Creator:whl
Discription:��һ�ָ���ͼ��ķ�ʽ����δ��ʼʹ��
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
Time:2021��7��1��16:36:14
Creator:whl
Discription:����ͳ������
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
Discription:��������ƶ��¼������ر߿�󣬽����޷��ƶ���
			��Ҫ��������д���������϶��¼�����mousePressEvent��mouseMoveEvent�����ʹ�ã�
return:void
*/
void AIMonitor::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();       // ��ò�����ǰλ��
	this->mousePos = event->globalPos(); // ������λ��
	this->dPos = mousePos - windowPos;   // �ƶ��󲿼����ڵ�λ��
}
 
void AIMonitor::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}
/*
Time:2021-5-22 21:58:00
Creator:whl
Discription:�����¼�¼������ص�¼���ڣ���ʾ�����ڣ��������첽У��
return:void
*/
void AIMonitor::login()
{
	this->show();
	this->loginWidget.hide();
}

/*
Time:2021��7��2��22:06:38
Creator:whl
Discription:��ʼ����ǰͨ����filterΪ����ѡ���һ��ͨ������Ϊ�����filter��ѡ���һ��ͨ��
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