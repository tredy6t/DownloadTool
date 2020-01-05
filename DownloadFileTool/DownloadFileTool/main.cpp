#include <easylogging/easylogging++.h>
#include <easylogging/LoggingHelper.h>
#include "GlobalInit.h"
#include "GlobalConfig.h"
#include"mainframe/MainFrame.h"
#include "common/Macro.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    VERIFY_RETURN_OPTION(LogHelper::InitLog(GetLogConfig()), 0);

    if (!GlobalConfig::Instatnce().Init())
    {
        LOG(ERROR) << "Load config falied";
        return 0;
    }

    LOG(INFO) << "Init success";
    CPaintManagerUI::SetInstance(hInstance);
    //资源存放路径
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("Res\\"));


    MainFrame *pMainFrame(new MainFrame());

    pMainFrame->Create(NULL, _T("MainFrame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE, 0, 0, 800, 600);
    if (nullptr == pMainFrame)return -1;
    pMainFrame->CenterWindow();

    CPaintManagerUI::MessageLoop();
    CPaintManagerUI::Term();

    return 0;

}