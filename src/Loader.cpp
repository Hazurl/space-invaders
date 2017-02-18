#include "Loader.h"

#include <iostream>

std::map<std::string, sf::Texture* > Loader::texturesMap;

void Loader::clean () {
    for (auto it = Loader::texturesMap.begin(); it != Loader::texturesMap.end(); ++it)
        delete it->second;
}

sf::Texture& Loader::getTexture(std::string path) {
    if (Loader::texturesMap.find(path) == Loader::texturesMap.end()) {
        sf::Texture* tx = new sf::Texture();
        if (!tx->loadFromFile(path)) {
            std::cerr << "impossible d'oucrir la texture : " << path << std::endl;
            exit(1);
        }
        return *(Loader::texturesMap[path] = tx);
    }

    return *Loader::texturesMap[path];
}
