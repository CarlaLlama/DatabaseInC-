/**
*.cpp file:
*/
#include "database.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
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
	
	ifstream ifs("databaseFile.txt");

	if(!ifs){
		cout << "File not found.";
		return;
	}

	string db;

	while(getline(ifs, db, '\n')){
		WLBCAR002::StudentRecord sr;
		istringstream iss(db);
		string current;
		int cnt = 1;

		while(getline(iss, current, ' ')){
			if(cnt==1){
				sr.Name = current;
			}
			else if(cnt==2){
				sr.Surname = current;
			}
			else if(cnt==3){
				sr.StudentNumber = current;
			}
			else{
				sr.ClassRecord += current + " ";
			}
			cnt++;
		}
		database.push_back(sr);
		db="";
	}
	cout << "Student details successfully read from databaseFile.txt.\n";
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
	cout << "Database saved to databaseFile.txt.\n";
}

void WLBCAR002::display_database(string stdnum){
	string output;
	for(int i = 0; i < database.size(); i++){
		if(database[i].StudentNumber == stdnum){
			output = "Student: " + database[i].Name + " " + database[i].Surname + "\n";
			output += "Student Number: " + database[i].StudentNumber + "\n";
			output += "Class record: " + database[i].ClassRecord + "\n";
		}
	}
	if(output == ""){
		cout << "No such student exists in the database.";
	}else{
		cout << output;
	}
}

void WLBCAR002::grade_student(string stdnum){
	string marks;
	int sum;
	int count;
	for(int i = 0; i < database.size(); i++){
		if(database[i].StudentNumber == stdnum){
			marks = database[i].ClassRecord;
			istringstream iss(marks);
			string mark;
			while(getline(iss, mark, ' ')){
				int num;
				num = atoi(mark.c_str());
				sum += num;
				count++;
				mark = "";
			}
		}
	}
	double average = (double)sum/count;
	ostringstream ss;
	ss << average;
	string stravg(ss.str());
	cout << "Average:" + stravg;
}


