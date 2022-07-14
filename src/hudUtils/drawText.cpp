#include "../HudUtils.hpp"

void HudUtils::drawText(sf::RenderWindow& window) {
    /*std::vector<sf::Text> txtuTmp;
    std::vector<sf::Text&> textFromTokens;*/

    //sf::Font tmpFont = txtu.getFont();

    //txtuTmp = txtu.getTexts();

    for(int i = 0; i < textTokens.size(); i++) {
        for(int j = 0; j < txtu.getTexts().size(); j++) {
            if(j == textTokens[i]) {
                /*std::string tmp = txtu.getTexts()[j].getString();
                std::cout << tmp << std::endl;*/
                window.draw(txtu.getTexts()[j]);
            }
        }
    }
    window.draw(txtu.getTexts()[0]);
    //std::string tmpStr = textFromTokens[0].getString(); std::cout << tmpStr << std::endl;
    //for(auto x : textFromTokens) {window.draw(x);}
}
