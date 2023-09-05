#include <iostream>
#include <functional>

struct MenuItem {
    const char* option_text;
    std::function<void()> function;
};

// Define a sentinel value to indicate the end of the menu
const MenuItem END_MENU = {nullptr, nullptr};

// Function to execute when option 1 is selected
void function1() {
    std::cout << "You selected Option 1. Function 1 is executed." << std::endl;
    // Add your code for Option 1 here
}

// Function to execute when option 2 is selected
void function2() {
    std::cout << "You selected Option 2. Function 2 is executed." << std::endl;
    // Add your code for Option 2 here
}

// Create the menu using the custom struct
MenuItem menu[] = {
    {"Option 1", function1},
    {"Option 2", function2},
    END_MENU // Use END_MENU to indicate the end of the menu
};

int main() {
    // Display the menu
    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        int i = 0;
        while (menu[i].option_text != nullptr) {
            std::cout << "[" << i + 1 << "] " << menu[i].option_text << std::endl;
            i++;
        }
        std::cout << "Enter your choice (0 to exit): ";
        std::cin >> choice;

        if (choice == 0 || choice > i) {
            break;
        }

        // Execute the selected function
        menu[choice - 1].function();
    }

    return 0;
}
