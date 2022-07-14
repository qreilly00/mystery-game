#ifndef TEXTUTILS_HPP
#define TEXTUTILS_HPP

#include "../inc/common.hpp"

//#include "BasicUtils.hpp"
//#include "TextureUtils.hpp"

class TextUtils {
private:
    //BasicUtils ut;
    //TextureUtils tu;

    sf::Font font;

    //std::vector<sf::Font> fonts;
    std::vector<sf::Text> texts;

public:

    // Init class.
    TextUtils();

    void loadFont(std::string);
    void createText(sf::Color, sf::Vector2f, sf::Vector2f, std::string);

    // Allows external class to keep track of the last text it ordered to be created.
    int generateStorageToken(); 

    sf::Font& getFont();
    std::vector<sf::Text>& getTexts();
};

#endif
