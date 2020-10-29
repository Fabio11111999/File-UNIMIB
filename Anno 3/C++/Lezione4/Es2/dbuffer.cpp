#include <cassert>
#include <iostream>
#include "dbuffer.h"

namespace dbuffer {
	void stampa_buffer(const dynamic_buffer &db) {
		assert(db.buffer != nullptr);
		for(unsigned int i = 0; i < db.size; i++) 
			std::cout << db.buffer[i] << " ";
		std::cout << std::endl;
	}
	void inizializza_buffer(dynamic_buffer &db) {
		db.size = 0;
		db.buffer = nullptr;
	}
	void alloca_buffer(dynamic_buffer &db, unsigned int size) {
		if(db.buffer != nullptr)
			dealloca_buffer(db);
		db.buffer =  new int[size];
		db.size = size;
	}
	void dealloca_buffer(dynamic_buffer &db) {
		delete[] db.buffer;
		inizializza_buffer(db);
	}
	void riempi_buffer(dynamic_buffer &db, const int *values, unsigned int val_size) {
		assert(db.buffer != nullptr);
		assert(values != nullptr);
		assert(db.size == val_size);
		for(unsigned int i = 0; i < db.size; i++)
			db.buffer[i] = values[i];
	}
	dynamic_buffer copia_buffer(const dynamic_buffer &src) {
		dynamic_buffer dst;
		inizializza_buffer(dst);
		alloca_buffer(dst, src.size);
		riempi_buffer(dst, src.buffer, src.size);
		return dst;
	}
}
