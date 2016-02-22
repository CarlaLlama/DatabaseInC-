#include "database.h"
using namespace std;
void selected(int num);
void clear(void);

int main(void)
{
	char x;

	for (;;) { // loop forever
		// Output to standard output
		cout << "\nEnter a number (or q to quit) and press return... " << endl;
		cout << "0: Add student" << endl;
		cout << "1: Read database" << endl;
		cout << "2: Save database" << endl;
		cout << "3: Display given student data" << endl;
		cout << "4: Grade student" << endl;
		cout << "q: Quit" << endl;

		// Read in an integer from standard input
		cin >> x;
		if (x == 'q') break;
		int num = (int)x - 48;
		selected(num);
	}

	// Clear terminal window
	clear();

	return 0;
};

void clear(void) { system("clear"); } 

void selected(int num)
{
	string name;
	string surname;
	string studnum;
	string classrec;

	switch(num){
		case 0:
			getline(cin, name);
			cout << "Enter student name" << endl;
			getline(cin, name);
			cout << "Enter student surname" << endl;
			getline(cin, surname);
			cout << "Enter student number" << endl;
			getline(cin, studnum);
			cout << "Enter student's class record, (ie 50 65 98, or press enter if N/A)" << endl;
			getline(cin, classrec);
			cout << "Adding Student: " << name << " " << surname << " " << studnum << endl;
			
			if(classrec == ""){
				cout << "With no current class record." << endl;
			}else{
				cout << "With class record: " << classrec << endl;
			}
			WLBCAR002::add_student(name, surname, studnum, classrec);
			break;
		case 1:
			WLBCAR002::read_database();
			break;
		case 2:
			WLBCAR002::save_database();
			break;
		case 3:
			getline(cin, name);
			cout << "Enter student number of student to display:" << endl;
			getline(cin, studnum);
			WLBCAR002::display_database(studnum);
			break;
		case 4:
			getline(cin, name);
			cout << "Enter student number of student to grade:" << endl;
			getline(cin, studnum);
			WLBCAR002::grade_student(studnum);
			break;
		default:
			cout << "Please enter a valid number [1 to 4]" << endl;
			break;
	}
}