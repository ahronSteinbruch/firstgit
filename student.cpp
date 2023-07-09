
#include "student.h"



	 Student::Student(unsigned long id, const char* fName, const char* lastName, float age, int grade ) {
		this->ID = id;
		memcpy(this->firstName, fName, 99);
		this->firstName[99] = '\0';
		memcpy(this->lastName, lastName, 99);
		this->lastName[99] = '\0';
		this->grade = grade;
		this->age = age;
		this->marks = nullptr;
		this->numOfTests = 0;
	}
//
	 Student:: Student() {
		const char* fNameJune = "june";
		const char* lNameJune = "do";
		this->ID = 0;
		memcpy(this->firstName, fNameJune, strlen(fNameJune));
		this->firstName[99] = '\0';
		memcpy(this->lastName, lNameJune, strlen(lNameJune));
		this->lastName[99] = '\0';
		this->grade = -1;
		this->age = -1;
		this->marks = nullptr;
		this->numOfTests = 0;
	}
	 Student:: ~Student() {
		free(this->marks);
		//free(this);
	};
	void Student:: addMark(int mark) {

		this->marks = (int*)realloc(this->marks, (numOfTests + 1) * sizeof(int));
		this->marks[this->numOfTests] = mark;
		numOfTests++;
	}
	void Student::update(int mark,int index) {
		if (index > numOfTests) {
			cout << "error the exem don't exist";
			return;
		}
		this->marks[index] = mark;
	}


	void Student::printer() {
		 cout <<"I am " << this->age << " years old. " << "my name is " << firstName << " " << lastName
			<< " I am in grede " << grade << " my marks : ";
		for (size_t i = 0; i < numOfTests; i++)
		{
			cout << " exem num " << i  + 1 << ": " << marks[i];
		}
		cout << '\n';

	};
