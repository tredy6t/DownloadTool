/**************************************************************
*
* @brief:       QQ error code
* @date:        20190703
* @update:
* @auth:        Wite_Chen
* @copyright:
*
***************************************************************/


#pragma once

#define QQ_OK  0

//登录界面  1000+
#define QQ_PASSWORD_ERROR       1001        //密码错误
#define QQ_INVALID_ACCOUNT      1002        //无效账户
#define QQ_NET_ERROR            1003        //网络异常
#define QQ_ALREDY_LOGIN         1004        //账户已登录

//json解析错误  2000+
#define QQ_PARSE_ERROR          2001        //解析错误    
#define QQ_NOT_ARRAY            2002        //不是数组
#define QQ_NOT_STRING           2003        //不是字符串