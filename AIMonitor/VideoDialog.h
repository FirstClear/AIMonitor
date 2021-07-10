#pragma once

#include <QtWidgets/QDialog>
#include "ui_VideoDialog.h"

class VideoDialog : public QDialog
{
	Q_OBJECT

public:
	VideoDialog(QWidget *parent = Q_NULLPTR);
	~VideoDialog();

//private:
	Ui::VideoDialog ui;
};
