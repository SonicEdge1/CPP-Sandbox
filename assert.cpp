//#define NDEBUG  // if this line is present asserts will be skipped, if not asserts will run.
#include <cassert>
#include <iostream>

int main() {
    int correctAssert = 1;
    int badAssert = 0;
    
    assert(correctAssert == 1);
    assert(badAssert == 1);  //is there a graceful way to handle failing an assert??

    std::cout << "Asserts Passed\n";

    return 0;
}