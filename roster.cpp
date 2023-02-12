#include <iostream>
#include <string>
#include "roster.h"
#include <regex>


using namespace std;


Roster::~Roster() {
	
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {

	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++i] = new Student(studentID, firstName, lastName, emailAddress, age,
		daysInCourse, degree);

}

void Roster::printAll() {
	for (int i = 0; i < 5; ++i) {

		if (classRosterArray[i] != nullptr) {

			classRosterArray[i]->Student::print();
		}
	}

	cout << endl;
}

void Roster::parse(string studentData) {
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram;

	if (strDegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (strDegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	Roster::add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::printInvalidEmails() {
	string email;
	for (int i = 0; i < 5; ++i) {
		email = classRosterArray[i]->Student::getEmail();
		const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!regex_match(email, pattern)) {
			cout << email << " - is invalid.\n";
		}
	}

}
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; ++i) {
		studentID = classRosterArray[i]->Student::getStudentID();
		int* days = classRosterArray[i]->Student::getDaysInCourse();
		int avg = (days[0] + days[1] + days[2]) / 3;
		cout << "Student ID: " << studentID << ", average days in course is: " << avg << endl;
		
	}


}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	string degreeStr;
	if (degree == 0) {
		degreeStr = "SECURITY";
	}
	else if (degree == 1) {
		degreeStr = "NETWORK";
	}
	else {
		degreeStr = "SOFTWARE";
	}
	cout << "Showing students in degree program: " << degreeStr << endl << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->Student::getDegree() == degree) {
			classRosterArray[i]->Student::print();
		}
	}
}
void Roster::remove(string studentID) {

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "The student with the ID: " << studentID << " was not found." << endl;
		}
		else if (classRosterArray[i] != nullptr && classRosterArray[i]->Student::getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			Roster::~Roster();
		}
	}
}

