#ifndef TEXTUREUTILS_HPP
#define TEXTUREUTILS_HPP

#include "../inc/common.hpp"

#include "BasicUtils.hpp"

class TextureUtils {
private:
    BasicUtils ut;

    // Visual editor variables.
    std::vector<sf::Texture> textures;

public:

    // Init class.
    TextureUtils();

    // Main functions.
    void loadAllTextures();
    std::vector<int> loadAllTextures(std::string);
    // Get and set.
    std::vector<sf::Texture>& getTextures();
};

#endif
