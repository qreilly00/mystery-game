#include "../HudUtils.hpp"

void HudUtils::drawText(sf::RenderWindow& window, std::string textToDisplay) {
    textForEachHud[currentHud][0].setText(textToDisplay);
    textForEachHud[currentHud][0].drawText(window);
}
