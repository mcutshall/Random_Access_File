/*
Program: Assign 6- Random Access File

Purpose: This program creates a Student class an instantiates 6 Student objects. The objects are then
written to a file which may be modified. Some of the records are updated after the initial write,
and the updated information is displayed.

Created: 3/25/2016

Developer: Michael Cutshall

*/

#pragma once
#ifndef _Student
#define _Student
#include <string>

using namespace std;

class Student
{
public:
	Student();//default constructor


	Student(int, string, string, string, double, double);

	//setter methods
	void setStudentID(int);
	void setLastName(string);
	void setFirstName(string);
	void setMajorCode(string);
	void setCreditsEarned(double);
	void setGPA(double);

	//getter methods
	int getStudentID();
	string getLastName();
	string getFirstName();
	string getMajorCode();
	double getCreditsEarned();
	double getGPA();

	string toString();

private:
	string lastName, firstName, majorCode;
	int studentID;
	double creditsEarned, GPA;

};
#endif

