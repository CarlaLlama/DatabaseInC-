STUDENT RECORDS DATABASE
------------------------

To compile this project:
	Extract project to desired directory
	cd into project directory
	run:
		$ make

To run this project:
	Ensure it has been compiled correctly
	cd into project directory
	run:
		$ make run
	Follow prompts.

To clean project:
	run:
		$ make clean

FILE STRUCTURE
--------------

Makefile:
	Used to correctly compile source files.
DatabaseDriver.cpp:
	Source file containing main() method, called at start of project.
database.h:
	Header file containing method and struct declaration.
database.cpp:
	Source file containing method implementation.
databaseFile.txt:
	Default file that database is saved to.

MAINTAINERS
-----------

Current Maintainers:
* Carla Wilby (carlallama) - https://github.com/CarlaLlama