//program to gather info and determine bmi
#include <iostream>
#include <iomanip>
#include <limits>
#include <istream>

using namespace std;

void printBMIandIntrepretation(float ImperialBMI);
float getWeightOrHeight(string metric, int floor, int ceiling);
float computeBMI(float weight, float height);

int main() {

    const int HEIGHT_HIGH = 108;
    const int WEIGHT_HIGH = 1500;
    const int WEIGHT_HEIGHT_LOW = 0;

    float weight = getWeightOrHeight("weight", WEIGHT_HEIGHT_LOW, WEIGHT_HIGH);
    float height = getWeightOrHeight("height", WEIGHT_HEIGHT_LOW, HEIGHT_HIGH);

    cout << "\n" << "Your entered weight: " << weight << "  " << "Your entered height: " << height << endl;
    
    float imperialBMI = computeBMI(weight, height);
        
    printBMIandIntrepretation(imperialBMI);

    return 0;
}

float getWeightOrHeight(string metric, int floor, int ceiling) {
    float measurement = 0;
    while(measurement <= floor || measurement > ceiling){
        cout << "Please enter your " << metric;
        if(metric == "weight") {
            cout << " in pounds: ";
        } else {
            cout << " in inches: "; 
        }
        cin >> measurement;
        if (measurement <= floor || measurement > ceiling){
            cout << "Invalid entry: Weight must be above " << floor << " and below " << ceiling << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    return measurement;
}

float computeBMI(float weight, float height) {
    const int IMP_CONSTANT = 703;
    IMP_CONSTANT * weight / (height * height);
}

void printBMIandIntrepretation(float imperialBMI) {
    const int BMI_UNDERWEIGHT = 20;
    const int BMI_NORMAL = 25;
    const int BMI_OVERWEIGHT = 30;

    cout << fixed << showpoint << setprecision(2);
    cout << "Your Imperial BMI is: " << imperialBMI << "\n";
    
    cout << "\nInterpretation & Instructions:\n";
    if(imperialBMI <= BMI_UNDERWEIGHT) {
        cout << "Underweight: Have a milk shake.\n";
    } else if(imperialBMI <= BMI_NORMAL) {
        cout << "Normal: Have a glass of milk\n";
    } else if(imperialBMI <= BMI_OVERWEIGHT) {
        cout << "Overweight: Have a glass of iced tea\n";
    } else {
        cout << "Obese: See your doctor\n";
    } 
}