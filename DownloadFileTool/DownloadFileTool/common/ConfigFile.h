/**************************************************************
*
* @brief:       XML文件变量定义
* @date:        20190709
* @update:
* @auth:        Wite_Chen
* @copyright:
*
***************************************************************/

#pragma once
#include <string>
#ifdef WIN32
    #include <direct.h>
    #include <windows.h>
#else
    #include <unistd.h> //linux
#endif

//conf
static std::string kConfigDir = "conf//";
static std::string kConfigName = "tool.conf";
static std::string kLogConfig = "log.conf";


//resource directory
static std::string kResourcePrefix = "Res//";
static std::string kToolXmlFile = "MainFrame.xml";





/************************************************************************
*                                   function                            *
*************************************************************************/
//获取当前路径
static std::string GetCurrentPath()
{
    const int MAX_RESOURCE_PATH = 260;
    char szPath[MAX_RESOURCE_PATH] = { 0 };
    _getcwd(szPath, MAX_RESOURCE_PATH);
    std::string strCurrPath(szPath);
    if (strCurrPath.back() != '\\')
    {
        strCurrPath += "\\";
    }
    return strCurrPath;
}

//获取可执行文件路径
static std::string GetModulePath()
{
    const int MAX_RESOURCE_PATH = 260;
    char szPath[MAX_RESOURCE_PATH] = { 0 };
    GetModuleFileNameA(NULL, szPath, MAX_RESOURCE_PATH);
    std::string strPath(szPath);
    int nPos = strPath.rfind("\\");
    if (nPos != std::string::npos)
    {
        strPath = strPath.substr(0, nPos + 1);
    }
    return strPath;
}

/************************************************************************
*                                   config                              *
*************************************************************************/
static std::string GetConfigDir()
{
    return GetModulePath() + kConfigDir;
}

static std::string GetConfigFile()
{
    return  GetConfigDir() + kConfigName;
}

static std::string GetLogConfig()
{
    return GetConfigDir() + kLogConfig;
}

/************************************************************************
*                                   XML                                 *
*************************************************************************/
static std::string GetResourceDir()
{
    return GetModulePath() + kResourcePrefix;
}

static std::string GetToolXml()
{
    return kToolXmlFile;
}
