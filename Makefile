CXX=g++

fact:	Factorial.o FactorialDriver.o
	$(CXX) Factorial.o FactorialDriver.o -o fact

Factorial.o:	factorial.cpp factorial.h
	$(CXX) factorial.cpp -c

FibDriver.o:	FibDriver.cpp Fib.h
	$(CXX) FibDriver.cpp -c

clean:
	@rm -f *.o fib


