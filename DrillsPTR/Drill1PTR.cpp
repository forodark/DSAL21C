
#include <iostream>

using namespace std;

//Write a C++ program which does the following: a. Declares an integer variable and a pointer variable 
//which points to an integer. b. Point the pointer variable to the address of the integer variable. c. 
//Display the value of the integer variable, its address, the value of the pointer variable and its address.
       
int main() {
    int i = 5;
    int* iptr;

    iptr = &i;

    cout << "i = " << i << endl
         << "&i = " << &i << endl
         << "iptr = " << iptr << endl
         << "&iptr = " << &iptr << endl;

    return 0;
}