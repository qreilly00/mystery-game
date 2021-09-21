#include "../Base.hpp"

float Base::calculateFrameStep() {return (player.getSpeed() * player.getSpeedMultiplier()) * totalTime;}
