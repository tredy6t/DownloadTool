#pragma once
#include"../../common/DuilibDefine.h"


struct TaskItem
{
    int nType;      // �ļ����ͣ��������ͼ��ض�Ӧͼ��
    CDuiString dstrFilename;    // �ļ���
    int64_t nTotalLength = 0;   // �ļ���С
    CDuiString dstrUnit;
    int64_t nDownloadedLength = 0;  // �������ļ���С
    std::string strCreateTime;      // �������ʱ��
};