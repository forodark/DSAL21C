#include "glenlib.hpp"
#include <iostream>

using namespace std;
using namespace gl;

#define SIZE 10

//Using Arrays, create a complete C++ program that will accept 10 of your classmates’ 
//names and their last semester's GWA. The program should sort the list based on the highest GWA.

struct Student {
    string name;
    double gwa;
};

void insertionSort(Student arr[]) {
    for (int i = 1; i < SIZE; i++) {
        Student key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].gwa > key.gwa) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    while(true) {
        Student students[SIZE];

        for (int i = 0; i < SIZE; i++) {
            students[i].name = getString("[" + to_string(i) + "] Enter student name: ");
            while(true) { // additional validation to prevent GWA from being between 3.00 and 5.00
                students[i].gwa = getDouble("[" + to_string(i) + "] Enter student GWA: ", 1.00, 5.00);
                if (students[i].gwa > 3.00 && students[i].gwa < 5.00) {
                    invalid("Invalid GWA. GWA cannot be between 3.00 and 5.00.\n");
                    continue;
                }
                break;
            }
        }

        insertionSort(students); 

        table record[] = {
            COLUMN("Name", students, name, "20s", Student),
            COLUMN("GWA", students, gwa, "7.2lf", Student),
            END_TABLE
        }; printTableFull("Students by GWA", record);
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}