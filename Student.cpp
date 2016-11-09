/*
Program: Assign 6- Random Access File

Purpose: This program creates a Student class an instantiates 6 Student objects. The objects are then
written to a file which may be modified. Some of the records are updated after the initial write,
and the updated information is displayed.

Created: 3/25/2016

Developer: Michael Cutshall

*/

#include "stdafx.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
Student::Student()
{
	setStudentID(0);
	setLastName("");
	setFirstName("");
	setMajorCode("");
	setCreditsEarned(0.0);
	setGPA(0.0);
}

//Parameter accepting constructor
Student::Student(int studentID, string lastName, string firstName, string majorCode, double creditsEarned, double GPA)
{
	setStudentID(studentID);
	setLastName(lastName);
	setFirstName(firstName);
	setMajorCode(majorCode);
	setCreditsEarned(creditsEarned);
	setGPA(GPA);
}

//set methods
void Student::setStudentID(int studentID)
{
	this->studentID = studentID;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setMajorCode(string majorCode)
{
	this->majorCode = majorCode;
}

void Student::setCreditsEarned(double creditsEarned)
{
	this->creditsEarned = creditsEarned;
}

void Student::setGPA(double GPA)
{
	this->GPA = GPA;
}

//getter methods
int Student::getStudentID()
{
	return studentID;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getMajorCode()
{
	return majorCode;
}

double Student::getCreditsEarned()
{
	return creditsEarned;
}

double Student::getGPA()
{
	return GPA;
}

//method to convert integers to strings
string getIntegerStr(int number)
{
	stringstream sstrm;
	sstrm << number;
	return sstrm.str();
}

//method to convert doubles to strings
string getDoubleStr(double number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

string Student::toString()
{
	string IDString = getIntegerStr(studentID);
	string creditsStr = getDoubleStr(creditsEarned);
	string GPAStr = getDoubleStr(GPA);

	return (" Student ID     : " + IDString + "\n" +
			" Last Name      : " + lastName + "\n" +
			" First Name     : " + firstName + "\n" +
			" Major Code     : " + majorCode + "\n" +
			" Credits Earned : " + creditsStr + "\n" +
			" GPA            : " + GPAStr + "\n");
}