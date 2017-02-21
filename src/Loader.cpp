#include "Loader.h"

#include <iostream>

std::map<std::string, sf::Texture* > Loader::texturesMap;

void Loader::clean () {
    for (auto it = Loader::texturesMap.begin(); it != Loader::texturesMap.end(); ++it)
        delete it->second;
}

sf::Texture& Loader::getTexture(std::string path) {
    if (Loader::texturesMap.find(path) == Loader::texturesMap.end()) {
        sf::Image* img = new sf::Image();
        if (!img->loadFromFile(path)) {
            std::cerr << "Impossible d'oucrir la texture : " << path << std::endl;
            exit(1);
        }

        img->createMaskFromColor(MASK_COLOR, 0);

        sf::Texture* tx = new sf::Texture();
        tx->loadFromImage(*img);

        delete img;

        return *(Loader::texturesMap[path] = tx);
    }

    return *Loader::texturesMap[path];
}
