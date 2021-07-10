/*
 * publicfuc.cpp
 *
 *  Created on: 2009-11-5
 *      Author: letian
 */

#include "publicfuc.h"
#include <QtWidgets/QMessageBox>

#define MAX_CHAN_CHECKBOX 64

//convert the QLineEdit to  int
//Please note that  the bit num of pNum!!!!!!
int KIT_editToInt(const QLineEdit *pEdit, int *pNum)
{
    QString qstrTemp;
    QByteArray cArrTemp;
    const char *pTemp;
    qstrTemp = pEdit->text();
    cArrTemp = qstrTemp.toLatin1();
    pTemp = cArrTemp.data();
    *pNum = atoi(pTemp);

    return HPR_OK;
}


int KIT_intToEdit(QLineEdit *pEdit, int iNum)
{
    char strTemp[INT_LEN];
    memset(strTemp, 0, INT_LEN);
    //firstly, convert int to char *
    sprintf(strTemp, "%d", iNum);
    //secondly, convert char * to QLineEdit
    pEdit->setText(QString(QLatin1String(strTemp)));

    return  HPR_OK;
}

int KIT_unintToEdit(QLineEdit *pEdit, unsigned int iNum)
{
	  char strTemp[INT_LEN];
	  memset(strTemp, 0, INT_LEN);
	  //firstly, convert int to char *
	  sprintf(strTemp, "%u", iNum);
	  //secondly, convert char * to QLineEdit
	  pEdit->setText(QString(QLatin1String(strTemp)));

	  return  HPR_OK;
}

//check ip
int KIT_checkIP(char * ip)
{
	if(ip == NULL)
	{
		return HPR_ERROR; //-1
	}
	if(strlen(ip) == 0)
	{
		return HPR_OK;
	}

	char str[20];
	memset(str, 0, 20);
	strcpy(str,ip);
	char a;
	int dot=0;
	int a3, a2, a1, a0, i;
	i = 0;
	a3 = a2 = a1 = a0 = -1;

	while ((a=str[i++]))
	{
		if ((a==' ')||(a=='.')||((a>='0')&&(a<='9')))
		{
			if (a=='.')
			{
				dot++;
			}
		}
		else
		{
			return HPR_ERROR;
		}
	}
	if (dot!=3)
	{
		return HPR_ERROR;
	}
	else
	{
		sscanf(str,"%d.%d.%d.%d",&a3,&a2,&a1,&a0);
		if ((a0>255)||(a1>255)||(a2>255)||(a3>255))
		{
			return HPR_ERROR;
		}
		if ((a0 < 0) || (a1 < 0) || (a2 < 0) || (a3 < 0))
		{
		    return HPR_ERROR;
		}
	}

    return HPR_OK;
}

//convert QLineEdit to  char*
int KIT_editToStr(const QLineEdit *pEdit, BYTE  *pStr, int iLen)
{
	if( pEdit == NULL || pStr == NULL)
	{
		return HPR_ERROR;
	}

	QString qstrTemp;
	QByteArray cArrTemp;

	//first, convert  QLineEdit  to QByteArray
	qstrTemp = pEdit->text();
	cArrTemp = qstrTemp.toLatin1();
	//second, convert QByteArray to char*.
	memcpy(pStr,  cArrTemp.data(), iLen);

	return HPR_OK;
}

int KIT_qstringToStr(const QString *pString, BYTE *pStr, int iLen)
{
	if( pString == NULL || pStr == NULL)
	{
		return HPR_ERROR;
	}

	QByteArray cArrTemp;
	//first, convert  QLineEdit  to QByteArray
        cArrTemp = pString->toLatin1();
	//second, convert QByteArray to char*.
	memcpy(pStr,  cArrTemp.data(), iLen);

	return HPR_OK;
}


int KIT_qstringToInt(const QString *pString, int *pNum)
{
	QByteArray cArrTemp;
	const char *pTemp;
	cArrTemp = pString->toLatin1();
	pTemp = cArrTemp.data();
	*pNum = atoi(pTemp);

	return HPR_OK;
}

//convert edit to ip
int KIT_editToIP(const QLineEdit *pEditIP, BYTE *pIP, int iLen)
{
	if( pEditIP == NULL || pIP == NULL)
	{
		return HPR_ERROR;
	}

	int iRet;
	char strIP[20];
	memset(strIP, 0, 20);
	//1.get ip str
        iRet = KIT_editToStr(pEditIP, (BYTE *)strIP, 20);
	if(iRet == HPR_ERROR)
	{
		return HPR_ERROR;
	}
    //2.check ip
	iRet = KIT_checkIP(strIP);
	if(iRet == HPR_ERROR)
	{
		return HPR_ERROR;
	}
	else
	{
		memcpy(pIP, strIP, iLen);
	}

	return HPR_OK;
}


