/**************************************************************
*
* @brief:       配置文件管理
* @date:        20190803
* @update:
* @auth:        Wite_Chen
* @copyright:
*
***************************************************************/


#pragma once
#include "common/ConfigFile.h"
#include "common/CrossPlat.h"
#include <fstream>
#include <vector>
#include <rapidjson/document.h>

#define QQ_CONFIG_INSTANCE GlobalConfig::Instatnce()
#define QQ_CONFIG QQ_CONFIG_INSTANCE.GetConfig()
#define QQ_CONFIG_SERVER QQ_CONFIG_INSTANCE.GetServerConfig()
#define QQ_CONFIG_CACHEUSER QQ_CONFIG_INSTANCE.GetConfigCacheUser()

class GlobalConfig
{
public:
    struct ConfigServer
    {
        std::string strIP = "127.0.0.1";
        int port = 10000;
        int nTimeoutSend = 10000;
        int nTimeoutRecv = 10000;
        int nHeartBeat = 500;
        void LoadFromJson(rapidjson::Value& value);
    };

    struct CacheUser
    {
        std::string strUser;
        std::string strName;
        std::string strImage;
    };
    struct ConfigCacheUser
    {
        std::vector<CacheUser>vecUser;
        void LoadFromJson(rapidjson::Value& value);
    };

private:
    GlobalConfig() {}
    std::string load_config(const std::string& strFile);
    bool load_from_json(const std::string& datrData);

public:
    static GlobalConfig& Instatnce()
    {
        static GlobalConfig g_Instance;
        return g_Instance;
    }
    bool Init();
    ConfigServer GetServerConfig() { return m_configServer; }
    ConfigCacheUser GetConfigCacheUser() { return m_configCacheUsers; }

private:
    ConfigServer m_configServer;
    ConfigCacheUser m_configCacheUsers;
};

