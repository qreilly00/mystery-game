#include "../MapUtils.hpp"

std::vector<LevelShape> MapUtils::loadObjects(int level) {
    std::vector<std::string> input = ut.readFileLines("../maps/map-" + std::to_string(level) + "-objects");
    std::vector<LevelShape> objs;

    if(input.size() != 0) {
        for(int i = 0; i < input.size() - 1; i++) {
            int firstCoordGrabbed = 0;
            int lastOtherPropertyGrabbed = -1;

            sf::Vector2f size = sf::Vector2f(0, 0);
            sf::Vector2f position = sf::Vector2f(0, 0);
            int color = 0;
            int isCol = 0;
            int idx = 0;
            int lvl = 0;
            int stage = 0;
            bool isFG = 0;

            float* tmpPointer = &size.x;

            for(int j = 0; j < input[i].size(); j++) {
                if(input[i][j] == ',') {
                    tmpPointer == &size.x ? tmpPointer = &size.y : tmpPointer = &position.y;
                } else if(input[i][j] == ')' && firstCoordGrabbed == 0) {
                    firstCoordGrabbed++;
                    tmpPointer = &position.x;
                } else if(input[i][j] == ')' && firstCoordGrabbed == 1) {
                    lastOtherPropertyGrabbed++;
                    firstCoordGrabbed++;
                    //break;
                } else if(input[i][j] == ')' && lastOtherPropertyGrabbed != -1) {
                    if(lastOtherPropertyGrabbed == 5) {break;}
                    lastOtherPropertyGrabbed++;
                } else if(input[i][j] >= '0' && input[i][j] <= '9') {
                    if(firstCoordGrabbed < 2) {*tmpPointer *= float(10); *tmpPointer += float(input[i][j] - '0');}
                    (lastOtherPropertyGrabbed == 0) ? (color *= (10), color += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 1) ? (isCol *= (10), isCol += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 2) ? (idx *= (10), idx += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 3) ? (lvl *= (10), lvl += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 4) ? (stage *= (10), stage += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 5) ? (isFG *= (10), isFG += (input[i][j] - '0')):(0);
                }
            }

            objs.push_back(LevelShape(size, position, sf::Color(color), isCol, isFG, lvl, stage, &tu.getTextures()[idx], idx /*sf::Color::White, 1, 1, 1*/));
        }
    }

    return objs;
}
