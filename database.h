/**
*.h file: Header file
* 22/02/2016 Carla Wilby
*/

#ifndef DATABASE_H
#define DATABASE_H
#include <iostream> // Include I/O Stream library headers.
#include <cstdlib>
#include <vector>

// Define namespace
namespace WLBCAR002 {

	void selected(int num);
	
	void clear(void);

	struct StudentRecord {
			std::string Name;
			std::string Surname;
			std::string StudentNumber;
			std::string ClassRecord;
	};

	extern std::vector<StudentRecord>  database;

	void add_student(std::string name, std::string surname, std::string stdnum, std::string classrec);

	void read_database(std::string filename);

	void save_database(std::string filename);

	void display_database(std::string stdnum);

	void grade_student(std::string stdnum);

}

#endif
