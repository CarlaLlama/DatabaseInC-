/**
*.cpp Database Driver File
* Carla Wilby 22/02/2016
*/
#include "database.h"
using namespace std;


int main(void)
{
	// Choice char
	char x;
	for (;;) {
		// Output to standard output
		cout << "\nEnter a number (or q to quit) and press return... " << endl;
		cout << "NB: All values are Case Sensitive!" << endl;
		cout << "0: Add student" << endl;
		cout << "1: Read database" << endl;
		cout << "2: Save database" << endl;
		cout << "3: Display given student data" << endl;
		cout << "4: Grade student" << endl;
		cout << "q: Quit" << endl;

		// Read in an integer from standard input
		cin >> x;
		if (x == 'q'){
			char opt;
			cout << "Are you sure you want to quit? All changes will be lost [y/n]" <<endl;
			cin >> opt;
			if(opt == 'y') break;
		}
		// Parse char to int
		int num = (int)x - 48;
		WLBCAR002::selected(num);
	}

	// Clear terminal window
	WLBCAR002::clear();

	return 0;
};

void WLBCAR002::clear(void) { system("clear"); } 

void WLBCAR002::selected(int num)
{
	string name;
	string surname;
	string studnum;
	string classrec;
	string filename;

	switch(num){
		case 0:
			getline(cin, name); //clear input stream
			cout << "Enter student name" << endl;
			getline(cin, name);
			cout << "Enter student surname" << endl;
			getline(cin, surname);
			cout << "Enter student number" << endl;
			getline(cin, studnum);
			cout << "Enter student's class record, (ie 50 65 98, or press enter if N/A)" << endl;
			getline(cin, classrec);
			cout << "Adding Student: " << name << " " << surname << " " << studnum << endl;
			cout << "With class record: " << classrec << endl;
			WLBCAR002::add_student(name, surname, studnum, classrec);
			break;
		case 1:
			getline(cin, name); //clear input stream
			cout << "Enter filename to read database from:" << endl;
			getline(cin, filename);
			WLBCAR002::read_database(filename);
			break;
		case 2:
			getline(cin, name); //clear input stream
			cout << "Enter filename to save database to:" << endl;
			cout << "[This will overwrite filename if already exists. MUST end in .txt]" << endl;
			getline(cin, filename);
			WLBCAR002::save_database(filename);
			break;
		case 3:
			getline(cin, name); //clear input stream
			cout << "Enter student number of student to display:" << endl;
			getline(cin, studnum);
			WLBCAR002::display_database(studnum);
			break;
		case 4:
			getline(cin, name); //clear input stream
			cout << "Enter student number of student to grade:" << endl;
			getline(cin, studnum);
			WLBCAR002::grade_student(studnum);
			break;
		default:
			// If not a valid number
			cout << "Please enter a valid number [1 to 4]" << endl;
			break;
	}
}