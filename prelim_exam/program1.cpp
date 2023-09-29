#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

int main() {
    string last_name;
    string first_name;
    char middle_initial;
    string course;
    int year_level;
    string section;
    double final_grade;
    double equivalent_grade;
    string remarks;

    last_name = getString("Enter Last Name: ");
    first_name = getString("Enter First Name: ");
    middle_initial = getChar("Enter Middle Initial: ");
    course = getString("Enter Course: ");
    year_level = getInt("Enter Year Level: ", 1, 5);
    section = getString("Enter Section: ");
    final_grade = getDouble("Enter Final Grade: ", 0, 100);

    if(final_grade >= 98.5 && final_grade <= 100) {
        equivalent_grade = 1.00;
        remarks = "Excellent";
    } 
    else if(final_grade >= 95.5) {
        equivalent_grade = 1.25;
        remarks = "Outstanding";
    }
    else if(final_grade >= 92.5) {
        equivalent_grade = 1.50;
        remarks = "Superior";
    }
    else if(final_grade >= 89.5) {
        equivalent_grade = 1.75;
        remarks = "Very Good";
    }
    else if(final_grade >= 86.5) {
        equivalent_grade = 2.00;
        remarks = "Good";
    }
    else if(final_grade >= 83.5) {
        equivalent_grade = 2.25;
        remarks = "Satisfactory";
    }
    else if(final_grade >= 80.5) {
        equivalent_grade = 2.50;
        remarks = "Fairly Satisfactory";  
    }
    else if(final_grade >= 77.5) {
        equivalent_grade = 2.75;
        remarks = "Fair";  
    }
    else if(final_grade >= 74.5) {
        equivalent_grade = 3.00;
        remarks = "Passed";  
    }
    else {
        equivalent_grade = 5.00;
        remarks = "Failed";
    }

    cout << ln 
         << "Last Name: " << last_name << endl
         << "First Name: " << first_name << endl
         << "Middle Initial: " << middle_initial << endl
         << "Course: " << course << endl
         << "Year Level: " << year_level << endl
         << "Section: " << section << endl
         << "Final Grade: " << final_grade << endl
         << "Equivalent Grade: " << equivalent_grade << endl
         << "Remarks:  " << remarks << endl
         << ln;
    
    return 0;
}
