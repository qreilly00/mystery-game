#include "../TextEntity.hpp"

TextEntity::TextEntity(/*std::string fontName, */sf::Color clr, sf::Vector2f position, sf::Vector2f scale, std::string stringForText) {
    loadFont("../fonts/SourceCodePro-Regular.ttf"/*fontName*/);

    text.setFillColor(clr);

    text.setPosition(position);
    text.setScale(scale.x, scale.y);

    text.setString(stringForText);
}
