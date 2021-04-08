#include <iostream>
#include <ctime>
#include <string>


class TooLowError{
public:    
    TooLowError(float amount) {
        std::cout << amount << " too low!\n";
    }
};
class TooHighError{
public:    
    TooHighError(float amount) {
        std::cout << amount << " is too High!!\n";
    }
};

class Salary {
public:
    Salary(){}
    Salary(float initSalary){
        if(initSalary > maxAllowedSalary) {
            throw TooHighError(initSalary);
        } else if (initSalary < minAllowedSalary) {
            throw TooLowError(initSalary);
        }
        yearlySalary = initSalary;
    }
    float getYearlySalary() const {
        return yearlySalary;
    };
    float getHourlySalary() const {
        return yearlySalary / weeksInYear / hoursInWeek;
    };
    void addRaiseToSalary(float raise) {
        if(raise == otherAllowedRaise){
            std::cout << "\nHow is this possible? The top private const variable changes every input! otherAllowedRaise = " << otherAllowedRaise << "\n";
        }
        if(raise < minAllowedRaise) {
            throw TooLowError(raise);
        } else if(raise > maxAllowedRaise) {
            throw TooHighError(raise);
        }
        yearlySalary += raise;
        lastRaise = time(0);
    };
    void decreaseSalary(float decrease) {
        if((yearlySalary - decrease) < minAllowedSalary) {
            throw TooHighError(decrease);
        }
        yearlySalary -= decrease;
        lastRaise = time(0);
    };
    const char* getDateOfLastRaise() const {
        if(lastRaise <= 0){
            const char* e = "NEVER";
            return e;
        }
        return ctime(&lastRaise);
    }
private:
    const float otherAllowedRaise = 2000;
    const float minAllowedRaise = 2080;
    const float maxAllowedRaise = 10000;
    const int weeksInYear = 52;
    const int hoursInWeek = 40;
    const float maxAllowedSalary = 100000;
    const float minAllowedSalary = 20000;
    float yearlySalary;
    time_t lastRaise;
};

#include <iomanip> //for setprecision()

int main() {
    float salary;
    float raiseIn;
    std::cout << std::fixed << std::showpoint << std::setprecision(2); //formatting future float output
    Salary *bobsSalary;
    bool validSalary = false;
    while(!validSalary) {
        try {
            std::cout << "Enter a new salary: ";
            std::cin >> salary;
            Salary a(salary);
            bobsSalary = &a;
            validSalary = true;
        }
        catch (TooHighError error) {}
        catch (TooLowError error) {}
    }
    std::cout << "bob's current salary is: $" << bobsSalary->getYearlySalary() << " = $" << bobsSalary->getHourlySalary() << " per hour.\n";
    std::cout << "bob's last raise was on : " << bobsSalary->getDateOfLastRaise() << "\n";
    bool validRaise = false;
    while(!validRaise) {
        try {
            std::cout << "give bob a raise of: ";
            std::cin >> raiseIn;
            bobsSalary->addRaiseToSalary(raiseIn);
            validRaise = true;
        }
        catch (TooHighError error) {}
        catch (TooLowError error) {}
    }
    std::cout << "bob's new salary is: $" << bobsSalary->getYearlySalary() << " = $" << bobsSalary->getHourlySalary() << "per hour.\n";
    std::cout << "bob's last raise was on : " << bobsSalary->getDateOfLastRaise() << "\n";
    return 0;
}