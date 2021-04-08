#include <iostream>




int main(){
    std::string message = "Hello, lets see if this works!";

    std::cout << message << "\n";

    //lets print is out in reverse
    for(int i = message.size() - 1; i >=0; i--){
        std::cout << message[i];
    }


}

