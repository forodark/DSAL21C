#include <iostream>
#include <string>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

void exercise1();
void exercise2();
void exercise3();

int main() {
    menu main_menu[] = {
        {"Grade Calculation", exercise1},
        {"Salary Calculation", exercise2},
        {"Sum, Product, and Average", exercise3},
        END_MENU
    };
    showMenu("Menu", main_menu);
    return 0;
}

/*WAC++P that will prompt the user to enter the Student's Name, Student Number, 
Course, Year, Section, Prelim Period Grade, Midterm Period Grade and Final Period Grade. 
Compute and display the Final Grade (Average of the 3 Grading Periods) then display all 
values entered and the computed Final Grade.*/
void exercise1() {
    printLine();
    printCentered(31, "Grade Calculation");
    cout << endl;
    printLine();

    string name = getString("Enter Name: ");
    string student_number = getString("Enter Student Number: ");
    string course = getString("Enter Course: ");
    int year_level = getInt("Enter Year Level: ", 1, 5);
    string section = getString("Enter Section: ");
    double prelim_grade = getDouble("Enter Prelim Period Grade: ", 0, 100);
    double midterm_grade = getDouble("Enter Midterm Period Grade: ", 0, 100);
    double final_grade = getDouble("Enter Final Period Grade: ", 0, 100);

    double average_grade = (prelim_grade + midterm_grade + final_grade) / 3;

    system("cls");
    printLine();
    printCentered(31, "Grade Report");
    cout << endl;
    printLine();

    cout 
    << "Name: " << name << endl
    << "Student Number: " << student_number << endl
    << "Course: " << course << endl
    << "Year Level: " << year_level << endl
    << "Section: " << section << endl
    << "Prelim Period Grade: " << prelim_grade << endl
    << "Midterm Period Grade: " << midterm_grade << endl
    << "Final Period Grade: " << final_grade << endl;
    printLine();
    cout << "Final Grade: " << fixed << setprecision(2) << average_grade << endl;
    printLine();
}

/*WAC++P that will prompt the user to enter Employee No. (ex. 123-4567A),
Employee Name (FN, MI and LN), Date Hired, Rate, No of Hours Worked. Compute
for the Gross Pay which No of hours worked multiplied by the rate,
Net Pay which is Gross Pay less 10% of the Gross Pay. Display all
entered values and the Gross Pay and Net Pay.*/
void exercise2() {
    printLine();
    printCentered(31, "Salary Calculation");
    cout << endl;
    printLine();

    string employee_no = getString("Enter Employee No.: ");
    string first_name = getString("Enter First Name: ");
    char middle_initial = getChar("Enter Middle Initial: ");
    string last_name = getString("Enter Last Name: ");
    string date_hired = getString("Enter Date Hired: ");
    double rate = getDouble("Enter Rate: ");
    int hours_worked = getInt("Enter No. of Hours Worked: ");

    double gross_pay = (rate * hours_worked);
    double net_pay = gross_pay - (gross_pay * 0.1);

    system("cls");
    printLine();
    printCentered(31, "Employee Report");
    cout << endl;
    printLine();

    cout
    << "Employee No.: " << employee_no << endl
    << "First Name: " << first_name << endl
    << "Middle Initial: " << middle_initial << endl
    << "Last Name: " << last_name << endl
    << "Date Hired: " << date_hired << endl
    << "Rate: " << rate << endl
    << "No. of Hours Worked: " << hours_worked << endl;
    printLine();
    cout 
    << "Gross Pay: " << fixed << setprecision(2) << gross_pay << endl
    << "Net Pay: " << fixed << setprecision(2) << net_pay << endl;
    printLine();
}

/*WAC++P that will prompt the user to enter 5 numbers, compute 
and display the Sum, Product and Average.*/
void exercise3() {
    printLine();
    printCentered(31, "Sum, Product, and Average");
    cout << endl;
    printLine();

    double numbers[5];
    double sum = 0;
    double product = 1;
    for (int i = 0; i < 5; i++) {
        cout << "Enter number [" << i + 1 << "/5]: ";
        numbers[i] = getDouble("");
        sum += numbers[i];
        product *= numbers[i];
    }
    double average = sum / 5;

    system("cls");
    printLine();
    printCentered(31, "Results");
    cout << endl;
    printLine();
    
    cout
    << "Selected Numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl
    << "Sum: " << sum << endl
    << "Product: " << product << endl
    << "Average: " << average << endl;
    printLine();
}
