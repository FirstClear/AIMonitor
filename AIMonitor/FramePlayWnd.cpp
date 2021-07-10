 /*
 * Copyright(C) 2010,Custom Co., Ltd 
 *    FileName: FramePlayWnd.cpp
 * Description: 
 *     Version: 1.0
 *      Author: panyadong
 * Create Date: 2010-6-24
 * Modification History：
 */

#include <QtWidgets/QFrame>
#include<QtGui/qevent.h>
#include "FramePlayWnd.h"
#include "PublicFuc/publicfuc.h"

/*******************************************************************
*      Function:   QFrame
*   Description:   structure function
*     Parameter:   (IN)   parent   parent object.   
**********************************************************************/
CFramePlayWnd::CFramePlayWnd(QWidget *parent): QFrame(parent)
{
    ui.setupUi(this);
    m_iBorderWidth = 2;
    m_iBorderHeiht = 2;
    m_bSelected = FALSE;

    setStyleSheet("border: 2px solid gray;");



    m_pframePlay = ui.framePlayWnd;
    m_pframePlay->move(m_iBorderWidth, m_iBorderHeiht);//和上面的border保持一致
    m_pframePlay->setStyleSheet("border: none;");
}

/*******************************************************************
*      Function:   CFramePlayWnd::~CFramePlayWnd
*   Description:   析构函数
*     Parameter:   (IN)   无参数  
**********************************************************************/
CFramePlayWnd::~CFramePlayWnd()
{
}

/*******************************************************************
      Function:   CFramePlayWnd::resizeEvent
   Description:   new size
     Parameter:   (IN)   QResizeEvent *event  Size event.
        Return:   none   
**********************************************************************/
void CFramePlayWnd::resizeEvent(QResizeEvent *event)
{
    int iTempWidth;
    int iTempHeight;
    iTempWidth = event->size().width();
    iTempHeight = event->size().height();

    m_pframePlay->resize(iTempWidth - 2*2, iTempHeight - 2*2);
}

/*******************************************************************
      Function:   CFramePlayWnd::GetPlayWndId
   Description:   Get play HWND in Windows.
     Parameter:   none  
        Return:   Window ID.  
**********************************************************************/
WId CFramePlayWnd::GetPlayWndId()
{
    return m_pframePlay->winId();
}

/********************************************************************
*      Function:   CFramePlayWnd::GetPlayRect
*   Description:   Get play rect in Linux.
*     Parameter:   (IN)   CLIENT_PLAY_RECT* pPlayRect  
*        Return:   0--success，-1--fail.   
**********************************************************************/
int CFramePlayWnd::GetPlayRect(CLIENT_PLAY_RECT* pPlayRect)
{
    if (NULL == pPlayRect)
    {
        return HPR_ERROR;
    }
    pPlayRect->iX = x() + m_iBorderWidth;
    pPlayRect->iY = y() + m_iBorderHeiht;

    //计算尺寸
    pPlayRect->iWidth = m_pframePlay->width();
    pPlayRect->iHeight = m_pframePlay->height();
    return HPR_OK;
}


void CFramePlayWnd::mouseReleaseEvent(QMouseEvent * event)
{
    emit SingleClickSig();
}

