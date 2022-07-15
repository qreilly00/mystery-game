#ifndef HUDUTILS_HPP
#define HUDUTILS_HPP

#include "../inc/common.hpp"

//#include "BasicUtils.hpp"
//#include "TextureUtils.hpp"
#include "TextUtils.hpp"

class HudUtils {
private:
    //BasicUtils ut;
    //TextureUtils tu;
    TextUtils txtu;

    sf::View hudView;

    int currentHud;

    std::vector<std::vector<int> > textTokens;

public:

    // Init class.
    HudUtils();

    void initHudView(sf::RenderWindow&, sf::Vector2f);

    void drawText(sf::RenderWindow&);
    void drawText(sf::RenderWindow&, std::string, int);
    void addToken();

    // Get and set.
    sf::View &getHudView();

    void setCurrentHud(int);

};

#endif
