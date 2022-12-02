#include "../TextureUtils.hpp"

void TextureUtils::loadAllTextures() {
    std::vector<std::string> oldInput = ut.readFileLines("../textures/texture-names");
    std::vector<std::string> input;

    for(int i = 0; i < oldInput.size(); i++) {
        if(oldInput[i].size() != 0) {
            input.push_back(oldInput[i]);
        }
    }

    for(int i = 0; i < input.size(); i++) {
        textures.push_back(sf::Texture());

        if (!textures[i].loadFromFile("../textures/" + input[i])) {
            std::cout << "Error finding: " +  input[i] << std::endl;
        }
        std::cout << input[i] << std::endl;
    }

    textureNames = input;
}

std::vector<int> TextureUtils::loadAllTextures(std::string fileName) {
    std::vector<std::string> oldInput = ut.readFileLines("../textures/" + fileName);
    std::vector<std::string> input;
    std::vector<int> tmpTextureIndexes;

    for(int i = 0; i < oldInput.size(); i++) {
        if(oldInput[i].size() != 0) {
            input.push_back(oldInput[i]);
        }
    }

    for(int i = textures.size(); i < input.size(); i++) {
        textures.push_back(sf::Texture());

        if (!textures[i].loadFromFile("../textures/" + input[i])) {
            std::cout << "Error finding: " +  input[i] << std::endl;
        }
        std::cout << input[i] << std::endl;
        tmpTextureIndexes.push_back(i);
    }

    textureNames = input;

    return tmpTextureIndexes;
}
