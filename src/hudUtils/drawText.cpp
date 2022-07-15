#include "../HudUtils.hpp"

void HudUtils::drawText(sf::RenderWindow& window) {
    for(int i = 0; i < textTokens[currentHud].size(); i++) {
        for(int j = 0; j < txtu.getTexts().size(); j++) {
            if(j == textTokens[currentHud][i]) {
                /*std::string tmp = txtu.getTexts()[j].getString();
                std::cout << tmp << std::endl;*/
                window.draw(txtu.getTexts()[j]);
            }
        }
    }
}

void HudUtils::drawText(sf::RenderWindow& window, std::string textToDisplay, int buildMode) {
    if(buildMode == 1) {
        txtu.getTexts()[0].setString(textToDisplay);
        window.draw(txtu.getTexts()[0]);
    }
}
