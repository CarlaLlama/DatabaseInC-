/**
*.cpp file:
*/
#include "database.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

vector<WLBCAR002::StudentRecord> database;
vector<WLBCAR002::StudentRecord>:: iterator i;

void WLBCAR002::add_student(string name, string surname, string stdnum, string classrec){
	WLBCAR002::StudentRecord sr;
	sr.Name = name;
	sr.Surname = surname;
	sr.StudentNumber = stdnum;
	sr.ClassRecord = classrec;
	database.push_back(sr);
}

void WLBCAR002::read_database(){
	string db;
	ifstream ifs("databaseFile.txt");

	if(){
		
	}
	ifs >> db;
	cout << db;
	ifs.close();
}

void WLBCAR002::save_database(){
	string writeout;
	std::ofstream out("databaseFile.txt");
	for(int i = 0; i < database.size(); i++){
		writeout += database[i].Name + " " + database[i].Surname + " " + database[i].StudentNumber + " " + database[i].ClassRecord + "\n";
	}
	out << writeout;
	out.close();
}

string WLBCAR002::display_database(string stdnum){
	//i = std::find_if(AllStudentRecords.begin(), AllStudentRecords.end(), boost::bind(&AllStudentRecords::StudentNumber, _1) == stdnum);
}

void WLBCAR002::grade_student(string stdnum){

}


