#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_LoginWidget.h"

class LoginWidget : public QWidget
{
	Q_OBJECT

public:
	LoginWidget(QWidget *parent = Q_NULLPTR);

	void loginSlot();
signals:
	void loginSignal();



private:
	Ui::LoginWidget ui;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	//��¼��꣬����λ��
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
};

