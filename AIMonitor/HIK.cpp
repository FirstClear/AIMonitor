#pragma once

#include "HIK.h"
#include <iostream>
#include <string>
LONG HIK::g_nPort=33;
Mat HIK::g_BGRImage=Mat();
using namespace std;
HIK* HIK::s_this = nullptr;
HWND HIK::hPlayWnd;
int HIK::flag = 0;
void HIK::updateFlag(int flag)
{
	this->flag = flag;
}

void HIK::DecCBFun(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, long nUser, long nReserved2)
{
	/*if (HIK::flag == 0) {
		HIK::flag = 1;
		return ;
	}*/
	if (pFrameInfo->nType == T_YV12)
	{
		std::cout << "the frame infomation is T_YV12" << std::endl;
		if (HIK::g_BGRImage.empty())
		{
			HIK::g_BGRImage.create(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC3);
		}
		Mat YUVImage(pFrameInfo->nHeight + pFrameInfo->nHeight / 2, pFrameInfo->nWidth, CV_8UC1, (unsigned char*)pBuf);
		float scaleW = 0.5; // 定义新图像的大小，宽度缩小到80%
		float scaleH = 0.5;  //定义新图像的大小，高度缩小到80%
		int width = int(YUVImage.rows * scaleW);
		//定义想要扩大或者缩小后的宽度，src.cols为原图像的宽度，乘以80%则得到想要的大小，并强制转换成int型
		int height = int(YUVImage.cols * scaleH);
		//定义想要扩大或者缩小后的高度，src.cols为原图像的高度，乘以80%则得到想要的大小，并强制转换成int型
		cv::Mat dst=Mat();
		cvtColor(YUVImage, HIK::g_BGRImage, COLOR_YUV2BGR_YV12);
		if (HIK::g_BGRImage.data != nullptr) {
			resize(HIK::g_BGRImage,HIK::g_BGRImage,cv::Size(1040, 758));
			cvtColor(HIK::g_BGRImage, HIK::g_BGRImage, COLOR_BGR2RGB);
			cout << "width:" << int(HIK::g_BGRImage.cols) << endl;
			cout << "height:" << int(HIK::g_BGRImage.rows) << endl;
			const uchar *pSrc = (const uchar*)HIK::g_BGRImage.data;
			// Create QImage with same dimensions as input Mat
			QImage image(pSrc,g_BGRImage.cols, g_BGRImage.rows, g_BGRImage.step, QImage::Format_RGB888);
			emit s_this->sendImage(image.copy());
		}
		YUVImage.~Mat();
		dst.~Mat();
	}
}
void CALLBACK fRealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser)
{
	DWORD dRet = 0;
	BOOL inData = FALSE;

	switch (dwDataType)
	{
	case NET_DVR_SYSHEAD:
		if (!PlayM4_GetPort(&HIK::g_nPort))
		{
			break;
		}
		if (!PlayM4_OpenStream(HIK::g_nPort, pBuffer, dwBufSize, 1024 * 1024))
		{
			dRet = PlayM4_GetLastError(HIK::g_nPort);
			break;
		}

		//设置解码回调函数 只解码不显示
 		if (!PlayM4_SetDecCallBack(HIK::g_nPort, HIK::DecCBFun))
 		{
 			dRet=PlayM4_GetLastError(HIK::g_nPort);
 			break;
 		}

		////设置解码回调函数 解码且显示
		//if (!PlayM4_SetDecCallBackExMend(HIK::g_nPort, DecCBFun, NULL, 0, NULL))
		//{
		//	dRet = PlayM4_GetLastError(HIK::g_nPort);
		//	break;
		//}

		//打开视频解码
		if (!PlayM4_Play(HIK::g_nPort, HIK::hPlayWnd))
		{
			dRet = PlayM4_GetLastError(HIK::g_nPort);
			break;
		}

		//打开音频解码, 需要码流是复合流
		if (!PlayM4_PlaySound(HIK::g_nPort))
		{
			dRet = PlayM4_GetLastError(HIK::g_nPort);
			break;
		}
		break;

	case NET_DVR_STREAMDATA:
		inData = PlayM4_InputData(HIK::g_nPort, pBuffer, dwBufSize);
		while (!inData)
		{
			Sleep(10);
			inData = PlayM4_InputData(HIK::g_nPort, pBuffer, dwBufSize);
			cout<<"PlayM4_InputData failed \n"<<endl;
		}
		break;
	default:
		inData = PlayM4_InputData(HIK::g_nPort, pBuffer, dwBufSize);
		while (!inData)
		{
			Sleep(10);
			inData = PlayM4_InputData(HIK::g_nPort, pBuffer, dwBufSize);
			cout << "PlayM4_InputData failed \n" << endl;
		}
		break;
	}
}




