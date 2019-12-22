#pragma once

class GlobalInit
{
private:
    GlobalInit()
    {

    }

public:
    static GlobalInit& Instance()
    {
        static GlobalInit g_Instance;
        return g_Instance;
    }
    ~GlobalInit()
    {

    }
    bool Init()
    {
        return true;
    }
};

