#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Create a complete C++ program that will display all the elements in Array3D [Table No., Row No. and Column No.). Use for loop.

#define TABLES 3
#define ROWS 3
#define COLUMNS 3

int main() {
    // while(true) {
    int array3D[TABLES][ROWS][COLUMNS] = {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}},

        {{10, 11, 12},
         {13, 14, 15},
         {16, 17, 18}},

        {{19, 20, 21},
         {22, 23, 24},
         {25, 26, 27}}
    };

    // display table no., row no. and column no.
    // for (int table = 0; table < 3; ++table) {
    //     for (int row = 0; row < ROWS; ++row) {
    //         for (int column = 0; column < COLUMNS; ++column) {
    //             std::cout << "Table " << table + 1 << ", Row " << row + 1 << ", Column " << column + 1
    //                       << " = " << array3D[table][row][column] << std::endl;
    //         }
    //     }
    // }

    //display per table
    for (int table = 0; table < 3; ++table) {
        for (int row = 0; row < ROWS; ++row) {
            for (int column = 0; column < COLUMNS; ++column) {
                std::cout << array3D[table][row][column] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    //     if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
    //         break;
    // }
    return 0;
}