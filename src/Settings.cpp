#include "Settings.h"

#include <iostream>

Settings& Settings::get() {
    static Settings instance;
    return instance;
}

Settings::Settings() {}
