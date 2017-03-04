#include "Settings.h"

#include <iostream>

Settings& Settings::get() {
    static Settings instance;
    return instance;
}

Settings::Settings() {
    std::ifstream ifs(SETTINGS_PATH("settings.json"));
    this->settings = json::parse(ifs);

    LoadImagesSettings();
    LoadImagePattern();
}

void Settings::LoadImagesSettings () {
    json imageSett = settings["images"];
    for (json::iterator it = imageSett.begin(); it != imageSett.end(); ++it) {
        json sett = it.value();
        ImageSettings iSett;

        iSett.frame = sett["frame"].get<int>();
        iSett.width = sett["width"].get<int>();
        iSett.height = sett["height"].get<int>();

        imagesSettings[it.key()] = iSett;
    }
}

void Settings::LoadImagePattern () {
    json imagePatt = settings["image_pattern"];
    for (json::iterator it = imagePatt.begin(); it != imagePatt.end(); ++it)
        imagesPattern[it.key()[0]] = it.value().get<std::string>();
        // key need to be a character, so we take only the first in case of a strange key
}

const ImageSettings Settings::getImageSettings (std::string img) {
    return imagesSettings.at(img);
}

std::string Settings::getImageForPattern (char c) {
    return imagesPattern.at(c);
}
