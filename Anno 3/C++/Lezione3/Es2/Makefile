CXX = g++
CXXFLAGS = -Wall -g
INCLUDES = -Iinclude

main: main.o point.o rectangle.o
	$(CXX) main.o point.o rectangle.o -o main

main.o: main.cpp include/point.h include/rectangle.h
	$(CXX) -c main.cpp $(INCLUDES) -o main.o

point.o: src/point.cpp include/point.h
	$(CXX) -c src/point.cpp $(INCLUDES) -o point.o
	
rectangle.o: src/rectangle.cpp include/rectangle.h
	$(CXX) -c src/rectangle.cpp $(INCLUDES) -o rectangle.o
