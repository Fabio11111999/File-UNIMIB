/**
	@file dbuffer.cpp
	@brief Definizione della classe dbuffer
*/

#include "dbuffer.h"
#include <iostream>
#include <cassert>

dbuffer::dbuffer() : _buffer(nullptr), _size(0) { 
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer()" << std::endl;
	#endif 
}
dbuffer::dbuffer(unsigned int sz) : _buffer(nullptr), _size(0) {
	_buffer = new int[sz];
	_size = sz;
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(unsigned int sz)" << std::endl;
	#endif 
}
dbuffer::dbuffer(unsigned int sz, int value) : _buffer(nullptr), _size(0) {
	_buffer = new int[sz];
	_size = sz;
	for(unsigned int i = 0; i < sz; i++)
		_buffer[i] = value;
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(unsigned int sz, int value)" << std::endl;
	#endif 
}
dbuffer::~dbuffer() {
	delete[] _buffer;
	_buffer = nullptr;
	_size = 0;
	#ifndef NDEBUG
	std::cout << "~dbuffer()" << std::endl;
	#endif
}
int dbuffer::get_value(unsigned int index) const {
	assert(index < _size);
	return _buffer[index];
}
void dbuffer::set_value(unsigned int index, int value) {
	assert(index < _size);
	_buffer[index] = value;
} 
int &dbuffer::value(unsigned int index) {
	assert(index < _size);
	return _buffer[index];
}
unsigned int dbuffer::get_size() const {
	return _size;
}
