#include "Loader.h"

static sf::Texture* Loader::getTexture(sdt::string path) {
    if (this->texturesMap.find(path) !== this->texturesMap.end()) {
        sf::Texture tx*;
        if (!tx->loadFromFile(path)) {
            std::cerr << "impossible d'oucrir la texture : " << path << std::endl;
            exit(1);
        }
        return this->texturesMap[path] = tx;
    }

    return this->texturesMap[path];
}
