/**
@file main.cpp 
@brief test d'uso della classe dbuffer
**/

#include <iostream>
#include "dbuffer.h" // dbuffer
#include <cassert>   // assert
#include <fstream>   // std::ofstream

/**
	test dei metodi fondamentali
*/
void test_fondamentali() {

	std::cout << "*** TEST METODI FONDAMENTALI ***" << std::endl;

	std::cout << "test ctor default" << std::endl;
	dbuffer db1;
	assert(db1.size() == 0); // verifichiamo lo stato dell'oggetto

	std::cout << "test ctor secondario 1" << std::endl;
	dbuffer db2(100);
	assert(db2.size() == 100);

	std::cout << "test ctor secondario 2" << std::endl;
	dbuffer db3(50,-1);
	assert(db3.size() == 50);
	for(dbuffer::size_type i =0; i < 50; i++)
		assert(db3[i] == -1);

	std::cout << "test copy constructor" << std::endl;
	dbuffer db4(db3); 
	// ATTENZIONE: una sintassi del tipo
	//             dbuffer db4 = db3;
	//             EQUIVALE ALLA CHIAMATA AL COPY CONSTRUCTOR!
	assert(db4.size() == db3.size());
	for(dbuffer::size_type i =0 ; 
		i < db4.size(); i++)
		assert(db3[i] == db4[i]);

	std::cout << "test operatore assegnamento =" << std::endl;
	db1 = db3;
	assert(db1.size() == db3.size());
	for(dbuffer::size_type i =0 ; 
		i < db1.size(); i++)
		assert(db3[i] == db1[i]);
}

/**
	test dei metodi d'uso per un dbuffer non const
*/
void test_dbuffer() {
	std::cout << "*** TEST METODI DBUFFER ***" << std::endl;

	dbuffer db(5,0);

	std::cout << "test value" << std::endl;
	db.value(1) = 100;
	assert(db.value(1) == 100);

	std::cout << "test set_value" << std::endl;
	db.set_value(0,99);
	assert(db.value(0) == 99);

	std::cout << "test scrittura op[]" << std::endl;
	db[3] = 5;
	assert(db[3]==5);

	// Se compilazione in modalita' debug da' errore 
	//db[100] = 5;

	std::cout << "test lettura op[]" << std::endl;
	dbuffer::value_type a = db[3];
	assert(a==5);

	// Se compilazione in modalita' debug da' errore 
	//int tmp = db[8];

	std::cout << "test stampa con operator<<" << std::endl;
	std::cout << db << std::endl;


	dbuffer db2;
	std::cout << "test dl metodo swap" << std::endl;
	db2.swap(db);
	assert(db.size()==0);
	assert(db2.size()==5);
	assert(db2[0]==99);
	assert(db2[1]==100);
}

/**
	funzione helper per i test dei metodi d'uso per un dbuffer const
*/
void test_dbuffer_const_helper(const dbuffer &db) {

	// Tutti i metodi di scrittura devono dare errore
	// db[1] = 10; // errore
	// db.value(1) = 10; // errore
	// db.set_value(1,10); // errore

	// I metodi di lettura devono funzionare
	dbuffer::value_type tmp1 = db[3];
	dbuffer::value_type tmp2 = db.value(3);
	dbuffer::value_type tmp3 = db.get_value(3);

	std::cout << "test stampa con operator<<" << std::endl;
	std::cout << db << std::endl;


	//dbuffer db2;
	//db2.swap(db); // errore
} 

/**
	test dei metodi d'uso per un dbuffer const
*/void test_dbuffer_const() {
	dbuffer db(5,0);

	test_dbuffer_const_helper(db);	
}

/**
	Esempio di come si può serializzare un oggetto su file. 
*/
void serializzazione_dbuffer() {
	std::cout << std::endl << "*** PROVA DI SERIALIZZAZIONE ***" << std::endl;

	// dbuffer di test
	dbuffer src(5,9999);

	// Usando operator<< possiamo scrivere su file il contenuto del dbuffer.
	// E' importante scrivere operator<< in modo tale da spedire SOLO i dati
	// e niente altro. Nel caso specifico vengono spediti nell'ordine la size 
	// e gli interi dell'array.  
	std::ofstream ofs;
	ofs.open("output.txt"); // il file è aperto come testo
	if (!ofs.is_open()) {
		std::cerr << "ERRORE NELLA'APERTURA DEL FILE" << std::endl;
		return;
	}
	ofs << src << std::endl;
	ofs.close();

	// Riapriamo il file e creiamo un secondo dbuffer con i valori salvati 
	std::ifstream ifs;
	ifs.open("output.txt");
	if (!ifs.is_open()) {
		std::cerr << "ERRORE NELLA'APERTURA DEL FILE" << std::endl;
		return;
	}
	// Leggiamo la size
	dbuffer::size_type size;
	ifs >> size;

	// Creiamo un dbuffer con la dimensione letta 
	dbuffer dst(size);

	// Leggiamo i size interi dal file direttamente nelle celle dell'array 
	for(dbuffer::size_type i=0; i<size;++i)
		ifs >> dst[i];
	ifs.close();

	std::cout <<"Contenuto del dbuffer src:" << std::endl;
	std::cout << src << std::endl;

	std::cout <<"Contenuto del dbuffer dst:" << std::endl;
	std::cout << dst << std::endl;

	// In realtà sarebbe meglio avere un operator>> ridefinito per dbuffer che viene chiamato
	// per riempire il dbuffer stesso. In pratica si potrebbe riempire uin dbuffer da file 
	// in questo modo:
	//
	// dbuffer dst2;
	// ifs >> dst2;	
	//
	// PROVATE A IMPLEMENTARE QUESTO OPERATORE
}

int main(int argc, char *argv[]) {
	
	test_fondamentali();

	test_dbuffer();

	test_dbuffer_const();

	serializzazione_dbuffer();

	return 0;
}
