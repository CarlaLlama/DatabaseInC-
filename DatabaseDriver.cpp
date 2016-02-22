#include "database.h"
void selected(int num);
void clear(void);

int main(void)
{
	char x;

	for (;;) { // loop forever
		// Output to standard output
		std::cout << "Enter a number (or q to quit) and press return... " << std::endl;
		std::cout << "0: Add student" << std::endl;
		std::cout << "1: Read database" << std::endl;
		std::cout << "2: Save database" << std::endl;
		std::cout << "3: Display given student data" << std::endl;
		std::cout << "4: Grade student" << std::endl;
		std::cout << "q: Quit" << std::endl;
		// Read in an integer from standard input

		std::cin >> x;
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
		default:
			std::cout << "Please enter a valid number [1 to 4]" << std::endl;
			break;
	}
}