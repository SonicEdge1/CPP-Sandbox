// A simple program to demonstrate callback 
#include<iostream> 
#include<vector>
#include<cmath>
  
using void_f_ptr = void(*)();
using int_f_int_int_ptr =int (*)(int, int);

void A() 
{ 
    std::cout << "I am function A\n"; 
} 

void Aplus() 
{ 
    std::cout << "I am function Aplus\n"; 
}

// callback function 
void B(void (*pName)()) 
{ 
    (*pName) (); // callback to A 
} 
  
// callback function 
void C(void_f_ptr p) 
{ 
    p(); // callback to A 
}

int multiplyByX(int multiplicand, int multiplier){
    return multiplicand * multiplier;
}

int addTwoNums(int numOne, int numTwo){
    return numOne + numTwo;
}

int raiseToPower(int base, int exponent){
    return pow(base, exponent);
}

int subtractFromX(int x, int subtrahend){
    return x - subtrahend;
}

// callback function 
int changeTheseNumbers(int x, int y, int_f_int_int_ptr fPtr)
{ 
    return fPtr(x, y) ; // callback to A 
} 

int main() 
{ 
    std::vector<int> intVector {1, 2, 3, 5, 8, 13, 21, 34, 55};
    // calling function B & C and passing 
    // address of the function A & Aplus as argument
    // there are four different ways (syntaxes) that can be used to call the callback functions 
    void (*ptr)() = &A; 
    B(ptr);
    void_f_ptr fap = &Aplus;  
    C(fap);
    B(A);
    C(&Aplus);

    int i = 3;
 
    std::cout << "\nOriginal numbers: \n";
    for(int num : intVector) {
        std::cout << num << " ";
    }
    std::cout << "multiply by " << i << "\n";
    for(int num : intVector) {
        std::cout << changeTheseNumbers(num, i, multiplyByX) << " ";
    }
    std::cout << "\n\n";
    for(int num : intVector) {
        std::cout << num << " ";
    }
    std::cout << "adding " << i << "\n";
        for(int num : intVector) {
        std::cout << changeTheseNumbers(num, i, addTwoNums) << " ";
    }
    std::cout << "\n\n";
    for(int num : intVector) {
        std::cout << num << " ";
    }    
    std::cout << "raising to power of " << i << "\n";
        for(int num : intVector) {
        std::cout << changeTheseNumbers(num, i, raiseToPower) << " ";
    }
        std::cout << "\n\n";
    for(int num : intVector) {
        std::cout << num << " ";
    }
    std::cout << "subtracting " << i << "\n";
        for(int num : intVector) {
        std::cout << changeTheseNumbers(num, i, subtractFromX) << " ";
    }
    std::cout << "\n";



   return 0; 
} 