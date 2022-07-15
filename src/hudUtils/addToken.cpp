#include "../HudUtils.hpp"

void HudUtils::addToken() {
    textTokens[currentHud].push_back(txtu.generateStorageToken());
}
