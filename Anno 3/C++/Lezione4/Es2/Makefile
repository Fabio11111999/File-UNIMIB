CXXFLAGS = -DNDEBUG

main: main.o dbuffer.o
	g++ -CXXFLAGS main.o dbuffer.o -o main

main.o: main.cpp
	g++ -CXXFLAGS -c main.cpp -o main.o
	
dbuffer.o: dbuffer.cpp
	g++ -CXXFLAGS -c dbuffer.cpp -o dbuffer.o

.PHONY: clear
clear: 
	rm *.o main
