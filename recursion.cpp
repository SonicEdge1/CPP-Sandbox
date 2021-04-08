#include <iostream>

long power(long base, int pow) {
    if(pow == 1) {
        return base;
    }
    return base * power(base, pow - 1);
}

long factorial(long fact) {
    if(fact == 1) {
        return fact;
    }
    return fact * factorial(fact -1);
}



int main(){
    int testArray[] = {1, 2, 3, 4, 5, 9, 11, 13, 17, 23};
    int base = 3;

    std::cout << "Starting Power Tests...\n";
    for(auto x : testArray) {
        std::cout << "test of raising "  << base << " to a power of " << x << " = " << power(base, x) << "\n";
    }

    std::cout << "Starting Factorial Tests...\n";
    for(auto x : testArray) {
        std::cout << "test of computing the factorial of " << x << " = " << factorial(x) << "\n";
    }
    return 0;

} //end of main