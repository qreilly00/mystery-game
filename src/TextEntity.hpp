#ifndef TEXTENTITY_HPP
#define TEXTENTITY_HPP

#include "../inc/common.hpp"

class TextEntity {
private:
    sf::Font font;
    sf::Text text;
public:
    // Init class.
    TextEntity(/*std::string, */sf::Color, sf::Vector2f, sf::Vector2f, std::string);

    void loadFont(std::string);
    void drawText(sf::RenderWindow&);

    // Property get utils.
    sf::Font& getFont() {return font;}
    sf::Text& getText() {return text;}

    // Property set utils.
    void setText(std::string txt) {text.setString(txt);}
};

#endif
