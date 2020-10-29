#ifndef dbuffer_H
#define dbuffer_H

namespace dbuffer {
	/**
		Struct che rappresenta un array dinamico di interi 
	*/
	struct dynamic_buffer {
		unsigned int size; ///< Dimensione dell'array di interi
		int *buffer; ///< Puntatore all'array di interi
	};
	
	/**
		Funzione che stampa il contenuto del buffer
		
		@param db dynamic_buffer da stampare
		@pre db.buffer != nullptr
	*/
	void stampa_buffer(const dynamic_buffer &db);
	
	/**
		Funzione che inizializza un buffer
		
		@param db dynamic_buffer da inizializzare
		@post db.size == 0
		@post db.buffer == nullptr
	*/
	void inizializza_buffer(dynamic_buffer &db);
	
	/**
		Funzione che alloca la memoria di un buffer
		
		@param db dynamic buffer da allocare
		@post db.size == size
		@post db.buffer != nullptr
	*/
	void alloca_buffer(dynamic_buffer &db, unsigned int size);
	
	/**
		Funzione che dealloca la memoria contenuta nel dynamic_buffer
		
		@param db dynamic_buffer
		@post db.size == 0
		@post db.buffer == nullptr
	*/
	void dealloca_buffer(dynamic_buffer &db);
	
	/**
		Funzione che riempe le celle dell'array di interi in dynamic_buffer.
		In questa versione i valori provengono da un altro array di interi la 
		cui dimensione deve essere uguale a db.size
		
		@param db dynamic_buffer da modificare
		@param values puntatore all'array di interi con i valori da usare
		@param val_size dimensione dell'array di interi
		@pre db.buffer != nullptr
		@pre values != nullptr
		@pre val_size ==db.size
	*/
	void riempi_buffer(dynamic_buffer &db, const int *values, unsigned int val_size);
	
	/**
		Funzione che clona il contenuto di un dynamic_buffer in un nuovo dynamic_buffer
		
		@param src dynamic_buffer da copiare
		@return un nuovo dynamic_buffer con il contenuto di src
	*/
	dynamic_buffer copia_buffer(const dynamic_buffer &src);
}

#endif
