#include<iostream>
using namespace std;

//Write a C++ program that will display
//(5) information about you

int main()
{
	// declaration
	char first_name[] = "Glen Angelo";
    char middle_name[] = "Dayao";
    char last_name[] = "Bautista";
    int age = 20;
    char course[] = "BSCS";
    int year_level = 2;
    char phone_number[] = "09162114655";
    
	//output
    cout
    << "First Name: " << first_name << endl
    << "Middle Name: " << middle_name << endl
    << "Last Name: " << last_name << endl
    << "Age: " << age << endl
    << "Course: " << course << endl
    << "Year Level: " << year_level << endl
    << "Phone Number: " << phone_number << endl;
    
    return 0;
}