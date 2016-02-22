CXX=g++

db:	database.o DatabaseDriver.o
	$(CXX) database.o DatabaseDriver.o -o db

database.o:	database.cpp database.h
	$(CXX) database.cpp -c

DatabaseDriver.o:	DatabaseDriver.cpp database.h
	$(CXX) DatabaseDriver.cpp -c

clean:
	@rm -f *.o db

run:
	./db