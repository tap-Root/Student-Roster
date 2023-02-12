#include <iostream>
#include <string>
#include "degree.h"


using namespace std;

class Student {	
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysInCourse;
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, 
		int daysInCourse[], DegreeProgram degreeProgram);
	~Student();
	
	//Accessors
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge()const;
	int* getDaysInCourse() const;
	DegreeProgram getDegree();

	//Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegree(DegreeProgram DegreeProgram);


	void print();
};