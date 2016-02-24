CXX=g++

db:	database.o driver.o
	$(CXX) database.o driver.o -o db

database.o:	database.cpp database.h
	$(CXX) database.cpp -c

driver.o: driver.cpp database.h
	$(CXX) driver.cpp -c

clean:
	@rm -f *.o db

run:
	./db