#pragma once
#include"../common/DuilibDefine.h"
#include <Duilib/Utils/WinImplBase.h> 
#include "../common/ConfigFile.h"
#include "../mainframe/MainFrame.h"

class MainFrame: public WindowImplBase
{
public:
    MainFrame();
    ~MainFrame();

    //�麯������ʵ��
    virtual LPCTSTR GetWindowClassName()const { return _T("MainFrame";) }
    virtual CDuiString GetSkinFile();
    virtual CDuiString GetSkinFolder();
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    //���ٴ���
    virtual void OnFinalMessage(HWND hWnd);

    //custom source
    virtual CControlUI* CreateControl(LPCTSTR pstrClass);
    virtual void InitWindow();

protected:
    void Notify(TNotifyUI& msg);
    void OnExit(TNotifyUI& msg) { Close(); };

public:
	bool OnClickItem(void* pParam);


private:
    void init();

private:


};

