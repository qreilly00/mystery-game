#include "../MapUtils.hpp"

std::vector<LevelShape> MapUtils::loadObjects(int level) {
    //std::ifstream ifs ("../map-" + std::to_string(level) + "-objects");

    std::vector<std::string> input = ut.getFileLines("../map-" + std::to_string(level) + "-objects");
    std::vector<LevelShape> objs;

    //std::cout << input[0] << std::endl;

    for(int i = 0; i < input.size(); i++) {
        bool firstCoordGrabbed = 0;

        sf::Vector2f size = sf::Vector2f(0, 0);
        sf::Vector2f position = sf::Vector2f(0, 0);

        float* tmpPointer = &size.x;

        for(int j = 0; j < input[i].size(); j++) {
            if(input[i][j] == ',') {
                tmpPointer == &size.x ? tmpPointer = &size.y : tmpPointer = &position.y;
            } else if(input[i][j] == ')' && firstCoordGrabbed == 0) {
                firstCoordGrabbed = 1;
                tmpPointer = &position.x;
            } else if(input[i][j] == ')' && firstCoordGrabbed == 1) {
                break;
            } else if(input[i][j] >= '0' && input[i][j] <= '9') {
                *tmpPointer *= float(10); *tmpPointer += float(input[i][j] - '0');
            }

            //std::cout << input[i][j] << std::endl;
        }

        objs.push_back(LevelShape(size, position, sf::Color::Black, 1, 1, 1));
    }

    //std::cout << size.x << " " << size.y << " " << position.x << " " << position.y << std::endl;

    return objs;
}
