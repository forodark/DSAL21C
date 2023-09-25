#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Make a C++ Program that would prompt the user to enter 10 numbers
//Get the SUM and AVERAGE of the 10 numbers.
int main() {
    double sum = 0;
    for(int i = 0; i < 10; i++)
        sum += getDouble("Enter a number [" + to_string(i+1) + "/10]: ");
    double average = sum/10;
    cout << color(GREEN, "Sum: ") << sum << endl;
    cout << color(GREEN, "Average: ") << average << endl;
}