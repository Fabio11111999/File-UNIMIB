/**
	@file dbuffer.cpp
	@brief Definizione della classe dbuffer
*/

#include "dbuffer.h"
#include <iostream>
#include <cassert>
#include <algorithm>

dbuffer::dbuffer() : _buffer(nullptr), _size(0) { 
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer()" << std::endl;
	#endif 
}
dbuffer::dbuffer(unsigned int sz) : _buffer(nullptr), _size(0) {
	_buffer = new value_type[sz];
	_size = sz;
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(unsigned int sz)" << std::endl;
	#endif 
}
dbuffer::dbuffer(unsigned int sz, value_type value) : _buffer(nullptr), _size(0) {
	_buffer = new int[sz];
	_size = sz;
	for(unsigned int i = 0; i < sz; i++)
		_buffer[i] = value;
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(unsigned int sz, value_typet value)" << std::endl;
	#endif 
}
dbuffer::dbuffer(const dbuffer &other) : _buffer(nullptr), _size(0) {
	_buffer = new value_type[other._size];
	_size = other._size;
	for(unsigned int i = 0; i < _size; i++)
		_buffer[i] = other._buffer[i];
	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(const dbuffer &other)" << std::endl;
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
dbuffer& dbuffer::operator=(const dbuffer &other) {
	if(this != &other) {
		dbuffer tmp(other);
		swap(tmp);
	}
	#ifndef NDEBUG
	std::cout << "operator=(const dbuffer &other)" << std::endl;
	#endif
	return *this;
}
dbuffer::value_type dbuffer::get_value(unsigned int index) const {
	assert(index < _size);
	return _buffer[index];
}
void dbuffer::set_value(unsigned int index, value_type value) {
	assert(index < _size);
	_buffer[index] = value;
} 
dbuffer::value_type& dbuffer::value(unsigned int index) {
	assert(index < _size);
	return _buffer[index];
}
const dbuffer::value_type& dbuffer::value(unsigned int index) const {
	assert(index < _size);
	return _buffer[index];
}
unsigned int dbuffer::size() const {
	return _size;
}
void dbuffer::swap(dbuffer &other) {
	std::swap(_buffer, other._buffer);
	std::swap(_size, other._size);
}
