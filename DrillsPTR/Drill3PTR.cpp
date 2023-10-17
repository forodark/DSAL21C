#include "glenlib.hpp"
#include <iostream>

using namespace std;
using namespace gl;

//Write a C++ program that will declare an array named myArray of size 10. Prompt the user to input 10 integers
//to the array using a loop. Display the values of myArray and their addresses using a pointer named myPtr.
       
#define SIZE 10
int main() {
    int myArray[SIZE];

    for(int i = 0; i < SIZE; i++){
        myArray[i] = getInt("[" + to_string(i) + "] Enter a number: ");
    }

    for(int i = 0; i < SIZE; i++){
        int* myPtr = &myArray[i];
        cout << "myArray[" << i << "] = " << myArray[i] << endl
             << "myPtr = " << myPtr << endl;
    }

    return 0;
}