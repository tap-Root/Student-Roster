#include <iostream>
#include "student.h"
using namespace std;

Student::Student() 
	:
	studentID(""),
	firstName(""),
	lastName(""),
	email(""),
	age(0){
	daysInCourse = new int[3];

	for (int i = 0; i < 3; ++i) {
		daysInCourse[i] = 0;
	}

}
	
Student::Student(string studentID, string firstName, string lastName, string email, int age, int DaysInCourse[], DegreeProgram DegreeProgram) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysInCourse(DaysInCourse);
	setDegree(DegreeProgram);
	


}
Student::~Student() {
	
}

//Accessor Functions

string Student::getStudentID() const{
	return studentID;
}
string Student::getFirstName() const{
	return firstName;
}
string Student::getLastName() const {
	return lastName;
}
string Student::getEmail() const {
	return email;
}
int Student::getAge() const {
	return age;
}

int* Student::getDaysInCourse() const {
	return daysInCourse;
}
DegreeProgram Student::getDegree() {
	return this->degreeProgram;
}


//Mutator functions definition


void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegree(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t";
	cout << getAge() << "\t";
	//cout << getDaysInCourse() << "\t";
	cout << "{" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}\t";
	if (this->getDegree() == 0) {
		cout << "SECURITY";
	}
	else if (this->getDegree() == 1) {
		cout << "NETWORK";
	}
	else {
		cout << "SOFTWARE";
	}
	cout << endl;
}

