/*
Prog13.CS
Create a complete C++ program will compute for the bonus of an employee. Consider the following conditions: 
If the employee’s monthly salary is less than 15,000 pesos, the bonus is 25% of the salary; for employees with 
salaries greater than or equal to 15,000 pesos, the bonus is 5,500 pesos. Print the name and the corresponding bonus for each employee.
*/

#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

int main() {
    string name = getString("Enter Name: ");
    double salary = getDouble("Enter Salary: ");
    double bonus;

    if (salary < 15000) {bonus = salary * 0.25;}
    else {bonus = 5500;}

    printLine();
    cout << "Name: " << name << endl
    << "Bonus: " << bonus << endl;
    return 0;
}
