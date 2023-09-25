#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Make a C++ Program that would prompt the user to enter 5 numbers
//Get the PRODUCT of the 5 numbers.
int main() {
    double product = 1;
    for(int i = 0; i < 5; i++) 
        product *= getDouble("Enter a number [" + to_string(i+1) + "/5]: ");
    cout << color(GREEN, "Product: ") << product << endl;
}