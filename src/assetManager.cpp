#include "../include/assetManager.h"

#include <iostream>

sf::Texture* AssetManager::requestTexture(const string& name)
{

    sf::Texture* t = &textures[name];

    // Check GL handle. GL uses 0 for an unloaded texture,
    // this is how we know that we need to load from file
    if (t->getNativeHandle() == 0)
    {
        t->loadFromFile(path_art + name);
    }

    return t;

}



