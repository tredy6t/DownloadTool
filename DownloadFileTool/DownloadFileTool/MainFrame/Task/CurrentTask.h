#pragma once
#include "Task.h"
#include "../../common/ConfigFile.h"


class CurrentTaskWnd : public CListUI
{
public:
    CurrentTaskWnd(CPaintManagerUI& paint_manager);
    ~CurrentTaskWnd();

    bool Add(CControlUI* pControl);

    bool AddAt(CControlUI* pControl, int iIndex);

    bool Remove(CControlUI* pControl, bool bDoNotDestroy = false);

    bool RemoveAt(int iIndex, bool bDoNotDestroy);

    void RemoveAll();

    void DoEvent(TEventUI& event);


private:
    void init();

private:
    CDuiString m_strXml;
    CDialogBuilder m_dlgBuilder;    // 创建需要
    CPaintManagerUI m_PaintManager;

};