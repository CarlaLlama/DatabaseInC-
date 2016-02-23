/**
*.cpp file: Database methods file
* 22/02/2016 Carla Wilby
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
	
	//Check that student number doesn't already exist
	for(int i = 0; i < database.size(); i++){
		if(database[i].StudentNumber == stdnum){
			cout << "Student number already exists.";
			return;
		}
	}

	//Check that all marks are valid integers
	istringstream iss(classrec);
	string mark;
	while(getline(iss, mark, ' ')){
		int markint;
		stringstream(mark) >> markint;
		if(!markint){
			cout << "Marks must be integers.";
			return;
		}
	}

	//If everything is correct make new student struct
	WLBCAR002::StudentRecord sr;
	sr.Name = name;
	sr.Surname = surname;
	sr.StudentNumber = stdnum;
	sr.ClassRecord = classrec;
	//Add record to vector
	database.push_back(sr);
}

void WLBCAR002::read_database(string filename){
	// Load default file
	ifstream ifs(filename.c_str());

	if(!ifs){
		cout << "File not found.";
		return;
	}

	// Stream file contents line by line
	string db;
	while(getline(ifs, db, '\n')){
		WLBCAR002::StudentRecord sr;
		istringstream iss(db);
		string current;
		int cnt = 1;

		// For each line, parse on ' ' to get struct members
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
		// Add new struct to vector
		database.push_back(sr);
		db="";
	}
	cout << "Student details successfully read from " + filename + ".\n";
	ifs.close();
}

void WLBCAR002::save_database(string filename){
	// Save to default file location
	string writeout;
	std::ofstream out(filename.c_str());
	// Write StudentRecord to string
	for(int i = 0; i < database.size(); i++){
		writeout += database[i].Name + " " + database[i].Surname + " " + database[i].StudentNumber + " " + database[i].ClassRecord + "\n";
	}
	// Append string to file
	out << writeout;
	out.close();
	cout << "Database saved to " + filename + "\n";
}

void WLBCAR002::display_database(string stdnum){
	string output;
	// Find student with stdnum in database
	for(int i = 0; i < database.size(); i++){
		if(database[i].StudentNumber == stdnum){
			output = "Student: " + database[i].Name + " " + database[i].Surname + "\n";
			output += "Student Number: " + database[i].StudentNumber + "\n";
			output += "Class record: " + database[i].ClassRecord + "\n";
		}
	}
	// If not
	if(output == ""){
		cout << "No such student exists in the database.";
	}else{
		cout << output;
	}
}

void WLBCAR002::grade_student(string stdnum){
	string marks;
	int sum;
	int count = 0;
	// Find student with stdnum in database
	for(int i = 0; i < database.size(); i++){
		if(database[i].StudentNumber == stdnum){
			marks = database[i].ClassRecord;
			istringstream iss(marks);
			string mark;
			// Parse marks and add them together
			while(getline(iss, mark, ' ')){
				int num;
				istringstream ss(mark);
				ss >> num;
				sum += num;
				count++;
				mark = "";
			}
		}
	}
	// If not
	if(count == 0){
		cout << "No such student exists in the database.";
	}else{
		// Find the average of the marks
		double average = (double)sum/count;
		ostringstream ss;
		ss << average;
		cout << "Average: " + ss.str();
	}
}


