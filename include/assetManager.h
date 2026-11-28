#pragma once

#include <string>
#include <map>

#include <SFML/Graphics.hpp>

using std::string;
using std::map;


class AssetManager
{

public:


    sf::Texture* requestTexture(const string& name);


private:

    // Asset paths
    const string path_art {"assets/art/"};
    const string path_font {"assets/fonts/"};
    const string path_music {"assets/music/"};
    const string path_sfx {"assets/sfx/"};

    // Textures
    map<string, sf::Texture> textures;


};



