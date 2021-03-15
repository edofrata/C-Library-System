
# variables for the makefile
CXX = g++ -std=c++17
CXXFLAGS =  -c -Wall

 #Compiling the file which will run the program
library_main : library_main.o library_methods.o.o
	$(CXX) library_main.o libraery_methods.o -o music_shop
	

 #Compiling the file which contains the main
library_main.o : library_main.cpp library.hpp
	$(CXX) $(CXXFLAGS) library_main.cpp
	
 #Compiling the methods file
library_methods.o : library_methods.cpp music_shop.hpp
	$(CXX) $(CXXFLAGS) library_methods.cpp

 # creating a PHONY target as the clean method is
.PHONY: clean
clean :
	rm *.o
	rm library_main
	# rm music_shop_test
