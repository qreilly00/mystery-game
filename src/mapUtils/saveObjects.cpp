#include "../MapUtils.hpp"

void MapUtils::saveObjects(std::vector<LevelShape> objects) {
    std::ofstream ofs;

    int objectCounter = 0;
    int levelCounter = 1;

    //std::string tmp = "../map-" + std::to_string(x.getLevel()) + "-objects";

    std::vector<std::vector<std::string> > original; //= ut.getFileLines(tmp);
    std::vector<std::vector<std::string> > output;

    while(objectCounter != objects.size()) {
        std::vector<std::string> tmp;
        //int tmpCounter = objectCounter;

        for(auto x : objects) {
            if(levelCounter == x.getLevel()) {
                //tmpCounter++;
                objectCounter++;

                std::stringstream ss;
                ss << "(" << x.getShape().getSize().x << "," << x.getShape().getSize().y << ")"
                    << "(" << x.getShape().getPosition().x << "," << x.getShape().getPosition().y << ")"
                    << "(" << x.getShape().getFillColor().toInteger() << ")"
                    << "(" << x.getIsCollidable() << ")"
                    << "(" << x.getLevel() << ")"
                    << "(" << x.getStage() << ")";
                    tmp.push_back(ss.str());
            }
        }
        /*if(tmp != objectCounter) {
            original.push_back(ut.getFileLines("../map-" + std::to_string(levelCounter) + "-objects"));
            output.push_back(tmp);
            objectCounter += tmp;
        }*/
        original.push_back(ut.getFileLines("../map-" + std::to_string(levelCounter) + "-objects"));
        output.push_back(tmp);
        levelCounter++;
    }



    for(int i = 0; i < output.size(); i++) {
        if(output[i].size() != 0) {
            ofs.open("../map-" + std::to_string(i + 1) + "-objects");

            for(int j = 0; j < original[i].size(); j++) {


                if(j != original[i].size() - 1) {
                    ofs << original[i][j] << std::endl;
                } else {
                    ofs << original[i][j];
                }


            }

            for(int j = 0; j < output[i].size(); j++) {


                ofs << output[i][j] << std::endl;


            }
            ofs.close();
        }
    }
}
