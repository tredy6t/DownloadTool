#include "MainFrame.h"
#include <sstream>
#include <ctime>
#include "../common/CtrlName.h"
#include "../common/CtrlMessage.h"
#include "../GlobalConfig.h"
#include "../common/ErrorCode.h"

static int kUserCharacter = 9;
static int kDecade = 10;



MainFrame::MainFrame()
{

}


MainFrame::~MainFrame()
{
	PostQuitMessage(0);
}

CDuiString MainFrame::GetSkinFile()
{  
    return String2DuiString(GetToolXml()); 
}

CDuiString MainFrame::GetSkinFolder()
{
    return String2DuiString(GetResourceDir());
}

LRESULT MainFrame::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    return WindowImplBase::HandleMessage(uMsg, wParam, lParam);
}

void MainFrame::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);//窗口销毁
	delete this;
}



void MainFrame::Notify(TNotifyUI & msg)
{
    CDuiString dstrType = msg.sType;
    CDuiString dstrCtrlName = msg.pSender->GetName();
    if (IsSpecifiedMessage(kMessageWindowInit, dstrType))
	{
		//初始化
        init();
	}
	else if (IsSpecifiedMessage(kMessageCtrlClick, dstrType))
	{
		//点击事件
		if (IsCtrlClicked(kCloseButtonControlName, dstrCtrlName))
		{
			OnExit(msg);//退出
		}
		else if (IsCtrlClicked(kMinButtonControlName, dstrCtrlName))
		{
#if defined(UNDER_CE)
			::ShowWindow(m_hWnd, SW_MINIMIZE);
#else
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
#endif
		}
		else if (IsCtrlClicked(kMaxButtonControlName, dstrCtrlName))
		{
#if defined(UNDER_CE)
			::ShowWindow(m_hWnd, SW_MAXIMIZE);
			CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(kMaxButtonControlName));
			if (pControl) pControl->SetVisible(false);
			pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(kRestoreButtonControlName));
			if (pControl) pControl->SetVisible(true);
#else
			SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
#endif
		}
		else if(IsCtrlClicked(kRestoreButtonControlName, dstrCtrlName))
		{
#if defined(UNDER_CE)
			::ShowWindow(m_hWnd, SW_RESTORE);
			CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(kMaxButtonControlName));
			if (pControl) pControl->SetVisible(true);
			pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(kRestoreButtonControlName));
			if (pControl) pControl->SetVisible(false);
#else
			SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
#endif
		}
	}

	OutputDebugString(msg.sType);
	OutputDebugString(L"\n");
}

CControlUI* MainFrame::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void  MainFrame::InitWindow()//create时调用
{
}


void MainFrame::init()
{

}

bool MainFrame::OnClickItem(void* pParam)
{
    return true;
}