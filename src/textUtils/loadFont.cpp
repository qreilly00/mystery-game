#include "../TextUtils.hpp"

void TextUtils::loadFont(std::string fontName) {
    if (!font.loadFromFile(fontName)) {
        std::cout << "Error loading font." << std::endl;
    }
}
