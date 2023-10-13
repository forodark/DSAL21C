#include "glenlib.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace gl;

#define SIZE 5

//WAC++P that will prompt the user to 5 numbers (Base) and another 5 numbers (Exponent) in an Array named MyNums. The program should be able to compute and display the computed value of each number i.e. Base raised to Exponent, in a table format as shown below.

struct Number {
    int base;
    int exponent;
    int computed;
};
       
int main() {
    while(true) {
        Number MyNums[SIZE];

        for (int i = 0; i < SIZE; i++) {
            MyNums[i].base = getInt("[" + to_string(i) + "] Enter base: ");
            MyNums[i].exponent = getInt("[" + to_string(i) + "] Enter exponent: ");
            MyNums[i].computed = pow(MyNums[i].base, MyNums[i].exponent);
        }

        table numbers[] = {
            COLUMN("Base", MyNums, base, "15d", Number),
            COLUMN("Exponent", MyNums, exponent, "15d", Number),
            COLUMN("Computed Value", MyNums, computed, "20d", Number),
            END_TABLE
        }; printTableFull("MyNums Computed Numbers", numbers);
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}