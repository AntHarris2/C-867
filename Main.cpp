#include "degree.h"
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;

Roster classRoster;

int main()
{   //Print out personal info
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Written in C++ by Anthony Harris" << endl;
    cout << "WGU ID: 0056536706" << "\n";

    
    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Anthony,Harris,aha1278@wgu.edu,26,10,15,36,SOFTWARE"
    };


    const int numStudents = 5;
    Roster roster;
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying students: " << endl;
    roster.printAll();
    cout << endl;


    cout << "Displaying invalid emails:" << endl;
    roster.printInvalidEmails();
    cout << endl;

    for (int i = 0; i < 1; i++) {
        cout << "Displaying number of days: " << endl;
        roster.printAverageDays(roster.classRosterArray[i]->getstudentID());
    }

    for (int i = 0; i < 3; i++) {
        cout << "Displaying by Degree: " << degreeProgramStr[i] << endl;
        roster.printByDegreeProgram((DegreeProgram)i);
    }


    cout << "Removing student with ID A3" << endl;
    roster.removeStudentByID("A3");
    cout << endl;

    cout << "Removing student with ID A3" << endl;
    roster.removeStudentByID("A3");
    cout << endl;


    return 0;
}