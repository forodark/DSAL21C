#include <iostream>
#include "glencryppt.hpp"

using namespace std;
using namespace gc;


int main() {
    // // Green and bold
    // std::cout << "\033[1;32mHello, green and bold world!\033[0m\n";
    // // Red and underlined
    // std::cout << "\033[4;31mThis text is red and underlined.\033[0m\n";
    // // Blue text on yellow background
    // std::cout << "\033[1;34;43mBlue text on a yellow background.\033[0m\n";

    printColor(RED, "Invalid choice.\n");
    return 0; 
}
