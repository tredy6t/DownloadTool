#include "GlobalConfig.h"
#include "common/JsonHelper.h"
#include "common/Macro.h"
#include <easylogging/easylogging++.h>


bool GlobalConfig::Init()
{
    VERIFY_RETURN_OPTION(load_from_json(load_config(GetConfigFile())), false);

    return true;
}

std::string GlobalConfig::load_config(const std::string& strFile)
{
    if (0 == QQ_access(strFile.c_str(), 0))
    {
        std::fstream fin(strFile, std::ios::in);
        if (fin.is_open())
        {
            fin.seekg(0, std::ios::end);
            int64_t nFileSize = fin.tellp();
            fin.seekg(0, std::ios::beg);
            std::vector<char>vecData(nFileSize + 1, 0);
            fin.read(vecData.data(), nFileSize);
            fin.close();
            LOG(INFO) << "Load config file:" << strFile << " success";
            return vecData.data();
        }
    }
    LOG(ERROR) << "Can't find config file:" << strFile;
    return "";
}

bool GlobalConfig::load_from_json(const std::string& datrData)
{
    rapidjson::Document doc;
    JS_PARSE_RETURN(doc, datrData, false);

    if (doc.HasMember("server_info") && doc["server_info"].IsObject())
    {
        m_configServer.LoadFromJson(doc["server_info"]);
    }
    if (doc.HasMember("user_list") && doc["user_list"].IsArray())
    {
        m_configCacheUsers.LoadFromJson(doc["user_list"]);
    }
    return true;
}

void GlobalConfig::ConfigServer::LoadFromJson(rapidjson::Value& value)
{
    JS_PARSE_OPTION(strIP, value, String, ip);
    JS_PARSE_OPTION(port, value, Int, port);
    JS_PARSE_OPTION(nTimeoutSend, value, Int, time_out_send);
    JS_PARSE_OPTION(nTimeoutRecv, value, Int, time_out_recv);
    JS_PARSE_OPTION(nHeartBeat, value, Int, heart_beat);
}

void GlobalConfig::ConfigCacheUser::LoadFromJson(rapidjson::Value& value)
{
    for (int i = 0; i < value.Size(); ++i)
    {
        rapidjson::Value& valueInfo = value[i];
        CacheUser user;
        JS_PARSE_OPTION_RETURN_VOID(user.strUser, valueInfo, String, id);
        JS_PARSE_OPTION_RETURN_VOID(user.strName, valueInfo, String, name);
        JS_PARSE_OPTION_RETURN_VOID(user.strImage, valueInfo, String, image);
        vecUser.push_back(user);
    }
}