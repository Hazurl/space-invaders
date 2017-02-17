#ifndef __LOADER_H__
#define __LOADER_H__

#include <string>
#include <map>

static class Loader {
public :
    static sf::Texture* getTexture(sdt::string path);

private :
    static std::map<string, sf::Texture* > texturesMap;
};

#endif