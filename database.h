/**
*.h file:
*/

#ifndef DATABASE_H
#define DATABASE_H
#include <iostream> // Include I/O Stream library headers.
#include <cstdlib>
//any includes here
namespace WLBCAR002 {
void add_student(std::string name, std::string surname, std::string stdnum, std::string classrec);

void read_database();

void save_database();

std::string display_database(std::string stdnum);

void grade_student(std::string stdnum);

struct StudentRecord {
		std::string Name;
		std::string Surname;
		std::string StudentNumber;
		std::string ClassRecord;
};

}

#endif
