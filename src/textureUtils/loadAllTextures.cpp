#include "../TextureUtils.hpp"

void TextureUtils::loadAllTextures() {
    std::vector<std::string> oldInput = ut.getFileLines("../textures/texture-names");
    std::vector<std::string> input;

    for(int i = 0; i < oldInput.size(); i++) {
        if(oldInput[i].size() != 0) {
            input.push_back(oldInput[i]);
            //std::cout << "test";
        }
    }

    //textures.resize(input.size());

    for(int i = 0; i < input.size(); i++) {
        textures.push_back(sf::Texture());
        //sf::Texture texture;
        if (!textures[i].loadFromFile("../textures/" + input[i])) {
            std::cout << "Error finding: " +  input[i] << std::endl;
        }
        std::cout << input[i] << std::endl;
        //textures[i] = texture;
    }
}

std::vector<int> TextureUtils::loadAllTextures(std::string fileName) {
    std::vector<std::string> oldInput = ut.getFileLines("../textures/" + fileName);
    std::vector<std::string> input;
    std::vector<int> tmpTextureIndexes;

    for(int i = 0; i < oldInput.size(); i++) {
        if(oldInput[i].size() != 0) {
            input.push_back(oldInput[i]);
            //std::cout << "test";
        }
    }

    //textures.resize(input.size());

    for(int i = textures.size(); i < input.size(); i++) {
        textures.push_back(sf::Texture());
        //sf::Texture texture;
        if (!textures[i].loadFromFile("../textures/" + input[i])) {
            std::cout << "Error finding: " +  input[i] << std::endl;
        }
        std::cout << input[i] << std::endl;
        tmpTextureIndexes.push_back(i);
        //textures[i] = texture;
    }

    return tmpTextureIndexes;
}