//通过用户ID去获取通道信息, iArrayChanelInfo数组：-1表示无信息，非负数表示通道号
//iArrayChanelInfo数组大小为MAX_CHANNUM_V30
int KIT_GetChannelInfo(long lUserID,  PKIT_CHAN_INFO pChanInfo)
{
	if(pChanInfo == NULL || lUserID < 0)
	{
		return HPR_ERROR;
	}

	NET_DVR_DEVICECFG struDeviceParams;
	DWORD paramsLen;
	int iRet;

	//***1.Get the channel number and IP channel number.***//
	iRet = NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_DEVICECFG, -1,
			&struDeviceParams, sizeof(NET_DVR_DEVICECFG), &paramsLen);
	if (iRet == 0)
	{
		iRet = NET_DVR_GetLastError();
		QMessageBox::information(NULL, "Please check!", "Get device parameters error!");
		return HPR_ERROR;
	}
	pChanInfo->cStartNO = (int) (struDeviceParams.byStartChan);

	//***2.Get the channel which is enabled.***//
	//iRet的值用于判断是否支持IP通道
	NET_DVR_IPPARACFG struIPParams;
	iRet = NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_IPPARACFG, -1, &struIPParams, sizeof(NET_DVR_IPPARACFG), &paramsLen);
	int i, j;
	j = 0;
	if (iRet)//if support ip channel
	{
		pChanInfo->cSupportIP = 1;
		//模拟通道
		for (i = 0; i < MAX_ANALOG_CHANNUM; i++)
		{
			if (struIPParams.byAnalogChanEnable[i])
			{
				pChanInfo->iArrayChanInfo[j]= i + pChanInfo->cStartNO;
				j++;
			}
		}

		//IP通道
		for (i = 0; i < MAX_IP_CHANNEL; i++)
		{
			if (struIPParams.struIPChanInfo[i].byIPID != 0)
			{
				pChanInfo->iArrayChanInfo[j] = i + pChanInfo->cStartNO + MAX_ANALOG_CHANNUM;
				j++;
			}
		}
	}
	else//if not support ip channel
	{
		pChanInfo->cSupportIP = 0;
		//simulate channel
		for (i = 0; (i < MAX_ANALOG_CHANNUM)&& (i < struDeviceParams.byChanNum); i++)
		{
			pChanInfo->iArrayChanInfo[j] = i + pChanInfo->cStartNO ;
			j++;
		}
		//m_iSimChannelNum = j;
	}
	pChanInfo->cTotalNum = j;

	//剩余的值都设置为-1
	for(; j < MAX_CHANNUM_V30; j++)
	{
		pChanInfo->iArrayChanInfo[j] = -1;
	}

	return HPR_OK;
}

//通过用户ID去创建一个checkbox数组; new出来的变量，由外部释放
//该数组大小为64, 传入的数组一定不能比这个小，否则程序会崩溃
int KIT_CreateCheckboxChanArr(long lUserID, QCheckBox *qArrChan[], int *piTotalNum)
{
	if(qArrChan == NULL || lUserID < 0)
	{
		return HPR_ERROR;
	}

	KIT_CHAN_INFO struChanInfo;// = {0};
	memset(&struChanInfo, 0,  sizeof(KIT_CHAN_INFO));
	if( KIT_GetChannelInfo(lUserID, &struChanInfo) == HPR_ERROR)
	{
		return HPR_ERROR;
	}

	//清空qArrChan
	int i;
	for(i = 0; i < MAX_CHAN_CHECKBOX; i++)
	{
		qArrChan[i] = NULL;
	}

	//***new check box***//
	char strTemp[100] = { 0 };
	int iStartNO = (int)struChanInfo.cStartNO;
	for (i = 0; i < MAX_CHANNUM_V30; i++)
	{
		//发现一个通道
		if (struChanInfo.iArrayChanInfo[i] >= 0)
		{
			if (struChanInfo.iArrayChanInfo[i] < MAX_ANALOG_CHANNUM) //模拟通道
			{
				sprintf(strTemp, "Camora%d", struChanInfo.iArrayChanInfo[i]);
			}
			else//IP channel
			{
				if (struChanInfo.cSupportIP)//supprot IP channel
				{
					sprintf(strTemp, "IPCamora%d", (struChanInfo.iArrayChanInfo[i] - MAX_ANALOG_CHANNUM));
				}
			}
			//new出来一个新的变量
			qArrChan[struChanInfo.iArrayChanInfo[i] - iStartNO] = new QCheckBox();
			//设置文本类容
			qArrChan[struChanInfo.iArrayChanInfo[i] - iStartNO]->setText(strTemp);
		}
	}

	*piTotalNum = struChanInfo.cTotalNum;
	return HPR_OK;
}

