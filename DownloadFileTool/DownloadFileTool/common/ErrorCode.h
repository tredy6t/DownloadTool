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

//��¼����  1000+
#define QQ_PASSWORD_ERROR       1001        //�������
#define QQ_INVALID_ACCOUNT      1002        //��Ч�˻�
#define QQ_NET_ERROR            1003        //�����쳣
#define QQ_ALREDY_LOGIN         1004        //�˻��ѵ�¼

//json��������  2000+
#define QQ_PARSE_ERROR          2001        //��������    
#define QQ_NOT_ARRAY            2002        //��������
#define QQ_NOT_STRING           2003        //�����ַ���