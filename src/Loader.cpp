#include "Loader.h"

#include <iostream>

sf::Texture& Loader::getTexture(std::string path) {
    if (texturesMap.find(path) == texturesMap.end()) {
        sf::Image* img = new sf::Image();
        if (!img->loadFromFile(path)) {
            std::cerr << "Impossible d'oucrir la texture : " << path << std::endl;
            exit(1);
        }

        img->createMaskFromColor(MASK_COLOR, 0);

        sf::Texture* tx = new sf::Texture();
        tx->loadFromImage(*img);

        delete img;

        return *(texturesMap[path] = tx);
    }

    return *texturesMap[path];
}

Loader& Loader::get() {
    static Loader instance;
    return instance;
}

Loader::Loader() {}
