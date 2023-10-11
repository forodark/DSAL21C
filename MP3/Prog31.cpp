#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Using Arrays, create a complete C++ program that will accept 10 of your classmates’ 
//names and their last semester's GWA. The program should sort the list based on the highest GWA.

struct Student {
    string name;
    double gwa;
};


void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key.gwa
        // to one position ahead of their current position
        while (j >= 0 && arr[j].gwa < key.gwa) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    while(true) {
        Student students[10];

        for (int i = 0; i < 10; i++) {
            students[i].name = getString("[" + to_string(i) + "] Enter student name: ");
            students[i].gwa = getDouble("[" + to_string(i) + "] Enter student GWA: ");
        }

        int size = sizeof(students) / sizeof(students[0]);
        insertionSort(students, size); 

        table record[] = {
            COL("Name", students, name, "20s"),
            COL("GWA", students, gwa, "7.2lf"),
            END_TABLE
        }; printTableFull("Students by GWA", record);
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}