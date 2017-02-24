#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <string>
#include <map>
#include "Define.h"

class Settings {
public:
    Settings(Settings const&)                   = delete;
    void operator=(Settings const&)             = delete;
    static Settings& get();

private:
    Settings();
};

#endif