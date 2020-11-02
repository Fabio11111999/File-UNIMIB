#include "dbuffer.h"
#include <iostream>

void f(dbuffer d) {}

int main() {
	// dbuffer db; // Chiamata al costruttore di default
	// dbuffer *adb =  new dbuffer[5]; //array statico di 5 dbuffer
	// delete[] adb;
	/*dbuffer db(10, 42);
	db.value(5) = 100;
	for(unsigned int i = 0; i < db.get_size(); i++)
		std::cout << db.value(i) << " ";
	std::cout << std::endl; */
	/*
	dbuffer db(5, 2);
	dbuffer db2(db); // Copy constructor
	dbuffer db3 = db; // Copy constructor
	f(db); // Chiamata al Copy constructor */
	dbuffer db(3, 0);
	dbuffer db2;
	db2 = db;
	return 0;
}
