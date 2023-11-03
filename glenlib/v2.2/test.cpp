#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;


int main() {
    println("Hello World");
    print("Hello", "World", 1, 2);

    string test = concat("Hello", "test");
    print(test);

    return 0;
}
