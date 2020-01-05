#pragma once
#include <windows.h> 
#include <objbase.h> 

#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#include <UIlib.h> 
#include <atlstr.h>

using namespace DuiLib;



/**************************************************************
*
* @brief:       DuiStringתstring
* @date:        20190706
* @update:
* @author:      Wite_Chen
*
***************************************************************/
static std::string DuiString2String(const CDuiString& strData)
{
    CString cstrData = strData.GetData();

    return std::string(CW2A(cstrData.GetBuffer()));
}

/**************************************************************
*
* @brief:       stringתDuiString
* @date:        20190706
* @update:
* @author:      Wite_Chen
*
***************************************************************/
static CDuiString String2DuiString(const std::string& strData)
{
    CString cstrData = CA2W(strData.c_str());

    return CDuiString(LPCTSTR(cstrData));
}

/**************************************************************
*
* @brief:       check ctrl is clicked
* @date:        20191005
* @update:
* @author:      Wite_Chen
*
***************************************************************/
static bool IsCtrlClicked(const CDuiString& dstrCtrlName, const CDuiString& dstrClickCtrl)
{
    return 0 == _tcsicmp(dstrCtrlName, dstrClickCtrl);
}

/**************************************************************
*
* @brief:       check is specifice message type
* @date:        20191005
* @update:
* @author:      Wite_Chen
*
***************************************************************/
static bool IsSpecifiedMessage(const CDuiString& dstrMsgDemand, const CDuiString& dstrMsgTriggered)
{
    return 0 == _tcsicmp(dstrMsgDemand, dstrMsgTriggered);
}