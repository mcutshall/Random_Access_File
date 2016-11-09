// Random_Access_File.cpp : Defines the entry point for the console application.
/*
Program: Assign 6- Random Access File

Purpose: This program creates a Student class an instantiates 6 Student objects. The objects are then
written to a file which may be modified. Some of the records are updated after the initial write, 
and the updated information is displayed.

Created: 3/25/2016

Developer: Michael Cutshall

*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

template<typename T>
void displayData(T& obj)
{
	cout << "\n" << obj.toString() << "\n";
}

bool readFile(fstream&, Student&);
void readRecord(fstream&, Student&, int);
void updateRecord(fstream&, Student&);

int main()
{
	fstream binaryFS;//output stream object

	const char FILE_NAME[] = "StudentInfo.dat";

	//open file for output
	binaryFS.open(FILE_NAME, ios::out | ios::binary);

	//instantiate student objects
	Student stu1(001, "Jenkins", "Bill", "MAT", 42.0, 3.8);
	Student stu2(002, "McSally", "Sally", "PSY", 46.0, 4.0);
	Student stu3(003, "Escobar", "Pablo", "CHM", 42.0, 3.5);
	Student stu4(004, "Grouch", "Oscar", "BIO", 55.0, 3.7);
	Student stu5(005, "Halloway", "Jennifer", "ENG", 33.0, 4.0);
	Student stuInput;

	binaryFS.write(reinterpret_cast<char*> (&stu1), sizeof(Student));
	binaryFS.write(reinterpret_cast<char*> (&stu2), sizeof(Student));
	binaryFS.write(reinterpret_cast<char*> (&stu3), sizeof(Student));
	binaryFS.write(reinterpret_cast<char*> (&stu4), sizeof(Student));
	binaryFS.write(reinterpret_cast<char*> (&stu5), sizeof(Student));

	//close the file, then re-open it to read data
	binaryFS.close();
	binaryFS.open(FILE_NAME, ios::in | ios::binary);

	cout << "\n\n \t\t\t   *****Student Data***** \n\n";
	bool eof = readFile(binaryFS, stuInput);

	while (!eof)
	{
		displayData(stuInput);
		eof = readFile(binaryFS, stuInput);
	}

	binaryFS.close();

	//Display data for second student
	binaryFS.open(FILE_NAME, ios::in | ios::binary);
	cout << "\n\t\t    ****Data for the Second Student****\n";
	readRecord(binaryFS, stuInput, stu2.getStudentID());
	displayData(stuInput);
	binaryFS.close();

	//Update major code for third student
	binaryFS.open(FILE_NAME, ios::in | ios::out | ios::binary);
	stu3.setMajorCode("PSY");
	updateRecord(binaryFS, stu3);
	binaryFS.close();

	//Display updated record
	binaryFS.open(FILE_NAME, ios::in | ios::binary);
	cout << "\n\t\t   ****Updated Record for Third Student****\n";
	readRecord(binaryFS, stuInput, stu3.getStudentID());
	displayData(stuInput);
	binaryFS.close();

	//update credits earned for fourth student
	binaryFS.open(FILE_NAME, ios::in | ios::out | ios::binary);
	stu4.setCreditsEarned(66.6);
	updateRecord(binaryFS, stu4);
	binaryFS.close();

	//Display updated record
	binaryFS.open(FILE_NAME, ios::in | ios::binary);
	cout << "\n\t\t   ****Updated Record for Fourth Student****\n";
	readRecord(binaryFS, stuInput, stu4.getStudentID());
	displayData(stuInput);
	binaryFS.close();

	//Update GPA of fifth student
	binaryFS.open(FILE_NAME, ios::in | ios::out | ios::binary);
	stu5.setGPA(3.8);
	updateRecord(binaryFS, stu5);
	binaryFS.close();

	//Display updated record
	binaryFS.open(FILE_NAME, ios::in | ios::binary);
	cout << "\n\t\t   ****Updated Record for Fifth Student****\n";
	readRecord(binaryFS, stuInput, stu5.getStudentID());
	displayData(stuInput);
	binaryFS.close();

	cout << "\nPress Enter to Continue... \n\n";
	cin.get();

}
void readRecord(fstream& binaryFS, Student& studentToRead, int keyValue)
{
	int byteToBegineReading = (keyValue - 1) * sizeof(Student);
	/*cout << "\n\nReadRecord: byteToBeginReading " << byteToBegineReading
		<< "\nStudentToRead.getStudentID " << studentToRead.getStudentID()
		<< "\nsizeof(Student) " << sizeof(Student)
		<< "\n\n";*/

	binaryFS.seekg(byteToBegineReading);//position pointer at the correct record
	/*cout << "\n\nreadRecord: tellg " << binaryFS.tellg()
		<< "\ngoodbit " << binaryFS.goodbit
		<< "\nbadbit " << binaryFS.badbit
		<< "\nfailbit" << binaryFS.failbit
		<< "\nisopen " << binaryFS.is_open()
		<< "\n\n";*/

	binaryFS.read(reinterpret_cast<char*> (&studentToRead), sizeof(Student));
}

void updateRecord(fstream& binaryFS, Student& studentToUpdate)
{
	int byteToBeginWriting = (studentToUpdate.getStudentID() - 1) * sizeof(Student);

	/*cout << "\n\nupdateRecord: byteToBeginWriting " << byteToBeginWriting
		<< "\nstudentToUpdate.getStudentID " << studentToUpdate.getStudentID()
		<< "\nsizeof(Student) " << sizeof(Student)
		<< "\n\n";*/

	binaryFS.seekp(byteToBeginWriting);
	/*cout << "\n\nupdateRecord " << binaryFS.tellp()
		<< "\ngoodbit " << binaryFS.goodbit
		<< "\nbadbit " << binaryFS.badbit
		<< "\nfailbit " << binaryFS.failbit
		<< "\nis_open " << binaryFS.is_open()
		<< "\n\n";*/

	binaryFS.write(reinterpret_cast<char*> (&studentToUpdate), sizeof(Student));
}

bool readFile(fstream& binaryFS, Student& stuInput)
{
	binaryFS.read(reinterpret_cast<char*> (&stuInput), sizeof(Student));

	if (!binaryFS)
		return true;
	else
		return false;
}
