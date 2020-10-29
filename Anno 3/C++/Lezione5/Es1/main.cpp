#include "dbuffer.h"
#include <iostream>

int main() {
	// dbuffer db; // Chiamata al costruttore di default
	// dbuffer *adb =  new dbuffer[5]; //array statico di 5 dbuffer
	// delete[] adb;
	dbuffer db(10, 42);
	db.value(5) = 100;
	for(unsigned int i = 0; i < db.get_size(); i++)
		std::cout << db.value(i) << " ";
	std::cout << std::endl;
	return 0;
}
