#include<iostream>
#include "glencryppt.hpp"
using namespace std;
using namespace gc;

//Write a C++ program that will display
//a student's name, student number, course,
//year and section.

struct student {
    char* student_name;
    char* student_number;
    char* course;
    int year_level;
    char* section;
};

int main() {
   student student1;

    student1.student_name = "Glen Angelo Bautista";
    student1.student_number = "2022-1-01604";
    student1.course = "BSCS";
    student1.year_level = 2;
    student1.section = "C231";
    
    // output information
    cout
    << "Student Information\n"
    << "========================================================================\n"
    << "         Name          | Student Number | Course | Year Level | Section \n "
    << student1.student_name << "  | "
    << student1.student_number << "   | "
    << student1.course << "   | "
    << student1.year_level << "          | "
    << student1.section << endl
    << "========================================================================\n";
    waitEnter();

    return 0;
}
