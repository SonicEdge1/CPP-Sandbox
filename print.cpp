#include <iostream>
#include <string>

int main() {
int two = 2;
std::cout << "\u2663 \u2667 \u2666 \u2662 \u2665 \u2661 \u2660 \u2664 \n";
std::string out = "";
out += "\u2663";
out += std::to_string(3);
std::cout << out << "\n";
return 0;
}