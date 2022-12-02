#include "../BasicUtils.hpp"

std::vector<std::string> BasicUtils::readFileLines(std::string fileName) {
    std::vector<std::string> result;
    std::string tmp;

    std::ifstream myfile (fileName);

    if (myfile.is_open()) {
        while(myfile.eof() != 1) {
            getline(myfile, tmp);
            result.push_back(tmp);
        }

        myfile.close();
    }
    else {
        std::cout << "File Unavailable" << std::endl;
    }

    myfile.close();

    return result;
}
