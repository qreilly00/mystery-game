#include "../HudUtils.hpp"

HudUtils::HudUtils() {
    // testing out the text class here.
    currentHud = 0;

    textTokens.push_back(std::vector<int>());

    txtu.createText(sf::Color::White, sf::Vector2f(1000, 0), sf::Vector2f(.6f, .6f), "***");
    textTokens[currentHud].push_back(txtu.generateStorageToken());
}
