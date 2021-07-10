#pragma once

#ifdef _WIN32
#define OPENCV
#define GPU
#endif

#include<QtCore/QObject>
#include<QtCore/QThread>
#include "HIK.h"
#include <QtCore/QMetaType>
#include <QtGUI/QImage>
#include <QtGUI/QPixmap>
#include <iostream>
#include "yolo_v2_class.hpp" //引用动态链接库中的头文件
#include<fstream>
#pragma comment(lib, "opencv_world452d.lib") //引入OpenCV链接库
#pragma comment(lib, "yolo_cpp_dll.lib") //引入YOLO动态链接库

using namespace std;
using namespace cv;
//以下两段代码来自yolo_console_dll.sln，有修改
class Capture :public QObject {
	Q_OBJECT
signals:
	void resultReady();

	//发送图像信号
	void sendImage(QPixmap image,int channel);
	void sendStatistic(int captureNum, int violatNum, int helmtLess, int vestLess);
public:
	string names_file = "custom.names";
	string cfg_file = "yolov4-custom.cfg";
	string weights_file = "yolov4-custom_final.weights";
	vector<std::string> obj_names;
	Detector* detector; //初始化检测器
	vector<int> captureChannels;
	void initDetector() {
		std::ifstream ifs(names_file.c_str());
		std::string line;
		while (getline(ifs, line)) obj_names.push_back(line);
		//测试是否成功读入分类对象文件
		for (size_t i = 0; i < obj_names.size(); i++)
		{
			std::cout << obj_names[i] << std::endl;
		}
	}
	void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names)
	{
		int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
		for (auto &i : result_vec) {
			cv::Scalar color = obj_id_to_color(i.obj_id);
			cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
			if (obj_names.size() > i.obj_id) {
				std::string obj_name = obj_names[i.obj_id];
				cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
				int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
				cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
					cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
					color, CV_FILLED, 8, 0);
				putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
			}
		}
	}
	std::vector<std::string> objects_names_from_file(std::string const filename) {
		std::ifstream file(filename);
		std::vector<std::string> file_lines;
		if (!file.is_open()) return file_lines;
		for (std::string line; getline(file, line);) file_lines.push_back(line);
		std::cout << "object names loaded \n";
		return file_lines;
	}

	Capture(QObject* parent = nullptr) {
		qRegisterMetaType<Mat>("Mat");
		initDetector();
		detector = new Detector(cfg_file, weights_file, 0);
	}
	HIK *hikvsion;
	int lock = 1; //定义一个锁,默认没锁
public slots:
	// doWork定义了线程要执行的操作
	void run()
	{
		int captureNum = 0;
		int violatNum = 0;
		while (true) {
			for (auto i = hikvsion->enable_pStruPicCfgV30.begin();i != hikvsion->enable_pStruPicCfgV30.end();) {
				Mat mat = hikvsion->captureImg(i->first);
				int helmetLess = 0;
				int vestLess = 0;
				bool flag = true;
				if (mat.data) {
					captureNum++;
					std::vector<bbox_t> result_vec = detector->detect(mat, 0.5, true);
					draw_boxes(mat, result_vec, obj_names);
					for (int i = 0;i < result_vec.size();i++) {
						if (result_vec[i].obj_id == 0 ) {
							helmetLess++;
						}
						else if (result_vec[i].obj_id == 3) {
							vestLess++;
						}
						if (flag) {
							if (result_vec[i].obj_id == 0 || result_vec[i].obj_id == 3) {
								violatNum++;
								flag = false;
							}
						}
					}
					cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
					QImage image = QImage((uchar*)(mat.data), mat.cols, mat.rows, QImage::Format_RGB888);
					QPixmap pixmap = QPixmap::fromImage(image);
					//emit sendImage(pixmap,i->first);
					emit sendStatistic(captureNum,violatNum,helmetLess,vestLess);
					Sleep(100);
				}
				i++;
			}
		}
	}
	void changeLock(int lock) {
		this->lock = lock;
	}
	// 线程完成工作时发送的信号
};