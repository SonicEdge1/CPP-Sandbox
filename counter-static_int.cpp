#include <iostream>

void counting();

int main() {
    std::cout << "starting count\n";
    for(int i = 0; i < 10; i++){
        counting();
    }
    std::cout << "completed count\n";
    return 0;
}

void counting() {
    static int count = 0;  //the static int is not re-initialized each time the function is called.
    using std::cout;
    cout << "Counting function called " << ++count << " times\n";
}