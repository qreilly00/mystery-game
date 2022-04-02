#include "../MapUtils.hpp"

std::vector<LevelShape> MapUtils::loadObjects(int level) {
    //std::ifstream ifs ("../map-" + std::to_string(level) + "-objects");

    std::vector<std::string> input = ut.getFileLines("../maps/map-" + std::to_string(level) + "-objects");
    std::vector<LevelShape> objs;

    //std::cout << input[0] << std::endl;

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
                    if(lastOtherPropertyGrabbed == 4) {break;}
                    lastOtherPropertyGrabbed++;
                } else if(input[i][j] >= '0' && input[i][j] <= '9') {
                    if(firstCoordGrabbed < 2) {*tmpPointer *= float(10); *tmpPointer += float(input[i][j] - '0');}
                    (lastOtherPropertyGrabbed == 0) ? (color *= (10), color += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 1) ? (isCol *= (10), isCol += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 2) ? (idx *= (10), idx += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 3) ? (lvl *= (10), lvl += (input[i][j] - '0')):(0);
                    (lastOtherPropertyGrabbed == 4) ? (stage *= (10), stage += (input[i][j] - '0')):(0);
                }

                //std::cout << input[i][j] << std::endl;
            }

            objs.push_back(LevelShape(size, position, sf::Color(color), isCol, &tu.getTextures()[idx], idx, lvl, stage /*sf::Color::White, 1, 1, 1*/));
        }
    }

    //std::cout << size.x << " " << size.y << " " << position.x << " " << position.y << std::endl;

    return objs;
}

/*#include "../MapUtils.hpp"

std::vector<LevelShape> MapUtils::loadObjects(int level) {
    //std::ifstream ifs ("../map-" + std::to_string(level) + "-objects");

    std::vector<std::string> input = ut.getFileLines("../maps/map-" + std::to_string(level) + "-objects");
    std::vector<LevelShape> objs;

    //std::cout << input[0] << std::endl;

    if(input.size() != 0) {
        for(int i = 0; i < input.size() - 1; i++) {
            int lastCoordGrabbed = 0;

            sf::Vector2f size = sf::Vector2f(0, 0);
            sf::Vector2f position = sf::Vector2f(0, 0);
            sf::Color color;
            int isCol = 0;
            int lvl = 1;
            int stage = 1;

            void* tmpPointer = &size.x;

            for(int j = 0; j < input[i].size(); j++) {
                if(input[i][j] == ',') {
                    tmpPointer == &size.x ? tmpPointer = &size.y : tmpPointer = &position.y;
                } else if(input[i][j] >= '0' && input[i][j] <= '9') {
                    lastCoordGrabbed == 0 || lastCoordGrabbed == 1 ? *(float*)tmpPointer *= float(10), *(float*)tmpPointer += float(input[i][j] - '0'):0;
                    lastCoordGrabbed >= 2 || lastCoordGrabbed <= 4  ? *(int*)tmpPointer *= 10, *(int*)tmpPointer += input[i][j] - '0':0;
                } else if(input[i][j] == ')' && lastCoordGrabbed == 0) {
                    lastCoordGrabbed++;
                    tmpPointer = &position.x;
                    continue;
                } else if(input[i][j] == ')' && lastCoordGrabbed == 1) {
                    lastCoordGrabbed++;
                    tmpPointer = &color;
                    continue;
                } else if(input[i][j] == ')' && lastCoordGrabbed == 2) {
                    lastCoordGrabbed++;
                    tmpPointer = &isCol;
                    continue;
                } else if(input[i][j] == ')' && lastCoordGrabbed == 3) {
                    lastCoordGrabbed++;
                    tmpPointer = &lvl;
                    continue;
                } else if(input[i][j] == ')' && lastCoordGrabbed == 4) {
                    lastCoordGrabbed++;
                    tmpPointer = &stage;
                    continue;
                } else if(input[i][j] == ')' && lastCoordGrabbed == 5) {
                    break;
                }



                //std::cout << input[i][j] << std::endl;
            }

            objs.push_back(LevelShape(size, position, sf::Color::White, 0, 1, 1));
        }
    }

    //std::cout << size.x << " " << size.y << " " << position.x << " " << position.y << std::endl;

    return objs;
}*/
