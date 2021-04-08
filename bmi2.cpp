//program to gather info and determine bmi
#include <iostream>
#include <iomanip>
#include <limits>
#include <istream>
// #include <string>

using namespace std;

int main() {

    const int BMI_UNDERWEIGHT = 20;
    const int BMI_NORMAL = 25;
    const int BMI_OVERWEIGHT = 30;
    const float LBS_TO_KG_FACTOR = 2.205;
    const float IN_TO_M_FACTOR = 39.37;
    const int HEIGHT_HIGH = 108;
    const int WEIGHT_HIGH = 1500;
    const int WEIGHT_HEIGHT_LOW = 0;
    const int IMP_CONSTANT = 703;
    float imperialBMI;
    float metricBMI;
    float weight = 0;
    float height = 0;
    string test;
    char firstChar;

    cout << "Would you like to check your BMI? :";
    cin >> firstChar;
    //alternate way to loop checking for valid input
    while(toupper(firstChar) == 'Y') {
        cout << "Please enter your weight in pounds: ";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        for(cin >> weight; weight <= WEIGHT_HEIGHT_LOW || weight > WEIGHT_HIGH; cin >> weight) {
            cout << "Invalid entry: Weight must be above " << WEIGHT_HEIGHT_LOW << " and below " << WEIGHT_HIGH << "\n";
            cout << "Please enter your weight in pounds: ";
            if(!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            // still don't know how to check for proper data type. A string input starts eternal loop.
        }
        
        cout << "please enter your height in inches: ";
        for(cin >> height; height <= WEIGHT_HEIGHT_LOW || height > HEIGHT_HIGH; cin >> height) {
            cout << "Invalid entry: Height must be above " << WEIGHT_HEIGHT_LOW << " and below " << HEIGHT_HIGH << "\n";
            cout << "please enter your height in inches: ";
            cin >> height;
            if(!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }

        cout << "\n" << "Your entered weight: " << weight << "  " << "Your entered height: " << height << endl;
        
        imperialBMI = IMP_CONSTANT * weight / (height * height);
        
        float weightInKg = weight / LBS_TO_KG_FACTOR;
        float heightInM = height / IN_TO_M_FACTOR;
        metricBMI = weightInKg / (heightInM * heightInM); 

        cout << fixed << showpoint << setprecision(2);
        cout << "Your Imperial BMI is: " << imperialBMI << "\n";
        cout << "Your Metric BMI is: " << metricBMI << "\n";
        
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
        cout << "\nWould you like to check your BMI? :";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> firstChar;
    }

    return 0;
}