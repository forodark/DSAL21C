/*
Prog11.CS
Create a complete C++ program that will allow user to input numbers from 1-12 and display its equivalent month name.
*/
#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

int main() {
    int index = getInt("Enter a number between 1-12: ", 1, 12);
    switch(index) {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
        default: cout << "Invalid";
    }  
    return 0;
}
