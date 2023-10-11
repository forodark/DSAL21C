#include "glenlib.hpp"
#include <cctype>

using namespace std;
using namespace gl;

int main() {
    char Any[10];
    int num_count = 0;
    int letter_count = 0;
    int punc_count = 0;
    println("Enter 10 characters: ");
    for (int i = 0; i < 10; i++) {
        Any[i] = getChar("");
        if (isdigit(Any[i]))
            num_count++;
        else if (isalpha(Any[i]))
            letter_count++;
        else if (ispunct(Any[i]))
            punc_count++;
    }
    println("No. of numbers: " + to_string(num_count));
    println("No. of letters: " + to_string(letter_count));
    println("No. of punctuations: " + to_string(punc_count));
    return 0;
}