#include "glenlib.hpp"
#include <cctype>

using namespace std;
using namespace gl;

int main() {
    char myStmt[64] = "";
    int word_count = 0;
    bool found_word = false;
    println("Enter a sentence:");
    gets(myStmt);
    
    for (int i = 0; i < strlen(myStmt); i++) {
        if (isspace(myStmt[i])) {
            found_word = false;
        } else if (!found_word) {
            found_word = true;
            word_count++;
        }
    }

    println("No. of word(s) in the sentence: " + to_string(word_count));
    return 0;
}