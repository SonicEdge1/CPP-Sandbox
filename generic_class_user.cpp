#include "generic_class.hpp"
#include <string>
#include "generic_function_template.hpp"

int main() {
    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    OrdPair<int> intPair(fourth, second);
    intPair.Print();
    
    OrdPair<int> intPair2(first, third);
    intPair2.Print();

    OrdPair<float> floatPair(1.34, 2.95);
    floatPair.Print();

    OrdPair<char> charPair('+', '#');
    charPair.Print();

    OrdPair<bool> boolPair(false, true);
    boolPair.Print();

    OrdPair<std::string> strPair("bye", "hi");
    strPair.Print();
    std::cout << strPair.Second();
    std::cout << strPair.First();
    std::cout << "\n";

    


// use of function template
    std::cout << "thrice of four: " << thrice<int>(fourth) << "\n";
    std::cout << "thrice of 3.14: " << thrice<float>(3.14) << "\n";
    std::cout << "thrice of \'a\': " << thrice<char>('a') << "\n";
    std::cout << "thrice of \'a\': " << thrice<double>(3.141579) << "\n";
    std::cout << "thrice of true: " << thrice<bool>(true) << "\n";
    std::cout << "thrice of false: " << thrice<bool>(false) << "\n";


} //end of main