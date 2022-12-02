#include "../MapUtils.hpp"

void MapUtils::saveObjects(std::vector<LevelShape> objects) {
    std::ofstream ofs;

    int objectCounter = 0;
    int levelCounter = 1;

    std::vector<std::vector<std::string> > original;
    std::vector<std::vector<std::string> > output;

    while(objectCounter < objects.size()) {
        std::vector<std::string> tmp;

        for(auto x : objects) {
            if(levelCounter == x.getLevel()) {
                objectCounter++;

                std::stringstream ss;
                ss << "(" << x.getShape().getSize().x << "," << x.getShape().getSize().y << ")"
                    << "(" << x.getShape().getPosition().x << "," << x.getShape().getPosition().y << ")"
                    << "(" << x.getShape().getFillColor().toInteger() << ")"
                    << "(" << x.getIsCollidable() << ")"
                    << "(" << x.getTextureIndex() << ")"
                    << "(" << x.getLevel() << ")"
                    << "(" << x.getStage() << ")"
                    << "(" << x.getIsForGround() << ")";
                    tmp.push_back(ss.str());
            }
        }

        original.push_back(ut.readFileLines("../maps/map-" + std::to_string(levelCounter) + "-objects"));
        output.push_back(tmp);
        levelCounter++;
    }



    for(int i = 0; i < output.size(); i++) {
        if(output[i].size() != 0) {
            ofs.open("../maps/map-" + std::to_string(i + 1) + "-objects");

            for(int j = 0; j < output[i].size(); j++) {
                ofs << output[i][j] << std::endl;
            }
            ofs.close();
        }
    }
}
