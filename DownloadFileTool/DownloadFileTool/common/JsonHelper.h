/**************************************************************
*
* @brief:       macro of JSON
* @date:         20190702
* @update:
* @auth:         Wite_Chen
* @copyright:
*
***************************************************************/

#pragma once
#define JS_PARSE(json, para)  \
    {   \
        json.Parse(para.c_str());   \
        if(json.HasParseError())    \
        {   \
            return; \
        }   \
    } 

#define JS_PARSE_RETURN(json, para, ret)  \
    {   \
        json.Parse(para.c_str());   \
        if(json.HasParseError())    \
        {   \
            return ret; \
        }   \
    } 


#define JS_VERIFY_OBJECT(json) \
    {   \
        if(!json.IsObject()) \
        {   \
            return; \
        }   \
    }

#define JS_PARSE_OPTION(to, json, type, field) \
    {   \
        if(json.HasMember(#field) && json[#field].Is##type())  \
        {   \
            to = json[#field].Get##type();  \
        }   \
        else \
        {   \
            return;    \
        }   \
    }


#define JS_PARSE_OPTION_RETURN(to, json, type, field, ret) \
    {   \
        if(json.HasMember(#field) && json[#field].Is##type())  \
        {   \
            to = json[#field].Get##type();  \
        }   \
        else \
        {   \
            return ret;    \
        }   \
    }

#define JS_PARSE_OPTION_RETURN_VOID(to, json, type, field) \
    {   \
        if(json.HasMember(#field) && json[#field].Is##type())  \
        {   \
            to = json[#field].Get##type();  \
        }   \
        else \
        {   \
            return;    \
        }   \
    }