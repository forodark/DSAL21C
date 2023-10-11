#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Create a complete C++ program that will find the nth Fibonacci number. 
//Use the formulas in finding the odd and even Fibonacci number. Provide its equivalent IPO and flowchart.
int getFib(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return getFib(n - 1) + getFib(n - 2);
    }
}

int main() {
    while(true) {
        int n = getInt("Enter a value for n: ");
        int result = getFib(n);
        println("The " + getOrdinal(n) + " Fibonacci number is: " + to_string(result));
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }

    return 0;
}