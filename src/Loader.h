#ifndef __LOADER_H__
#define __LOADER_H__

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class Loader {
public :
    static sf::Texture& getTexture(std::string path);
    static void clean ();

private :
    static std::map<std::string, sf::Texture* > texturesMap;
};

#endif