void g_RealDataCallBack_V30(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser)
{
	cout << "测试" << endl;
	if (dwDataType == NET_DVR_STREAMDATA)//码流数据
	{
		if (dwBufSize > 0 && HIK::g_nPort != -1)
		{
			if (!PlayM4_InputData(HIK::g_nPort, pBuffer, dwBufSize))
			{
				std::cout << "fail input data" << std::endl;
			}
			else
			{
				std::cout << "success input data" << std::endl;
			}

		}
	}
}
HIK::HIK(void) {
	s_this = this;
	qRegisterMetaType<Mat>("Mat");
}
//析构函数
HIK::~HIK(void)
{
}
//初始化函数，用作初始化状态检测
bool HIK::Init()
{
	if (NET_DVR_Init())
	{
		
		Jpeg = new char[2048 * 2048];
		/*if (!NET_DVR_SetCapturePictureMode(BMP_MODE)) {
			cout << "set Capture Picture Mode error!"<<endl;
		}*/
		return true;
	}
	else
	{
		return false;
	}
}
//视频流显示函数
void HIK::show(int flag)
{
	//启动预览并设置回调数据流
	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
	struPlayInfo.hPlayWnd = HIK::hPlayWnd; //窗口为空，设备SDK不解码只取流
	struPlayInfo.lChannel = currentChannel; //Channel number 设备通道
	cout << "====================================当前通道为：" <<this->currentChannel << endl;
	struPlayInfo.dwStreamType = 0;// 码流类型，0-主码流，1-子码流，2-码流3，3-码流4, 4-码流5,5-码流6,7-码流7,8-码流8,9-码流9,10-码流10
	struPlayInfo.dwLinkMode = 0;// 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP 
	struPlayInfo.bBlocked = 1; //0-非阻塞取流, 1-阻塞取流, 如果阻塞SDK内部connect失败将会有5s的超时才能够返回,不适合于轮询取流操作.
	playHandle = NET_DVR_RealPlay_V40(m_lLoginID, &struPlayInfo, fRealDataCallBack, NULL);
	if (playHandle <0)
	{
		unsigned int res = NET_DVR_GetLastError();
		cout << "取流失败，错误码：" << res << endl;
	}
}
void HIK::stop() {
	LONG lHandle = NET_DVR_StopRealPlay(this->playHandle);
	if (lHandle < 0)
	{
		unsigned int res = NET_DVR_GetLastError();
		cout << "停止播放失败" << res << endl;
	}
}
Mat HIK::captureImg(long channel) {
	unsigned long imgSize = 0;
	LPNET_DVR_JPEGPARA JpegPara = new NET_DVR_JPEGPARA;
	JpegPara->wPicQuality = 0;
	JpegPara->wPicSize = 2;
	
	bool res = NET_DVR_CaptureJPEGPicture_NEW(m_lLoginID, channel, JpegPara, Jpeg, len, &imgSize);
	if (!res)
	{
		printf("Error: NET_DVR_CaptureJPEGPicture_NEW = %d", NET_DVR_GetLastError());
		return	Mat();
	}
	vector<char> data = vector<char>(imgSize); ;
	data.insert(data.begin(), Jpeg, Jpeg + strlen(Jpeg));
	cout << "能听到我说话吗？" << data.size()<<endl;
	for (int i = 0;i < imgSize;i++)
		data[i] = Jpeg[i];
	Mat img = imdecode(Mat(data), 1);
	resize(img, img, Size(1040, 758));
	int width = int(img.rows);
	int height = int(img.cols);
	//imshow("camera", img);
	//waitKey(0);
	return img;
}
