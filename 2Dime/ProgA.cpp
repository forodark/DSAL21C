#include "glenlib.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace gl;

#define SIZE 10

//WAC++P that will prompt the user to enter 10 numbers in an Array named MyNums.
//The program should be able to compute and display the Squared, Cubed and Square Root (rounded off) value of each number which are to be stored also in the same array, in a table format as shown below.

struct Number {
    int number;
    int squared;
    int cubed;
    double square_root;
};
       
int main() {
    while(true) {
        Number MyNums[SIZE];

        for (int i = 0; i < SIZE; i++) {
            MyNums[i].number = getInt("[" + to_string(i) + "] Enter number: ");
            MyNums[i].squared = pow(MyNums[i].number, 2);
            MyNums[i].cubed = pow(MyNums[i].number, 3);
            MyNums[i].square_root = round(pow(MyNums[i].number, 1.0/2.0)*100)/100;
        }

        table numbers[] = {
            COLUMN("Number", MyNums, number, "15d", Number),
            COLUMN("Squared", MyNums, squared, "15d", Number),
            COLUMN("Cubed", MyNums, cubed, "15d", Number),
            COLUMN("Square Root", MyNums, square_root, "15.2lf", Number),
            END_TABLE
        }; printTableFull("MyNums Computed Numbers", numbers);
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}