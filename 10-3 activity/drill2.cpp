#include "glenlib.hpp"
#include <cctype>

using namespace std;
using namespace gl;

int main() {
    char myWord[16] = "";
    println("Enter a word:");
    gets(myWord);   
    for (int i = 0; i < strlen(myWord); i++) {
        if (isupper(myWord[i]))
            myWord[i] = tolower(myWord[i]);
        else
            myWord[i] = toupper(myWord[i]);
    }
    println(myWord);
    return 0;
}