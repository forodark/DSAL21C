
#include <iostream>

using namespace std;

//Write a C++ program that will declare variables ival initialized to 25, y to 3256 and a pointer named 
//pint initialized to the address of ival. Display the values of ival, y, pint and the address of ival and y.
       
int main() {
    int ival = 25;
    int y = 3256;
    int* pint = &ival;

    cout << "ival = " << ival << endl
         << "y = " << y << endl
         << "pint = " << pint << endl
         << "&ival = " << &ival << endl
         << "&y = " << &y << endl;

    return 0;
}