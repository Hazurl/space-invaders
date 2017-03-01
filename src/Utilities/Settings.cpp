#include "Settings.h"

#include <iostream>

using json = nlohmann::json;

Settings& Settings::get() {
    static Settings instance;
    return instance;
}

Settings::Settings() {
    LoadImagesSettings();
}

void Settings::LoadImagesSettings () {
    std::ifstream ifs(SETTINGS_PATH("settings.json"));
    json j = json::parse(ifs);

    j = j["images"];
    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        json sett = it.value();
        ImageSettings iSett;

        iSett.frame = sett["frame"].get<int>();
        iSett.width = sett["width"].get<int>();
        iSett.height = sett["height"].get<int>();

        imagesSettings[it.key()] = iSett;
    }
}

const ImageSettings Settings::getImageSettings (std::string img) {
    return imagesSettings.at(img);
}
