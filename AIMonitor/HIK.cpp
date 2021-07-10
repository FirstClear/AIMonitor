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
		float scaleW = 0.5; // ������ͼ��Ĵ�С�������С��80%
		float scaleH = 0.5;  //������ͼ��Ĵ�С���߶���С��80%
		int width = int(YUVImage.rows * scaleW);
		//������Ҫ���������С��Ŀ�ȣ�src.colsΪԭͼ��Ŀ�ȣ�����80%��õ���Ҫ�Ĵ�С����ǿ��ת����int��
		int height = int(YUVImage.cols * scaleH);
		//������Ҫ���������С��ĸ߶ȣ�src.colsΪԭͼ��ĸ߶ȣ�����80%��õ���Ҫ�Ĵ�С����ǿ��ת����int��
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

		//���ý���ص����� ֻ���벻��ʾ
 		if (!PlayM4_SetDecCallBack(HIK::g_nPort, HIK::DecCBFun))
 		{
 			dRet=PlayM4_GetLastError(HIK::g_nPort);
 			break;
 		}

		////���ý���ص����� ��������ʾ
		//if (!PlayM4_SetDecCallBackExMend(HIK::g_nPort, DecCBFun, NULL, 0, NULL))
		//{
		//	dRet = PlayM4_GetLastError(HIK::g_nPort);
		//	break;
		//}

		//����Ƶ����
		if (!PlayM4_Play(HIK::g_nPort, HIK::hPlayWnd))
		{
			dRet = PlayM4_GetLastError(HIK::g_nPort);
			break;
		}

		//����Ƶ����, ��Ҫ�����Ǹ�����
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
	cout << "����" << endl;
	if (dwDataType == NET_DVR_STREAMDATA)//��������
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
//��������
HIK::~HIK(void)
{
}
//��ʼ��������������ʼ��״̬���
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
//��Ƶ����ʾ����
void HIK::show(int flag)
{
	//����Ԥ�������ûص�������
	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
	struPlayInfo.hPlayWnd = HIK::hPlayWnd; //����Ϊ�գ��豸SDK������ֻȡ��
	struPlayInfo.lChannel = currentChannel; //Channel number �豸ͨ��
	cout << "====================================��ǰͨ��Ϊ��" <<this->currentChannel << endl;
	struPlayInfo.dwStreamType = 0;// �������ͣ�0-��������1-��������2-����3��3-����4, 4-����5,5-����6,7-����7,8-����8,9-����9,10-����10
	struPlayInfo.dwLinkMode = 0;// 0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ,3 - RTP��ʽ��4-RTP/RTSP,5-RSTP/HTTP 
	struPlayInfo.bBlocked = 1; //0-������ȡ��, 1-����ȡ��, �������SDK�ڲ�connectʧ�ܽ�����5s�ĳ�ʱ���ܹ�����,���ʺ�����ѯȡ������.
	playHandle = NET_DVR_RealPlay_V40(m_lLoginID, &struPlayInfo, fRealDataCallBack, NULL);
	if (playHandle <0)
	{
		unsigned int res = NET_DVR_GetLastError();
		cout << "ȡ��ʧ�ܣ������룺" << res << endl;
	}
}
void HIK::stop() {
	LONG lHandle = NET_DVR_StopRealPlay(this->playHandle);
	if (lHandle < 0)
	{
		unsigned int res = NET_DVR_GetLastError();
		cout << "ֹͣ����ʧ��" << res << endl;
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
	cout << "��������˵����" << data.size()<<endl;
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
