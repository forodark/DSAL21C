#include "glenlib.hpp"
#include <cmath>   

using namespace std;
using namespace gl;

//Create a complete C++ program that will compute for the minimum number of moves based on 
//the inputted number of disks. Provide its equivalent IPO and flowchart. (Refer to "Towers of Hanoi" problem).
int main() {
    while(true) {
        int disks = getInt("Enter the number of disks: ");
        int min_moves = pow(2, disks) - 1;
        println("Minimum number of moves: " + to_string(min_moves));
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}