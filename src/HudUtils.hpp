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

    std::vector<int> textTokens;

public:

    // Init class.
    HudUtils();

    void initHudView(sf::RenderWindow&);

    void drawText(sf::RenderWindow&);

    // Get and set.
    sf::View &getHudView();

};

#endif
