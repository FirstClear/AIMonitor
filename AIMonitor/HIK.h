#pragma once
#include <windows.h>
#include <string> 
#include <iostream>
#include <QtCore/QObject>
#include<string>
#include "HCNetSDK.h"
#include <fstream> 
#include "GeneralDef.h"
#include<PlayM4.h>    //此头文件需要按照下面第二步调试Bug中的方法去添加
#include<plaympeg4.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <QtGUI/QImage>
//timer
#define SYSTEM_TIMER			1		//timer for system parameter,cpu
#define CYCLE_PREVIEW_TIMER		2		//switch display timer
#define	AUTORECORD_TIMER		3		//suto record timer
#define	FREESPACE_TIMER			4		//check HD timer
#define	FILEINTERVAL_TIMER		5		//save file interval timer
#define UPGRADE_TIMER			6		//update timer
#define PLAY_TIMER				7		//local playback status timer
#define REMOTE_PLAY_STATE_TIMER	8		//remote playback status timer
#define DOWNSTATE_TIMER			9		//file download timer
#define FORMAT_TIMER			10		//remote HD format timer
#define EVENTLOG_TIMER			11		//event log timer
#define PLAYBYTIME_TIMER		12		//timer for playback on time
#define DOWNBYTIME_TIMER		13		//timerfor download on time
#define SERIAL_TIMER			14		//timer for serial port send data
#define	CHECK_DEVICE_TIMER		15		//timer for device time checking
#define AUDIOUPLOAD_TIMER		16		//timer for audio upload
#define AUDIODOWNLOAD_TIMER		17		//timer for audio download
#define FACE_DATABASE_INQUIRE   18      //timer for inquire face database
#define SNAP_DATABASE_INQUIRE   19      //timer for inquire snap database
#define WALL_WINSTATUS_TIMER    20      //timer for wall window status
#define TRANS_DEVICE_TIMER      21      //timer for Trans device
#define PLAYBACK_NPQ_STATUS_TIMER      22      //timer for npq playback
#define UPGRADE_TEST_TIMER			23		//update test timer

//default image parameter
#define DEFAULT_BRIGHTNESS	6			//default brightness
#define DEFAULT_CONTRAST	6			//default contrast
#define DEFAULT_SATURATION  6			//default saturation
#define DEFAULT_HUE			6			//default hue
#define DEFAULT_SHARPNESS   6			//default sharpness
#define DEFAULT_DENOISING	6			//default denoising
#define DEFAULT_VOLUME		50			//default volume


#define MAX_DEVICES			512	//max device number
#define MAX_OUTPUTS			512	//16max windownumber
#define MAX_PREVIEWS		512	//max preview number

//device list config
#define TREE_ALL_T	 0        //root node
#define DEVICETYPE 	 1		  //device
#define CHANNELTYPE	 2	      //channel
using namespace std;
using namespace cv;



class HIK : public QObject
{
	Q_OBJECT
signals:
	void sendImage(QImage image);
public slots:
	void updateFlag(int flag);
	void show(int flag);
	void stop();
public:
	LOCAL_DEVICE_INFO m_struDeviceInfo;
	BOOL m_bTrackRun;
	BOOL m_bIsOnCruise;
	BOOL m_bIsLogin;
	LONG m_lLoginID;
	BOOL m_bIsPlaying;
	BOOL m_bIsRecording;
	DWORD dwReturned = 0;
	NET_DVR_PICCFG_V40 *m_pStruPicCfgV40;
	NET_DVR_PICCFG_V30 *m_pStruPicCfgV30;
	map<int,NET_DVR_PICCFG_V30> enable_pStruPicCfgV30;
	map<int, int> indexChannelMap;
	int m_iCurChanIndex;               //当前通道在数组中索引
	LONG m_lPlayHandle;
	static LONG g_nPort;
	static Mat g_BGRImage;
	static void DecCBFun(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, long nUser, long nReserved2);
	static HIK* s_this;
	static HWND hPlayWnd;
	static int flag;
	LPNET_DVR_JPEGPARA JpegPara;
	char * Jpeg;
	DWORD len = 1024 * 1024;
	int currentChannel = -1;
	long playHandle;
	~HIK(void);
	HIK(void);
	bool Init();
	
	Mat captureImg(long channel);
	//全局变量
	static char* stringToChar(string s1) {
		const char*cfirst = s1.c_str();
		char* copy = new char[strlen(cfirst)+ 1];
		strcpy(copy, cfirst);
		cout << copy << endl;
		return copy;
	}
	static string byteToString(BYTE *key) {
		char* p = new char[sizeof(key)*4+1];
		memcpy(p, key, sizeof(key)*4+1);
		for (int i = 0;i < sizeof(key)*4+1;i++) {
			if (p[i] == '\0') {
				p[i] = ' ';
			}
		}
		p[sizeof(key)*4+1] = 0;
		string str(p);
		return str;
	}

