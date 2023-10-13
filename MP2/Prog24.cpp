#include "glenlib.hpp"
#include <iostream>

using namespace std;
using namespace gl;

//Create a complete C++ program that will determine the Greatest Common Divisor 
//(GCD) of two inputted integers. Provide its equivalent IPO and flowchart.

int main() {
    while(true) {
        int a = getInt("Enter the first number: ");
        int b = getInt("Enter the second number: ");

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        println("The GCD is " + to_string(a));

        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }

    return 0;
}