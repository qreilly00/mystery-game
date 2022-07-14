#include "../TextUtils.hpp"

void TextUtils::createText(sf::Color clr, sf::Vector2f position, sf::Vector2f scale, std::string stringForText) {
    texts.push_back(sf::Text());

    texts[texts.size() - 1].setFont(font);

    texts[texts.size() - 1].setFillColor(clr);

    texts[texts.size() - 1].setPosition(position);
    texts[texts.size() - 1].setScale(scale.x, scale.y);

    texts[texts.size() - 1].setString(stringForText);
}
