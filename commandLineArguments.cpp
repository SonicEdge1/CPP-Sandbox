#include <iostream>

int main(int argc, char** argv){
    std::cout << "You entered in " << argc << " arguments.\n";
    
    for(int i = 0; i < argc; i++){
        std::cout << i + 1 << ":  " << argv[i] << "\n";
    }
    
    
    return 0;
}

// calling the program using:
// these are my args count them
// returns a list of 7 arguments

// calling the program using:
// "these are my args" "count them"
// returns a list of 3 arguments