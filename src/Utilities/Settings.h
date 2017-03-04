#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <string>
#include <map>
#include "Define.h"
#include "../../lib/json.hpp"
#include <fstream>

using json = nlohmann::json;

struct ImageSettings {
    int frame;
    int width;
    int height;
};

class Settings {
public:
    Settings(Settings const&)                   = delete;
    void operator=(Settings const&)             = delete;
    static Settings& get();

    const ImageSettings getImageSettings (std::string img);
    std::string getImageForPattern (char c);

private:
    Settings();
    void LoadImagesSettings ();
    void LoadImagePattern();

    std::map<std::string, ImageSettings> imagesSettings;
    std::map<char, std::string> imagesPattern;

    json settings;
};

#endif