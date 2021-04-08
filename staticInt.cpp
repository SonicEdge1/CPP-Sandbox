#include <iostream>

int increment(int i);

int main(){
    std::cout << "Starting to increment a static int from 0\n";
    std::cout << "incrementing 2x\n";
    std::cout << increment(2) << "\n";
    std::cout << "incrementing 5x\n";
    std::cout << increment(5) << "\n";
    std::cout << "incrementing 10x\n";
    std::cout << increment(10) << "\n";
    std::cout << "Done!\n";
}

int increment(int i) {
    static int increment = 0; //the static int will hold its value in this function in between calls
    while(i > 0) {
        increment++;
        i--;
    }
    return increment;
}