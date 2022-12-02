#ifndef TEXTUREUTILS_HPP
#define TEXTUREUTILS_HPP

#include "../inc/common.hpp"

#include "BasicUtils.hpp"

class TextureUtils {
private:
    BasicUtils ut;

    // Visual editor variables.
    std::vector<sf::Texture> textures;
    std::vector<std::string> textureNames;
public:

    // Init class.
    //TextureUtils();

    // Main functions.
    void loadAllTextures();
    std::vector<int> loadAllTextures(std::string);

    // Get and set.
    std::vector<sf::Texture>& getTextures() {return textures;}
    std::vector<std::string>& getTextureNames() {return textureNames;}
};

#endif