	/*
	Time:2021年6月24日15:11:44
	Creator:whl
	Discription:登录操作，登录失败返回False
	return:bool
	*/
	bool DoLogin(string DeviceIp, WORD port, string UserName, string Password) {
		char *ip = stringToChar(DeviceIp);
		char *username = stringToChar(UserName);
		char *password = stringToChar(Password);


		NET_DVR_DEVICEINFO_V30 DeviceInfoTmp;
		memset(&DeviceInfoTmp, 0, sizeof(NET_DVR_DEVICEINFO_V30));

		m_lLoginID = NET_DVR_Login_V30(ip, port, \
			username, password, &DeviceInfoTmp);
		if (m_lLoginID == -1)
		{
			unsigned int res = NET_DVR_GetLastError();
			cout << "登录失败，错误码：" << res<<endl;
			return FALSE;
		}
		m_struDeviceInfo.lLoginID = m_lLoginID;
		m_struDeviceInfo.iDeviceChanNum = DeviceInfoTmp.byChanNum;
		m_struDeviceInfo.iIPChanNum = DeviceInfoTmp.byIPChanNum;
		m_struDeviceInfo.iStartChan = DeviceInfoTmp.byStartChan;
		m_struDeviceInfo.iIPStartChan = DeviceInfoTmp.byStartDChan;
		return true;
	}
	/*
	Time:2021年6月24日15:11:44
	Creator:whl
	Discription:获取通道配置信息
	return:void
	*/
	void HIK::GetConfig() {
		m_pStruPicCfgV30 = new NET_DVR_PICCFG_V30[MAX_CHANNUM_V30];
		for (int i = m_struDeviceInfo.iIPStartChan;i < MAX_CHANNUM_V30;i++) {
			memset(&m_pStruPicCfgV30[i], 0, sizeof(m_pStruPicCfgV30[i]));
			bool t = NET_DVR_GetDVRConfig(m_lLoginID, NET_DVR_GET_PICCFG_V30, i, &m_pStruPicCfgV30[i], sizeof(m_pStruPicCfgV30[i]), &dwReturned);
			if (t == true) {
				enable_pStruPicCfgV30[i] = m_pStruPicCfgV30[i];
			}
			cout << "通道号:" << i<<" ";
			cout << m_pStruPicCfgV30[i].sChanName << endl;
		}
	}
	void HIK::DoGetDeviceResoureCfg()
	{
		NET_DVR_IPPARACFG_V40 IpAccessCfg;
		memset(&IpAccessCfg, 0, sizeof(IpAccessCfg));
		DWORD  dwReturned;

		m_struDeviceInfo.bIPRet = NET_DVR_GetDVRConfig(m_struDeviceInfo.lLoginID, NET_DVR_GET_IPPARACFG_V40, 0, &IpAccessCfg, sizeof(NET_DVR_IPPARACFG_V40), &dwReturned);

		int i;
		if (!m_struDeviceInfo.bIPRet)   //不支持ip接入,9000以下设备不支持禁用模拟通道
		{
			for (i = 0; i < MAX_ANALOG_CHANNUM; i++)
			{
				if (i < m_struDeviceInfo.iDeviceChanNum)
				{
					sprintf(m_struDeviceInfo.struChanInfo[i].chChanName, "camera%d", i + m_struDeviceInfo.iStartChan);
					m_struDeviceInfo.struChanInfo[i].iChanIndex = i + m_struDeviceInfo.iStartChan;  //通道号
					m_struDeviceInfo.struChanInfo[i].bEnable = TRUE;
				}
				else
				{
					m_struDeviceInfo.struChanInfo[i].iChanIndex = -1;
					m_struDeviceInfo.struChanInfo[i].bEnable = FALSE;
					sprintf(m_struDeviceInfo.struChanInfo[i].chChanName, "");
					
				}
			}
		}
		else        //支持IP接入，9000设备
		{
			for (i = 0; i < MAX_ANALOG_CHANNUM; i++)  //模拟通道
			{
				if (i < m_struDeviceInfo.iDeviceChanNum)
				{
					sprintf(m_struDeviceInfo.struChanInfo[i].chChanName, "camera%d", i + m_struDeviceInfo.iStartChan);
					m_struDeviceInfo.struChanInfo[i].iChanIndex = i + m_struDeviceInfo.iStartChan;
					if (IpAccessCfg.byAnalogChanEnable[i])
					{
						m_struDeviceInfo.struChanInfo[i].bEnable = TRUE;
					}
					else
					{
						m_struDeviceInfo.struChanInfo[i].bEnable = FALSE;
					}

				}
				else//clear the state of other channel
				{
					m_struDeviceInfo.struChanInfo[i].iChanIndex = -1;
					m_struDeviceInfo.struChanInfo[i].bEnable = FALSE;
					sprintf(m_struDeviceInfo.struChanInfo[i].chChanName, "");

				}
			}

			//数字通道
			for (i = 0; i < MAX_IP_CHANNEL; i++)
			{
				if (IpAccessCfg.struStreamMode[i].uGetStream.struChanInfo.byEnable)  //ip通道在线
				{
					m_struDeviceInfo.struChanInfo[i + MAX_ANALOG_CHANNUM].bEnable = TRUE;
					m_struDeviceInfo.struChanInfo[i + MAX_ANALOG_CHANNUM].iChanIndex = i + IpAccessCfg.dwStartDChan;
					sprintf(m_struDeviceInfo.struChanInfo[i + MAX_ANALOG_CHANNUM].chChanName, "IP Camera %d", i + 1);
				}
				else
				{
					m_struDeviceInfo.struChanInfo[i + MAX_ANALOG_CHANNUM].bEnable = FALSE;
					m_struDeviceInfo.struChanInfo[i + MAX_ANALOG_CHANNUM].iChanIndex = -1;
				}
			}
		}
	}
	//全局变量
	

	//数据解码回调函数，
	//功能：将YV_12格式的视频数据流转码为可供opencv处理的BGR类型的图片数据，并实时显示。
	
	//构造函数
	
	

};


