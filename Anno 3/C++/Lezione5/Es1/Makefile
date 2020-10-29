 

main: main.o dbuffer.o
	g++ main.o dbuffer.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o
	
dbuffer.o: dbuffer.cpp
	g++ -c dbuffer.cpp -o dbuffer.o

.PHONY: clear
clear: 
	rm *.o main
