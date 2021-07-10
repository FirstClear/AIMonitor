#include "LoginWidget.h"
#include<QtGui/qevent.h>
#include<QtWidgets/QGraphicsDropShadowEffect>
LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.loginButton, &QPushButton::released, this, &LoginWidget::loginSlot);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//this->show();
	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
	// 阴影偏移
	shadowEffect->setOffset(0, 0);
	// 阴影颜色;
	shadowEffect->setColor(Qt::black);
	// 阴影半径;
	shadowEffect->setBlurRadius(10);
	// 给窗口设置上当前的阴影效果;
	this->setGraphicsEffect(shadowEffect);
}
void LoginWidget::loginSlot()
{
	emit loginSignal();
}
void LoginWidget::mousePressEvent(QMouseEvent * event)
{
	this->windowPos = this->pos();       // 获得部件当前位置
	this->mousePos = event->globalPos(); // 获得鼠标位置
	this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void LoginWidget::mouseMoveEvent(QMouseEvent * event)
{
	this->move(event->globalPos() - this->dPos);
}
