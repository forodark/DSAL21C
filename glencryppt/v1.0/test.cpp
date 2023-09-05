#include <iostream>
#include "glencryppt.hpp"

using namespace std;
using namespace gc;


void function1() {
    std::cout << "You selected Option 1. Function 1 is executed." << std::endl;
}

void function2() {
    std::cout << "You selected Option 2. Function 2 is executed." << std::endl;
}

void function3() {
    std::cout << "You selected Option 3. Function 3 is executed." << std::endl;
}

void function4() {
    std::cout << "You selected Option 4. Function 4 is executed." << std::endl;
}

// menu test[] = {
//     {"Option 1", function1},
//     {"Option 2", function2},
//     LINE,
//     {"Test subtitle", SUBTITLE},
//     {"Option 3", function2},
//     {"Option 4", function2},
//     END_MENU
// };

// menu page1[] = {
//     {"Option 1", function1},
//     LINE,
//     {"Test subtitle", SUBTITLE},
//     {"Option 2", function2},
//     END_MENU
// };

// menu page2[] = {
//     {"Option 3", function3},
//     {"Option 4", function4},
//     END_MENU
// };

// page_menu test2[] = {
//     page1,
//     page2,
//     END_PAGE_MENU
// };


typedef struct {
    int id;
    std::string name;
    float floatval;
    double doubleval;
    char charval;
    bool boolval;
} person;

person people[] = {
    {1, "John", 1.1f, 2.2, 'c', true},
    {2, "Jane", 3.3f, 4.4, 'd', false},
    {3, "Joe", 5.5f, 6.6, 'e', true},
    {4, "Jill", 7.7f, 8.8, 'f', false},
    {5, "Jim", 9.9f, 10.10, 'g', true},
    {6, "Joe", 11.11f, 12.12, 'h', false},
    {7, "Jill", 13.13f, 14.14, 'i', true},
    {8, "Jim", 15.15f, 16.16, 'j', false},
    {9, "Joe", 17.17f, 18.18, 'k', true},
    {10, "Jill", 19.19f, 20.20, 'l', false}
};

#define TCOL(HEADER, SOURCE, MEMBER, FORMAT) {HEADER, &SOURCE[0].MEMBER, sizeof(SOURCE)/sizeof(SOURCE[0]), sizeof(SOURCE[0]), FORMAT, offsetof(typeof(*(SOURCE)), MEMBER)}

table TEST[] = {
    TCOL("ID", people, id, "9d"),
    TCOL("Name", people, name, "12s"),
    TCOL("Float", people, floatval, "12f"),
    TCOL("Double", people, doubleval, "12lf"),
    TCOL("Char", people, charval, "12c"),
    TCOL("Bool", people, boolval, "12b"),
    END_TABLE
};

int main() {
    printTable("Title", TEST);

    // std::cout << formatString("asdfghj", 5);

    return 0;
}
