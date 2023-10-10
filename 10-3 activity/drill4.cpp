#include "glenlib.hpp"
#include <cctype>

using namespace std;
using namespace gl;

//
int main() {
    char myWord[32] = "";
    bool is_palindrome = true;
    println("Enter a word:");
    gets(myWord);

    for (int i = 0, j = strlen(myWord) - 1; i < strlen(myWord)/2; i++, j--) {
        if (tolower(myWord[i]) != tolower(myWord[j])) {
            is_palindrome = false;
            break;
        }
    }
    if (is_palindrome)
        println("This word is a palindrome.");
    else
        println("This word is not a palindrome.");

    return 0;
}