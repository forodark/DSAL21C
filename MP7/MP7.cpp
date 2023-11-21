// Create a complete C++ Program that will simulate the ENQUEUE, DEQUEUE,
// and PEEK Operations. Also, add a menu for displaying the state of your QUEUE.

#include <iostream>
#include "glenlib.hpp"
using namespace std;
using namespace gl;

const int QUEUE_SIZE = 5;

class Queue {
    public:
        int queue[QUEUE_SIZE];
        int head = -1; //yoink
        int tail = -1; //dagdag

        boolean enqueue(int value) {
            if (tail + 1 >= QUEUE_SIZE) {
                printColor(RED, "Error: Queue Overflow\n");
                return false;
            }
            if (head == -1) {
                head = 0;
            }
            tail++;
            queue[tail] = value;
            printColor(GREEN, concat("Successfully enqueued ", value, " to queue\n"));
            return true;
        }

        boolean dequeue() {
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

            printColor(GREEN, concat("Successfully dequeued ", temp, " from queue\n"));
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

        void peek() {
            if (head == -1) {
                printColor(RED, "Queue is empty\n");
                return;
            }
            cout << "Head -> " << queue[0] << endl;
        }

};

Queue MyQueue; // queue declaration

void enqueue() {
        int count = getInt("How many values do you want to enqueue?: ");
        for(int i = 0; i < count; i++) {
            int value = getInt("Enter value to enqueue: ");
            if(!MyQueue.enqueue(value)) {
                break;
            }
            MyQueue.display();
        }
}

void dequeue() {
    int count = getInt("How many values do you want to dequeue?: ");
    for(int i = 0; i < count; i++) {
        if(!MyQueue.dequeue()) {
            break;
        }
        MyQueue.display();
    }
}

void peek() {
    MyQueue.peek();
}

void display() {
    MyQueue.display();
}


int main() {
    menu queue_menu[] {
        {"Enqueue", enqueue},
        {"Dequeue", dequeue},
        {"Peek", peek},
        {"Display", display},
        END_MENU
    };
    showMenu("Queue Operations", queue_menu);
    
    return 0;
}