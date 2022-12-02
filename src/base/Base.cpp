#include "../Base.hpp"
Base::Base() {
    totalTime = 0;

    currentLevel = 1;
    currentStage = 1;

    buildMode = 0;

    createWindow();
    view.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    std::vector<std::string> textureNames = mu.returnTextureNames();
    int tmpTextMark = -1;
    for(int i = 0; i < textureNames.size(); i++) {
        if(textureNames[i].substr(0, 4).compare("doggo")) tmpTextMark = i;
    }
    player = Entity(sf::Vector2f(64, 64), sf::Vector2f(0, 0), sf::Color::White, 400, &mu.returnTextures()[tmpTextMark], tmpTextMark);

    hu.initHudView(window, sf::Vector2f(1000, 0));

    sf::Vector2f playerPosition = mu.designLevel(currentLevel, rooms, corridors, roomWalls, corridorWalls);
    player.getShape().setPosition(playerPosition.x - (player.getShape().getSize().x / 2), playerPosition.y - (player.getShape().getSize().y / 2));

    objects = mu.loadObjects(1);

    mu.addCollides(collides, roomWalls);
    mu.addCollides(collides, corridorWalls);

    mu.addCollidesCycle(collides, objects);
    //farmObjects.push_back(FarmablePlot(sf::Vector2f(32, 32), sf::Vector2f(32, 32), sf::Color::Black, 1/*, 0, tu.getTextures()*));*/
}
