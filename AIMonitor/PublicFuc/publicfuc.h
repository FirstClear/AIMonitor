/*
 * publicfuc.h
 *
 *  Created on: 2009-11-5
 *      Author: letian
 */

#ifndef PUBLICFUC_H_
#define PUBLICFUC_H_

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <stdio.h>
#include "DemoPublic.h"

#ifndef HPR_OK
#define HPR_OK 0
#endif

#ifndef HPR_ERROR
#define HPR_ERROR -1
#endif

#ifndef INT_LEN
#define INT_LEN 10  //the length of the string of 32 bit int
#endif

#ifndef IP_LEN
#define IP_LEN 16 //一个IP地址的最大长度
#endif

#define KIT_ERRPR_DIS_TYPE 1

typedef struct
{
	int iArrayChanInfo[MAX_CHANNUM_V30]; //-1表示无效通道号; 已+起始通道号
	char  cStartNO;          //起始通道号
	char  cTotalNum;        //可用通道总数, 也可以由iArrayChanInfo[]值大于-1的数，统计出来
	char  cSupportIP;       //是否支持IP通道0：不支持，1：支持
	char  cRes;
}KIT_CHAN_INFO, *PKIT_CHAN_INFO;

int KIT_editToInt(const QLineEdit *pEdit, int *pNum);

int KIT_intToEdit(QLineEdit *pEdit, int iNum);
int KIT_unintToEdit(QLineEdit *pEdit, unsigned int iNum);

int KIT_checkIP(char * ip);//check ip
int KIT_editToStr(const QLineEdit *pEdit, BYTE *pStr, int iLen);
int KIT_editToIP(const QLineEdit *pEditIP, BYTE *pIP, int iLen);

int KIT_qstringToStr(const QString *pString, BYTE *pStr, int iLen);
int KIT_qstringToInt(const QString *pString, int *pNum);

//通过用户ID去获取通道信息, iArrayChanelInfo数组大小为MAX_CHANNUM_V30
int KIT_GetChannelInfo(long lUserID,  PKIT_CHAN_INFO pChanInfo);

//通过用户ID去创建一个可用通道的checkbox数组; new出来的变量，由外部释放
//该数组大小为64, 传入的数组一定不能比这个小，否则程序会崩溃
int KIT_CreateCheckboxChanArr(long lUserID, QCheckBox *qArrChan[], int *piTotalNum);

//根据报警输出序号，获取报警输出名称
int getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut);
//获取可用报警输出通道Checkbox数组； new出来的变量，由外部释放
//该数组大小为MAX_ALARMOUT_V30, 传入的数组一定不能比这个小，否则程序会崩溃
int KIT_CreateCheckboxAlarmOut(long lUserID, QCheckBox *qArrAlarmOut[], int *piTotalNum);

//显示错误提示信息
int KIT_DisplayErrorInfo(char *pInfoType, int iDisplayType);

void KIT_OutputDebugString(const char * );

#endif /* PUBLICFUC_H_ */
