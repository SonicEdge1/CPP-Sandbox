#include <iostream>
#include <string>
#include <typeinfo>

std::string getCmdArg(char** begin, int countCopy);

// The problem with c++ switch statements!!
// The compiler builds them as a very fast look-up table at compile time
// and it can't do that if there is a possibility that the values could change as the program runs.

int main(int argc, char** argv){
    std::cout << "argCount: " << argc << "\n";
   
    int countCopy = 1;
    while(countCopy < argc) {
        std::cout << "Argument " << countCopy << ": ";
        std::cout << getCmdArg(argv, countCopy) << "\n";
        countCopy++;
    }

    std::string arg2 = "";
    if(argc >= 2){
        arg2 = argv[2];
    }

    std::hash<std::string> str_hash;

    const std::string blank = "";
    std::string awesome = "awesome";
    std::cout << "hashes: " << str_hash(blank) << " " << str_hash(awesome) << "\n";

    // Run using <program_name.o> | c++filt -t to see the type id of the output
    std::cout << "hash type ID: " << typeid(str_hash("hello World")).name() << "\n";
    unsigned long awesomeHash = str_hash("awesome");
    unsigned long blankHash = str_hash("");
    unsigned long helloHash = str_hash("hello");
    unsigned long pre_known_hash = 8466468697076548456;

    //strings don't work in switch statements.  even a hash doesn't
    //
    switch(str_hash(arg2))
    {
        case 6142509188972423790  : std::cout << "you forgot to enter two args\n";
        break;
        case 8466468697076548456  : std::cout << "that was an awesome input\n";
        break;
        default                   : std::cout << "I didn't see an argument I expected\n";
    }

        int notAconstInt;
        notAconstInt = 12;
        switch(notAconstInt)
    {
        case 13  : std::cout << "your number is 13\n";
        break;
        case 12  : std::cout << "your number is 12\n";
        break;
        default  : std::cout << "I didn't see an argument I expected\n";
    }

}

std::string getCmdArg(char** begin, int countCopy)
{
    std::string arg = begin[countCopy];
    return arg;
}