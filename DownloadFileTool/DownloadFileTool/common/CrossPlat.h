#pragma once
#ifdef _WIN32
#include <io.h>

#else
#include <unistd.h>

#endif // _WIN32




#ifdef _WIN32
#define QQ_access(file,mode) _access(file,mode)
#define QQ_local_time(time,tm) localtime_s(&tm, &time)


#else
#define QQ_access(file,mode) access(file,mode)
#define QQ_local_time(time,tm) localtime_r(&time, &tm)

#endif // _WIN32

