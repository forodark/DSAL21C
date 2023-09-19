#include "glenlib.hpp"

using namespace std;
using namespace gl;

void prog11();
void prog13();

int main() {
    menu main_menu[] = {
        {"Prog11: Get Month Name", prog11},
        {"Prog13: Compute Bonus", prog13},
        END_MENU
    };
    showMenu("Select a program to run", main_menu);
    return 0;
}


/*
Prog11.CS
Create a complete C++ program that will allow user to input numbers from 1-12 and display its equivalent month name.
*/
void prog11() {
    int index = getInt("Enter a number between 1-12: ", 1, 12);
    switch(index) {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
        default: cout << "Invalid";
    }   
}


/*
Prog13.CS
Create a complete C++ program will compute for the bonus of an employee. Consider the following conditions: 
If the employee’s monthly salary is less than 15,000 pesos, the bonus is 25% of the salary; for employees with 
salaries greater than or equal to 15,000 pesos, the bonus is 5,500 pesos. Print the name and the corresponding bonus for each employee.
*/
void prog13() {
    string name = getString("Enter Name: ");
    double salary = getDouble("Enter Salary: ");
    double bonus;

    if (salary < 15000) {bonus = salary * 0.25;}
    else {bonus = 5500;}

    printLine();
    cout << "Name: " << name << endl
    << "Bonus: " << bonus << endl;
}
