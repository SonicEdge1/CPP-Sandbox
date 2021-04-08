#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream inData;
    ofstream outData;
    string fileName;
    string inputString;
    cout << "Enter the name of the file to read: ";
    cin >> fileName;
    inData.open(fileName.c_str());
    cout << "Enter the name of the file to write: ";
    cin >> fileName;
    outData.open(fileName.c_str());
    getline(inData, inputString);
    cout << "\n1: " << inputString;
    outData << inputString << "\n";
    getline(inData, inputString);
    cout << "\n2: " << inputString << "\n";
    outData << inputString << "\n";
    cin.ignore();
    cout << "Enter something to write to line 3 of the file: ";
    getline(cin, inputString);
    outData << inputString << "\n";
    cout << "Enter something to write to line 4 of the file: ";
    getline(cin, inputString);
    outData << inputString << endl; //without a new line character, subsequent writes will write to the same line.
    printf("filenameValue: %s and current value inputString %s", fileName.c_str(), inputString.c_str());
    return 0;
}