#ifndef HUDUTILS_HPP
#define HUDUTILS_HPP

#include "../inc/common.hpp"

#include "TextEntity.hpp"

class HudUtils {
private:
    sf::View hudView;

    int currentHud;

    //std::vector<TextEntity> hudText;
    std::vector<std::vector<TextEntity> > textForEachHud;
    //TextEntity txt;
public:

    // Init class.
    HudUtils();

    // General util functions.
    void initHudView(sf::RenderWindow&, sf::Vector2f);
    void drawText(sf::RenderWindow& window) {for(auto x : textForEachHud[currentHud]) x.drawText(window);}
    void drawText(sf::RenderWindow&, std::string);
    TextEntity createTextEnt() {return TextEntity(sf::Color::White, sf::Vector2f(1000, 0), sf::Vector2f(.6f, .6f), "***");}

    // Property get utils.
    sf::View &getHudView() {return hudView;}

    // Property set utils.
    void setCurrentHud(int crnthd) {currentHud = crnthd;}

};

#endif
