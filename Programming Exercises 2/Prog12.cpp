/*
Prog12.CS
Create a complete C++ program that will allow the user to input a symbol and display a 10x10 square using this symbol. Use while loop.
*/

#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

int main() {
    char symbol = getChar("Enter symbol: ");
    int i = 0;
    while(i<10) {
        int j = 0;
        while(j<10) {
            cout << symbol;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}