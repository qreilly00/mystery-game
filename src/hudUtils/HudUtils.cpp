#include "../HudUtils.hpp"

HudUtils::HudUtils() {
    // testing out the text class here.
    txtu.createText(sf::Color::White, sf::Vector2f(1000, 0), sf::Vector2f(1, 1), "This is a test string!");
    textTokens.push_back(txtu.generateStorageToken());

    txtu.createText(sf::Color::White, sf::Vector2f(1000, 50), sf::Vector2f(1, 1), "This is a test string!");
    textTokens.push_back(txtu.generateStorageToken());

    for(auto x : textTokens) {
        std::cout << x << std::endl;
    }
}
