/**************************************************************
*
* @brief:       macro
* @date:        20190702
* @update:
* @auth:        Wite_Chen
* @copyright:
*
***************************************************************/
#pragma once



#define  VERIFY_RETURN(expr) \
    if(!expr) \
    {   \
        return; \
    }   

#define  VERIFY_RETURN_OPTION(expr, ret) \
    if(!expr) \
    {   \
        return ret; \
    }   
