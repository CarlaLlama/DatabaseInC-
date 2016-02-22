#include <iostream> // Include I/O Stream library headers.
#include <cstdlib>
#include "fib.h"

int main(void)
{
	int x;
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
	// Clear terminal window
	void clear(void) { system("clear"); } 

	for (;;) { // loop forever
		int val = selected(x);
		if (val == 1) break;
	}

	return 0;
}

int selected(int num)
{
	switch(num){
		case '0':
			cout << "Function AddStudent() called." << endl;
			break;
		case '1':
			cout << "Function ReadDatabase() called." << endl;
			break;
		case '2':
			cout << "Function SaveDatabase() called." << endl;
			break;
		case '3':
			cout << "Function DisplayDatabase() called." << endl;
			break;
		case '4':
			cout << "Function GradeStudent() called." << endl;
			break;
		case 'q':
			cout << "Quitting..." << endl;
			return 1;
			break;
		return 0; 
	}
}