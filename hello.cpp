// Your First C++ Program

#include <iostream>

void getAreaAndCircumference(const float pi, float& r, float& c, float& a);

int main() {
    const float PI = 3.14;
    float radius = 2.27;
    float circumference;
    float area;
    getAreaAndCircumference(PI, radius, circumference, area);

    std::cout << "Hello World!\n";
    std::cout << "Area: " << area << std::endl;
    std::cout << "Circ: " << circumference << std::endl;
    
    return 0;

}

void getAreaAndCircumference(const float pi, float& r, float& c, float& a) {
    c = 2 * pi * r;
    a = pi * r * r;
}


