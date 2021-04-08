#include <string>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile("../config/hbl_learjet.cfg");

    std::string line;

    while (std::getline(infile, line))
    {
        std::cout << line << std::endl;
    }
}
