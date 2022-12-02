#include "../HudUtils.hpp"

HudUtils::HudUtils() {
    // testing out the text class here.
    currentHud = 0;

    textForEachHud.push_back(std::vector<TextEntity>());
    textForEachHud[currentHud].push_back(TextEntity(sf::Color::White, sf::Vector2f(1000, 0), sf::Vector2f(.6f, .6f), "***"));
}
