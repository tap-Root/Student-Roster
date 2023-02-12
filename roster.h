#include <string>
#include "degree.h"
#include "student.h"

class Roster {
public:
	~Roster();
	

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, 
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void parse(string studentData);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void remove(string studentID);
	
	Student* classRosterArray[5];
	int i = -1;

};
