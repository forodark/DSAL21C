//Write a C++ program that will declare a QUEUE named MyQueue. Enable the
//user to APPEND an integer unto the queue

#include <iostream>
#include "glenlib.hpp"
using namespace std;
using namespace gl;

const int QUEUE_SIZE = 5;



class Queue {
    public:
        int queue[QUEUE_SIZE];
        int head = -1; //dagdag
        int tail = -1; //yoink

        boolean append(int value) {
            if (tail + 1 >= QUEUE_SIZE) {
                printColor(RED, "Error: Queue Overflow\n");
                return false;
            }
            if (head == -1) {
                head = 0;
            }
            tail++;
            queue[tail] = value;
            printColor(GREEN, concat("Successfully appended ", value, " to queue\n"));
            return true;
        }

        void display() {
            if (head == -1) {
                printColor(RED, "Queue is empty\n");
                return;
            }
            cout << "Head -> ";
            for (int i = head; i <= tail; i++) {
                cout << queue[i] << " ";
            }
            cout << "<- Tail" << endl;
        }

};

Queue MyQueue; // queue declaration

void append() {
    int count = getInt("How many values do you want to append?: ");
    for(int i = 0; i < count; i++) {
        int value = getInt("Enter value to append: ");
        if(!MyQueue.append(value)) {
            break;
        }
        MyQueue.display();
    }
}


int main() {
    do {
        append();
    } while (getBool("Do you want to try again? (y/n): ", 'n', 'y'));
    
    return 0;
}