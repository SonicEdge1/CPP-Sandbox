#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int height;
    int width;
    ifstream inFile;

    inFile.open("measures.dat");
    if(!inFile) {
        cout << "ERROR: Can't open the input file." <<endl;
        return 1;
    }
    inFile >> height >> width;
    cout << "for a height of " << height << "\n"
         << "and a width of " << width << "\n"
         << "the area is " << height * width << endl;
    return 0;
}
