#pragma once
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
using namespace std;
class Student
{
public:
	unsigned long ID;
	char firstName[100];
	char lastName[100];
	int grade; // כיתה
	float age;
	int* marks; // <-- note! It's an array
	int numOfTests;
	Student();
	Student(unsigned long id, const char* fName, const char* lastName, float age, int grade);
	~Student();
	void addMark(int mark);
	void update(int mark, int index);

	void printer();

};