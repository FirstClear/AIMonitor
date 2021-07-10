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
	// ��Ӱƫ��
	shadowEffect->setOffset(0, 0);
	// ��Ӱ��ɫ;
	shadowEffect->setColor(Qt::black);
	// ��Ӱ�뾶;
	shadowEffect->setBlurRadius(10);
	// �����������ϵ�ǰ����ӰЧ��;
	this->setGraphicsEffect(shadowEffect);
}
void LoginWidget::loginSlot()
{
	emit loginSignal();
}
void LoginWidget::mousePressEvent(QMouseEvent * event)
{
	this->windowPos = this->pos();       // ��ò�����ǰλ��
	this->mousePos = event->globalPos(); // ������λ��
	this->dPos = mousePos - windowPos;   // �ƶ��󲿼����ڵ�λ��
}

void LoginWidget::mouseMoveEvent(QMouseEvent * event)
{
	this->move(event->globalPos() - this->dPos);
}
