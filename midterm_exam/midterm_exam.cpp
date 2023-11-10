
#include <iostream>
#include "glenlib.hpp"
using namespace std;
using namespace gl;

const int STACK_SIZE = 12;

double MyStack[12] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
int top = STACK_SIZE - 1;

void push() {
    if (top+1 >= STACK_SIZE) {
        invalid("Error: Stack overflow\n");
        menu_return = 1; return;
    }
    top++;
    MyStack[top] = getDouble("Enter a value to push: ");
    printColor(GREEN, "Successfully pushed value to stack\n");
    printColor(GREEN, concat("Value: ", MyStack[top], "\nAddress: ", &MyStack[top], "\n"));
}

void pop() {
    if (top == -1) {
        invalid("Error: Stack is empty\n");
        menu_return = 1; return;
    }
    int count = getInt("Enter number of values to pop: ", 1, STACK_SIZE);

    for (int i = 0; i < count; i++) {
        if (top == -1) {
            invalid("Error: Stack underflow");
            menu_return = 1; return;
        }
        MyStack[top--] = 0;
        printColor(GREEN, concat("Value: ", MyStack[top], "\nAddress: ", &MyStack[top], "\n"));
    }

    printColor(GREEN, concat("Successfully popped ", count, " value/s from stack\n"));
}

void peek() {
    if (top == -1) {
        invalid("Error: Stack is empty\n");
        menu_return = 1; return;
    }
    cout << "TOS -> " << MyStack[top] << endl;
}

void display() {
    if (top == -1) {
        invalid("Error: Stack is empty\n");
        menu_return = 1; return;
    }
    cout << "TOS ->";
    for (int i = top; i >= 0; i--) {
        cout << "\t" << MyStack[i] << endl;
    }
}

void exitProg() {
    dontWait();
    printColor(RED, "Full Name: Glen Angelo Dayao Bautista\n");
    printColor(GREEN, "Course: Bachelor of Science in Computer Science\n");
    printColor(BLUE, "Section: C231\n");
}

int main() {
    menu stack_menu[] = {
        {"Push", push},
        {"Pop", pop},
        {"Peek", peek},
        {"Display", display},
        {"Exit", exitProg},
        END_MENU
    };
    do {
        menuSettings(0, 1, 1);
        showMenu("Stack Operations", stack_menu);
    } while(getBool("Do you want to try again? (y/n): ", 'n', 'y') == 1);
    exitProgram();
    return 0;
}