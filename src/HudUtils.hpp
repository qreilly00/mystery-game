#ifndef HUDUTILS_HPP
#define HUDUTILS_HPP

#include "../inc/common.hpp"

//#include "BasicUtils.hpp"
//#include "TextureUtils.hpp"

class HudUtils {
private:
    //BasicUtils ut;
    //TextureUtils tu;

    sf::View hudView;

public:

    // Init class.
    HudUtils();

    void initHudView(sf::RenderWindow &window);

    // Get and set.
    sf::View &getHudView();

};

#endif
