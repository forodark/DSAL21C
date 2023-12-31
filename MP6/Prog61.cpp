
#include <iostream>
#include "glenlib.hpp"
using namespace std;
using namespace gl;

const int STACK_SIZE = 10;

// int stack[STACK_SIZE];
// int top = -1;

int stack[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int top = STACK_SIZE - 1;

void push() {
    if (top+1 >= STACK_SIZE) {
        invalid("Error: Stack overflow");
        menu_return = 1; return;
    }
    top++;
    stack[top] = getInt("Enter a value to push: ");
    printColor(GREEN, "Successfully pushed value to stack\n");
}

void pop() {
    if (top == -1) {
        invalid("Error: Stack is empty");
        menu_return = 1; return;
    }
    int count = getInt("Enter number of values to pop: ", 1, STACK_SIZE);

    if (top - count + 1 < 0) {
        invalid("Error: Stack underflow. There are only " + to_string(top+1) + " value/s on the stack");
        menu_return = 1; return;
    }

    for (int i = 0; i < count; i++) {
        stack[top--] = 0;
    }

    printColor(GREEN, concat("Successfully popped ", count, " value/s from stack\n"));
}

void peek() {
    if (top == -1) {
        invalid("Error: Stack is empty");
        menu_return = 1; return;
    }
    cout << "TOS -> " << stack[top] << endl;
}

void display() {
    if (top == -1) {
        invalid("Error: Stack is empty");
        menu_return = 1; return;
    }
    cout << "TOS ->";
    for (int i = top; i >= 0; i--) {
        cout << "\t" << stack[i] << endl;
    }
}

int main() {
    menu stack_menu[] = {
        {"Push", push},
        {"Pop", pop},
        {"Peek", peek},
        {"Display", display},
        END_MENU
    };
    do {
        menuSettings(0, 1, 1);
        showMenu("Stack Operations", stack_menu);
    } while(getBool("Do you want to try again? (y/n): ", 'n', 'y') == 1);
    exitProgram();
    return 0;
}