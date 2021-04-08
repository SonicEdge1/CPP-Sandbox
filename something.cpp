#include <iostream>
#include <string>
using namespace std;

int main() {
    string wordOne = "Joe";
    string wordTwo = "Bell";
    int capture;
    // cin >> capture;
    string myString = "This is a"
        " string that spans two "  + wordOne + " " + wordTwo + " lines\n";
    char achar = 'a';
    char bchar = 'b';
    int binary = 0b11;
    int hex = 0x11;
    int octal = 01;
    float someFloat = 1.49;
    float anotherFloat = 1.50;
    int someInt = int(someFloat + 0.5); //easy way to round
    int anotherInt = int(anotherFloat + 0.5); //easy way to round
    cout << capture << "\n" << achar << bchar << "\n" << myString;
    cout << "binary: " << binary << "\n";
    cout << "hex: " << hex << "\n";
    cout << "octal: " << octal << "\n";
    cout << "someRoundedInt = " << someInt << "\n";
    cout << "AnotherRoundedInt = " << anotherInt << "\n";
}