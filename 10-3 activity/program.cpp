
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

int main() {
    while(true) {
        char answer;
        cout << "Would you like to enter a character? (Y/N): ";
        cin >> answer;

        if (toupper(answer) != 'Y')
            break;
        char any;
        cout << "Enter any: ";
        cin >> any;
        if (isdigit(any))
            cout << "You entered a number.\n";
        else if (isalpha(any))
            cout << "You entered a letter.\n";
        else 
            cout << "You entered a non-letter or non-number character.\n";
    }
    return 0;
}