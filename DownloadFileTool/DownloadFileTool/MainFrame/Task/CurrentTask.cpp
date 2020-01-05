#include "CurrentTask.h"
#include <sstream>
#include <ctime>
#include "../../common/CtrlName.h"
#include "../../common/CtrlMessage.h"
#include "../../GlobalConfig.h"
#include "../../common/ErrorCode.h"




CurrentTaskWnd::CurrentTaskWnd(CPaintManagerUI& paint_manager)
    : m_PaintManager(paint_manager)
{
    m_strXml = String2DuiString(GetCurrentTaskXmlFile());
}


CurrentTaskWnd::~CurrentTaskWnd()
{
}


bool CurrentTaskWnd::Add(CControlUI* pControl)
{
    return true;
}

bool CurrentTaskWnd::AddAt(CControlUI* pControl, int iIndex)
{
    return true;
}

bool CurrentTaskWnd::Remove(CControlUI* pControl, bool bDoNotDestroy)
{

    return true;
}

bool CurrentTaskWnd::RemoveAt(int iIndex, bool bDoNotDestroy)
{
    return true;
}

void CurrentTaskWnd::RemoveAll()
{

}

void CurrentTaskWnd::DoEvent(TEventUI& event)
{

}

