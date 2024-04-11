#pragma once
#include <string>
#include <iostream>
#include "student.h"
using std::cout;


class Roster {

public:
    int lastIndex = -1;

    const static int numStudents = 5;

    Student* classRosterArray[numStudents];

    void parse(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void printAll();
    void printAverageDays(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);


    void removeStudentByID(string studentID);

    Student* getStudentAt(int index);

    //The destructor
    ~Roster();
};