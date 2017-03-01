#ifndef __LOADER_H__
#define __LOADER_H__

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

#define MASK_COLOR sf::Color(0, 0, 0)

class Loader {
public:
    Loader(Loader const&)               = delete;
    void operator=(Loader const&)            = delete;
    static Loader& get();

    sf::Texture& getTexture(std::string path);

private:
    Loader();
    std::map<std::string, sf::Texture* > texturesMap;
};

#endif