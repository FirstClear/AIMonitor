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

	//记录鼠标，窗口位置
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
};

