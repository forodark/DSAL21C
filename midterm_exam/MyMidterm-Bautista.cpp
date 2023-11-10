
#include <iostream>
#include "glenlib.hpp"
using namespace std;
using namespace gl;

//1. Declare a stack named MyStack which is of type Double and has a size of 12 (3pts)
const int STACK_SIZE = 12;
double MyStack[12] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
int top = STACK_SIZE - 1;

//3. Enable the user to enter his/her choice from the menu and perform and display the result (value and address) of the stack operations chosen (15pts)
void push() {
    dontWait(); 
    double input = getDouble("Enter a value to push: ");
    if (top+1 >= STACK_SIZE) {
        invalid("Error: Stack overflow", false);
        return;
    }
    top++;
    MyStack[top] = input;
    printColor(GREEN, "Successfully pushed value to stack\n");
    printColor(GREEN, concat("Value: ", MyStack[top], "\nAddress: ", &MyStack[top], "\n"));
}

void pop() {
    dontWait(); 
    if (top == -1) {
        invalid("Error: Stack underflow. Stack is empty", false);
        return;
    }
    printColor(GREEN, concat("Successfully popped value at top of stack\n"));
    printColor(GREEN, concat("Value: ", MyStack[top], "\nAddress: ", &MyStack[top], "\n"));
    MyStack[top--] = 0;
}

void peek() {
    dontWait();
    if (top == -1) {
        invalid("Error: Stack is empty", false);
        return;
    }
    cout << "TOS -> " << MyStack[top] << endl;
    printColor(GREEN, concat("Value: ", MyStack[top], "\nAddress: ", &MyStack[top], "\n"));
}

//4. Display your full name, course, and section, when the exit option is chosen
void exitProg() {
    dontWait();
    printColor(RED, "Full Name: Glen Angelo Dayao Bautista\n");
    printColor(GREEN, "Course: Bachelor of Science in Computer Science\n");
    printColor(BLUE, "Section: C231\n");
}

int main() {
    //2. Display a Menu for stack operations (peek, push, pop, exit) (2pts)
    menu stack_menu[] = {
        {"Push", push},
        {"Pop", pop},
        {"Peek", peek},
        {"Exit", exitProg},
        END_MENU
    };
    do {
        menuSettings(0, 1, 1, 1, 1);
        showMenu("Stack Operations", stack_menu);
    } while(getBool("Do you want to try again? (y/n): ", 'n', 'y') == 1);
    //5. Allow the user to enter another choice so long as he/she answers Yes to a prompt (2pts)

    return 0;
}