//根据报警输出序号，获取报警输出名称
int getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut)
{
	char strTemp[100] = {0};
	if(iAlarmOut < MAX_ANALOG_ALARMOUT)
	{
		sprintf(strTemp, "AlarmOut%d", iAlarmOut + 1);
	}
	else
	{
		sprintf(strTemp, "IPAlarmOut%d", iAlarmOut - MAX_ANALOG_ALARMOUT + 1);
	}
    pQCheckAlarmOut->setText(strTemp);

	return HPR_OK;
}

int KIT_CreateCheckboxAlarmOut(long lUserID, QCheckBox *qArrAlarmOut[], int *piTotalNum)
{
	if(lUserID < 0 || NULL == qArrAlarmOut || NULL == piTotalNum)
	{
		return HPR_ERROR;
	}

	int iRet;
	DWORD uiReturnLen;
	//可用模拟报警输出个数
	NET_DVR_DEVICECFG struDeviceInfo;
	iRet = NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_DEVICECFG, -1, &struDeviceInfo, sizeof(NET_DVR_DEVICECFG), &uiReturnLen);
    if(iRet == 0)
    {
		iRet = NET_DVR_GetLastError();
		return HPR_ERROR;
		//QMessageBox::information(this, tr("Please check!"), tr("Get device parameters error! \"%1\"").arg(iRet));
    }

    //IP报警输出
	NET_DVR_IPALARMOUTCFG  struIPAlarmOut;
	iRet = NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_IPALARMOUTCFG, -1, &struIPAlarmOut, sizeof(NET_DVR_IPALARMOUTCFG), &uiReturnLen);
    if(iRet == 0)
    {
    	//不支持IP报警输出
    	memset(&struIPAlarmOut, 0, sizeof(struIPAlarmOut));
		iRet = NET_DVR_GetLastError();
		//QMessageBox::information(this, tr("Please check!"), tr("Get device parameters error! \"%1\"").arg(iRet));
    }

	//获取IP报警输出的个数，以设置表格的行数
	int i;
	int iRow = 0;
	for(i = 0; i < MAX_IP_ALARMOUT; i++ )
	{
		if(struIPAlarmOut.struIPAlarmOutInfo[i].byIPID > 0)
		{
			iRow++;
		}
	}
	iRow += struDeviceInfo.byAlarmOutPortNum;
	*piTotalNum = iRow;

    //清空数组，开始new出checkbox
	for(i = 0; i < MAX_ALARMOUT_V30; i++)
	{
		qArrAlarmOut[i] = NULL;
	}
    //new出模拟报警输出
	for(i = 0; i < struDeviceInfo.byAlarmOutPortNum && i < MAX_ANALOG_ALARMOUT; i++)
	{
		//new 一个新的checkbox
		qArrAlarmOut[i] = new(std::nothrow) QCheckBox;
		//获取报警输出名
		getAlarmOutInfo(i, qArrAlarmOut[i]);
	}

	//new出IP报警输出
	for(i = 0; i < MAX_IP_ALARMOUT; i++)
	{
		//判断IP报警输出是否可用
		if(struIPAlarmOut.struIPAlarmOutInfo[i].byIPID > 0)
		{
			//new出来一个新的checkbox
			qArrAlarmOut[i + MAX_ANALOG_ALARMOUT] = new(std::nothrow) QCheckBox;
		    //获取报警输出名称
			getAlarmOutInfo(i + MAX_ANALOG_ALARMOUT, qArrAlarmOut[i + MAX_ANALOG_ALARMOUT]);
		}
	}

	return HPR_OK;
}

//信息类型，提示方式
int KIT_DisplayErrorInfo(char *pInfoType, int iDisplayType)
{
	//目前只支持一种显示方式
	if(NULL == pInfoType || iDisplayType != KIT_ERRPR_DIS_TYPE)
	{
		return HPR_ERROR;
	}

	int iError = 0;
	iError = NET_DVR_GetLastError();
	char strError[100] = {0};
	if (NET_DVR_NOSUPPORT == iError)
	{
		sprintf(strError, "Device not support: %s", pInfoType);
	}
	else
	{
		sprintf(strError, "%s unsuccessfully!error:%d", pInfoType, iError);
	}

	if(KIT_ERRPR_DIS_TYPE == iDisplayType)
	{
		QMessageBox::information(NULL, QObject::tr("Please check!"), strError);
	}

	return HPR_OK;
}












