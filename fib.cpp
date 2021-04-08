/*3. In mathematics, the Fibonacci numbers are the series of numbers that exhibit
 the following pattern:0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …
 In mathematical notation the sequence Fn of Fibonacci numbers is defined
 by the following recurrence relation:Fn = Fn−1 + Fn−2
 With the initial values of F0 = 0 and F1 = 1.
 Thus, the next number in the series is the sum of the previous two numbers.
 Write a program that asks the user for a positive integer N and generates the Nth Fibonacci number.
 Your main function should handle user input and pass that data to a function called Fib
 that takes an integer value N as input and a reference parameter that is assigned the Nth Fibonacci number.*/
 
#include <iostream>

using namespace std;

void fib(int n, unsigned long& fibNumber);

 int main() {

    unsigned long fibNumber = 0;
    int n;
    
    cout << "Enter an integer n for the Nth fib number: ";
    cin >> n;

    fib(n, fibNumber);
    cout << "The " << n << "th fibonacci number is : " << fibNumber << endl;
    return 0;
 }

 void fib(int n, unsigned long& fibNumber) {
     //fn = fn-1+fn-2
    int fZero = 0;
    int fOne = 1;
    if(n == 1) {
        fibNumber = 1;
    } else {
        for(int i = 1; i < n; i++) {
            fibNumber = fZero + fOne;
            fZero = fOne;
            fOne = fibNumber;
        }
    }


 }
