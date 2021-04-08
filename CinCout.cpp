#include <iostream>
#include <istream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << showpoint << setprecision(2); //formatting future float output
    float dollar = 1.99999;
    int quantity = 1;
    cout << "Quantity: " << quantity << " Price: " << dollar << "\n";
    int year;
    int month;
    int day;
    // cout << "Enter the month: ";
    // cin >> month;
    // cout << "Enter the day: ";
    // cin >> day;
    // cout << "Enter the year: ";
    // cin >> year;
    // cout << "\nYou entered: " << month << "/" << day << "/" << year << "\n";
    // cout << "Now enter the month, day, and year.\n";
    // cin >> month >> day >> year;
    // cout << "\nYou entered: " << month << "/" << day << "/" << year << endl;
    //don't know why yet, but only works at top of file...  maybe need to clear cin stream somehow?
    // http://www.cplusplus.com/reference/istream/istream/
    // cin.clear(); this doesn't work...only clears flags
    // cin.get(); //This also works.  Must be processing a newline character in the buffer or reaching EOF?
    // cin.putback('t'); //confirms that it reads from what is currently left in cin.
    // cin.ignore(); //This seems to work... extracts and discards characters //http://www.cplusplus.com/reference/istream/istream/ignore/
    // string strIn;
    // getline(cin, strIn);
    // cout << strIn;


    // std::string newString;
    // std::cout << "Copy cat\n";
    // while (cin >> newString && newString != "stop") {
    // std::cout << newString << "\n";
    // std::cin.ignore(10, '\n'); //ignores up to 10 characters (after the first token) or until '\n' , whichever comes first
    // }

    int limit = 3;
    //char name[limit];
    std::string name;
    while(name != "joe"){
        std::cout << "enter name: ";
        getline(std::cin, name, '\n');
        //std::cin.getline(name, 21, '\n');
        //std::cin.ignore(limit, '\n');
        std::cout << "Entered: " << name << '\n'; 
    }

    return 0;
}
