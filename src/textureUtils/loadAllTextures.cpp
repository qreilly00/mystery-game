#include "../TextureUtils.hpp"

void TextureUtils::loadAllTextures() {
    std::vector<std::string> input = ut.getFileLines("../textures/texture-names");

    if(input[input.size() - 1] == "") {
        input.pop_back();
        //std::cout << "test";
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
