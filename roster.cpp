#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

//create parse fucntion
void Roster::parse(string studentdata)
{



    int rhs = studentdata.find(",");
    string studentID = studentdata.substr(0, rhs);
    int lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    string lastName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    string emailAddress = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    
    rhs = studentdata.find(",", lhs);
    string degree = studentdata.substr(lhs, rhs - lhs);

    DegreeProgram deg = SECURITY;

    if (degree == "NETWORK") {
        deg = NETWORK;
    }
    if (degree == "SOFTWARE") {
        deg = SOFTWARE;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, deg);
}
//Create add function
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int  age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int parr[3] = {
        daysInCourse1, daysInCourse2, daysInCourse3
    };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
}

//Create print function
void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getstudentID(); cout << '\t';
        cout << "First Name: " << classRosterArray[i]->getfirstName(); cout << '\t';
        cout << "Last Name: " << classRosterArray[i]->getlastName(); cout << '\t';
        cout << "Age: " << classRosterArray[i]->getage(); cout << '\t';
        cout << "daysInCourse: {" << classRosterArray[i]->getdaysInCourse()[0] << ", " << classRosterArray[i]->getdaysInCourse()[1] << ", " << classRosterArray[i]->getdaysInCourse()[2] << "} ";
        cout << "Degree Program: " << degreeProgramStr[classRosterArray[i]->getdegreeProgram()]; cout << endl;
    }
}

//Create avg days function
void Roster::printAverageDays(string studentID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {

        cout << classRosterArray[i]->getstudentID() << ": ";
        cout << (classRosterArray[i]->getdaysInCourse()[0] + classRosterArray[i]->getdaysInCourse()[1] + classRosterArray[i]->getdaysInCourse()[2]) / 3 << endl;
    }
    cout << endl;
}

//Create bad emails function
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string emailAddress = (classRosterArray[i]->getemailAddress());
        if (emailAddress.find('@') == string::npos ||
            emailAddress.find('.') == string::npos ||
            emailAddress.find(' ') != string::npos)
        {
            any = true;
            cout << classRosterArray[i]->getstudentID() << ": " << classRosterArray[i]->getemailAddress() << endl;
        }
    }
    if (!any) cout << "NONE" << endl;
}
 //Create Degree function
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << endl;
}


void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getstudentID() == studentID) {
            success = true;
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << studentID << " removed from table." << std::endl << endl;
        this->printAll();
    }
    else cout << "Student " << studentID << " not found." << std::endl << endl;
}

//Destructor
Roster::~Roster() 
{
    cout << "Destructor" << std::endl << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl << endl;
        classRosterArray[i] = nullptr;
        


    }
}