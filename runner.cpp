#include "namespaceGames.h"
#include "student.h"


int main()
{
	Student s1(10,"yaron", "shtain", 18.f, 10);
	Student s2(2,"moshe", "levy", 28.f, 10);
	Student s3(4,"ahron", "nachmany", 08.f, 10);
	Student s4(6,"yabenyron", "sufer", 133.f, 10);
	//if i dun't have the defult c'tur i cen`t be able to do students with tipe student
	Student students[4] = {s1,s2,s3,s4};
	students[0].addMark(58);
	students[0].addMark(38);
	students[0].addMark(90);
	students[0].addMark(100);
	
	bool shouldExit = false;


	while (!shouldExit)
	 {
		printf(
			"what would you like to do?\n"
			"1 Add new mark \n"
			"2 Edit existing mark\n"
			"3 Print data of all 4 students\n"
			"4 Exit \n");

		int choice = -1;
		scanf_s("%d", &choice);

		switch (choice) // TODO: Implement the following:
		{

			//Option 1 : let the user choose student index(0 - 3) and new mark.
		case 1:
			int studentIndex;
			int newMark;
			cout << "Enter student index (0 - 3): ";
			cin >> studentIndex;
			cout << "Enter new mark: ";
			cin >> newMark;
			if (studentIndex >= 0 && studentIndex < 4) {
				students[studentIndex].addMark(newMark);
				cout << "Mark added successfully." << endl;
			}
			else {
				cout << "Invalid student index." << endl;
			}
			break;

		case 2:
			int editStudentIndex;
			int markIndex;
			int editedMark;
			cout << "Enter student index (0 - 3): ";
			cin >> editStudentIndex;
			cout << "Enter mark index: ";
			cin >> markIndex;
			cout << "Enter new mark: ";
			cin >> editedMark;
			if (editStudentIndex >= 0 && editStudentIndex < 4 && markIndex >= 0) {
				students[studentIndex].update(editedMark, markIndex);
				cout << "Mark edited successfully." << endl;
			}
			else {
				cout << "Invalid student or mark index." << endl;
			}
			break;
		case 3:
			for (size_t i = 0; i < 4; i++)
			{
				students[i].printer();
			}
			break;
		case 4:
			shouldExit = true;
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
		//
// Question! answer in comment: should you call the d'tor of each 
// of the students explicitly? something like:
		//students[0].~Student(); // noooooooo
		// why ?becuse its hapend outomaticly when the blok code stop to run
	}
	return 0;
}