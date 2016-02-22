#include "database.h"
int selected(int num);
void clear(void);

int main(void)
{
	char x;

	for (;;) { // loop forever
		// Output to standard output
		std::cout << "Enter a number (or q to quit) and press return... " << std::endl;
		std::cout << "Add student [0]: " << std::endl;
		std::cout << "Read database [1]: " << std::endl;
		std::cout << "Save database [2]: " << std::endl;
		std::cout << "Display given student data [3]: " << std::endl;
		std::cout << "Grade student [4]: " << std::endl;
		std::cout << "Quit [q]: " << std::endl;
		// Read in an integer from standard input

		std::cin >> x;
		if (x == 'q') break;
		int val = selected((x - '0'));
	}

	// Clear terminal window
	clear();

	return 0;
}

void clear(void) { system("clear"); } 

int selected(int num)
{
	switch(num){
		case 0:
			std::cout << "Function AddStudent() called." << std::endl;
			break;
		case 1:
			std::cout << "Function ReadDatabase() called." << std::endl;
			break;
		case 2:
			std::cout << "Function SaveDatabase() called." << std::endl;
			break;
		case 3:
			std::cout << "Function DisplayDatabase() called." << std::endl;
			break;
		case 4:
			std::cout << "Function GradeStudent() called." << std::endl;
			break;
		case 'q':
			std::cout << "Quitting..." << std::endl;
			return 1;
			break;
		return 0; 
	}
}