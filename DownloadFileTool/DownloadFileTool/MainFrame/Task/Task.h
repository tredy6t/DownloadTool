#pragma once
#include"../../common/DuilibDefine.h"


struct TaskItem
{
    int nType;      // 文件类型，根据类型加载对应图标
    CDuiString dstrFilename;    // 文件名
    int64_t nTotalLength = 0;   // 文件大小
    CDuiString dstrUnit;
    int64_t nDownloadedLength = 0;  // 已下载文件大小
    std::string strCreateTime;      // 下载完成时间
};