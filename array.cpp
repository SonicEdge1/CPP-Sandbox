#include <iostream>
#include <vector>

void modArrayPassCopy(std::vector<int> vect){
    std::cout << "copy address: " << &vect << "\n";
    std::cout << "original vals NOT changed\n";
    int size = vect.size();
    vect[0] *= 2;
    vect[(size - 1) / 2] *= 2;
    vect[size - 1] *= 2;
}

void modArrayPassReference(std::vector<int> &vect){
    std::cout << "reff address: " << &vect << "\n";
    std::cout << "original vals ARE changed\n";
    int size = vect.size();
    vect[0] *= 2;
    vect[(size - 1) / 2] *= 2;
    vect[size - 1] *= 2;
}

int main() {

std::vector<int> intVector = {1,2,3,5,8,13};
std::cout << "orig address: " << &intVector << "\n";

for(auto i : intVector) {
    std::cout << i << " ";
}
std::cout << "\n";

modArrayPassCopy(intVector);

for(auto i : intVector) {
    std::cout << i << " ";
}
std::cout << "\n";

modArrayPassReference(intVector);

for(auto i : intVector) {
    std::cout << i << " ";
}
std::cout << "\n";
}