#include <iostream>
#include "roster.h"
using namespace std;

int main() {
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Andres,Lopez,alop645@wgu.edu,27,30,45,35,SOFTWARE"
	};
	
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010024273" << endl;
	cout << "Name: Andres Lopez\n" << endl;

	Roster classRoster;

	cout << "Displaying all students:\n\n";

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	
	classRoster.printAll();

	cout << "Displaying invalid emails:\n\n";

	classRoster.printInvalidEmails();

	cout << endl;

	classRoster.printAverageDaysInCourse("studentID");

	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl << "Removing A3:\n" << endl;

	classRoster.remove("A3");

	classRoster.printAll();

	cout << "Removing A3 again\n" << endl;

	classRoster.remove("A3");

	cout << "DONE.";

	return 0;
}