#include <iostream> 
#include <cassert>
#include "dbuffer.h"

int main(int argc, char **argv) {
	dbuffer::dynamic_buffer db; 
	dbuffer::inizializza_buffer(db);
	dbuffer::alloca_buffer(db, 10);
	int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	dbuffer::riempi_buffer(db, values, 10);
	dbuffer::dynamic_buffer copia = dbuffer::copia_buffer(db);
	dbuffer::stampa_buffer(db);
	dbuffer::stampa_buffer(copia);
	dbuffer::dealloca_buffer(db);
	dbuffer::dealloca_buffer(copia);
	assert(1 < 0);
	return 0;
}
