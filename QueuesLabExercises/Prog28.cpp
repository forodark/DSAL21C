// Write a C++ program that will declare a QUEUE named MyQueue. Enable the
// user to SERVE an integer from the queue.


#include <iostream>
#include "glenlib.hpp"
using namespace std;
using namespace gl;

const int QUEUE_SIZE = 5;

class Queue {
    public:
        int queue[QUEUE_SIZE] = {1,2,3,4,5};
        int head = 0; //yoink
        int tail = QUEUE_SIZE-1; //dagdag

        boolean serve() {
            if (tail == -1) {
                printColor(RED, "Error: Queue Underflow\n");
                return false;
            }
            if (tail == 0) {
                head = -1;
            }
            tail--;
            int temp = queue[0];

            for(int i = 0; i <= tail; i++) {
                queue[i] = queue[i + 1];
            }

            printColor(GREEN, concat("Successfully served ", temp, " from queue\n"));
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

void serve() {
    int count = getInt("How many values do you want to serve?: ");
    for(int i = 0; i < count; i++) {
        if(!MyQueue.serve()) {
            break;
        }
        MyQueue.display();
    }
}


int main() {

    do {
        serve();
    } while (getBool("Do you want to try again? (y/n): ", 'n', 'y'));
    
    return 0;
}