#pragma once

#include "AIMonitor.h"
#include "LoginWidget.h"
#include <QtWidgets/QApplication>
#include "Config.h"
int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    AIMonitor w;
    return a.exec();
}
