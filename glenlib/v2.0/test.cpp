#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;


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

menu test[] = {
    {"Option 1", function1},
    {"Option 2", function2},
    LINE,
    {"Test subtitle", SUBTITLE},
    {"Option 3", function2},
    {"Option 4", function2},
    END_MENU
};

menu page1[] = {
    {"Option 1", function1},
    LINE,
    {"Test subtitle", SUBTITLE},
    {"Option 2", function2},
    END_MENU
};

menu page2[] = {
    {"Option 3", function3},
    {"Option 4", function4},
    END_MENU
};

page_menu test2[] = {
    page1,
    page2,
    END_PAGE_MENU
};


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
    {10, "Jill", 19.19f, 20.20, 'l', false},
    {11, "Jim", 21.21f, 22.22, 'm', true},
    {12, "Joe", 23.23f, 24.24, 'n', false}
};

table TEST[] = {
    COL("ID", people, id, "9d"),
    COL("Name", people, name, "12s"),
    COL("Float", people, floatval, "12f"),
    COL("Double", people, doubleval, "12lf"),
    COL("Char", people, charval, "12c"),
    COL("Bool", people, boolval, "12b"),
    END_TABLE
};

int main() {
    for(int i = 0; i < 12; i++) {
        cout << random(1.0, 10.0, 1) << endl;
    }
}
