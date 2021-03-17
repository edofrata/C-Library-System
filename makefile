
# variables for the makefile
CXX = g++ -std=c++17
CXXFLAGS =  -c -Wall

all: test_cases library_main
#Compiling the file which will run the program
library_main : library_main.o library_methods.o
	$(CXX) library_main.o library_methods.o -o library_main
	

#Compiling the file which contains the main
library_main.o : library_main.cpp library.hpp
	$(CXX) $(CXXFLAGS) library_main.cpp
	
 #Compiling the methods file
library_methods.o : library_methods.cpp library.hpp
	$(CXX) $(CXXFLAGS) library_methods.cpp


# compiling the test file
test_cases : test_cases.o
	$(CXX) test_cases.o -o test_cases

test_cases.o : test_cases.cpp catch.hpp library_main.cpp
	$(CXX) $(CXXFLAGS) test_cases.cpp


# creating a PHONY target as the clean method is
.PHONY: clean
clean :
	rm *.o
	rm library_main
	rm test_cases
