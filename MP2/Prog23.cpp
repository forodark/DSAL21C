#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Create a complete C++ program that will simulate a slot machine 
//with 1 as the starting value and 5 as the highest value. Use the rand() math function.

int main() {
    while(true) {
        int slot[3];
        for(int i = 0; i < 3; i++) {
            slot[i] = rand() % 5 + 1;
            print(to_string(slot[i]) + " ");
        }
        nl();
        if (slot[0] == slot[1] && slot[1] == slot[2])
            println("Congratulations! You won the jackpot!");
        else
            println("Sorry! Better luck next time.");

        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }

    return 0;
}