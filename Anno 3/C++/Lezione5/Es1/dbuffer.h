#ifndef DBUFFER_H
#define DBUFFER_H

/**
	@file dbuffer.h
	@brief dichiarazione della classe dbuffer
*/



/**
	@brief Array dinamico di interi
	
	Classe che rappresenta un array dinamico di interi.
	La dimensione dell'array può essere scelta in fase di costruzione.
*/
class dbuffer {
	private:
		int *_buffer; ///< Puntatore all'array dinamico di interi 
		unsigned int _size; ///< Dimensione dell'array

	public:
		/**
			@brief Costruttore di default
			
			Costruttore di default per istanziare un dbuffer vuoto
			
			@post _buffer == nullptr
			@post _size == 0
		*/
		dbuffer();
		
		
		
		/**
			@brief costruttore secondario
			
			Costruttore secondario che crea un dbuffer della dimensione data
			
			@param sz dimensione del dbuffer na creare
			@post _size == sz
		*/
		dbuffer(unsigned int sz);
		
		
		
		/**
			@brief costruttore secondario
			
			Costruttore secondario che crea un dbuffer della dimensione data
			e inizializza le celle del buffer al valore passato
			
			@param sz dimensione del dbuffer na creare
			@param value valore di inizializzazione delle celle
			@post _size == sz
		*/
		dbuffer(unsigned int sz, int value);
		
		
		
		/**
			@brief distruttore della classe
			
			Distruttore della classe: rimuove dallo heap l'array
			
			@post _buffer == nullptr
			@post _size == 0
		*/
		~dbuffer();
		
		
		
		/**
			@brief accesso ai dati in lettura
			Accesso ad un elemento del buffer
			@param index indice del valore da leggere
			@pre index < _size
			@return valore della cella in posizione index
		*/
		int get_value(unsigned int index) const;
		
		
		
		/**
			@brief accesso ai dati in scrittura
			Scritture di un elemento del buffer
			@param index indice del valore da scrivere
			@param value valore da scrivere in posizione index
			@pre index < _size
			@post _buffer[index] == value
		*/
		void set_value(unsigned int index, int value);
		
		
		
		/**
			@brief Getter/Setter della cella index
			Funzione che permette di leggere/scrivere la cella index
			@param indice della cella da leggere/scrivere
			@return reference alla cella index
		*/
		int &value(unsigned int index);
		
		
		
		/**
			@brief ritorna dimensione del buffer
			Metodo per ottenere la dimensione dell'array dinamico
			@return dimensione dell'array dinamico
		*/
		unsigned int get_size() const ;
};

#endif
