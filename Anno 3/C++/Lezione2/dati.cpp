#include <iostream>

int main() {
	int i;
	short int si;
	long int li;
	long long int lli;
	std::cout << "Dimensione di i: " << sizeof(i) << std::endl;
	std::cout << "Dimensione di si: " << sizeof(si) << std::endl;
	std::cout << "Dimensione di li: " << sizeof(li) << std::endl;
	std::cout << "Dimensione di lli: " << sizeof(lli) << std::endl;
	
	struct prova {
		char c1;
		int i;
		char c2;
	};
	std::cout << "Dimensione di prova: " << sizeof(prova) << std::endl;
	
	#pragma pack(push)
	// Salvo l'informazione corrente 
	#pragma pack(1)
	// Da qui in poi allineo al byte
	// Cambio la modalità di impacchettamento
	struct prova2 {
		char c1;
		char c2;
		int i;
	};
	#pragma pack(pop)
	std::cout << "Dimesione di prova2: " << sizeof(prova2) << std::endl; 
	
	int ai[5] = {1, 2, 3, 4, 5};
	std::cout << std::endl << "Indirizzo di ai: " << ai << std::endl;
	for(int j = 0; j < 5; j++) {
		std::cout << "indirizzo di ai[" << j << "] :" << &ai[j] << std::endl;
	}
	
	int *p = ai;
	for(int j = 0; j < 5; j++){
		std::cout << "indirizzo di ai[" << j << "] :" << p++ << std::endl; 
	}
	
	int x = 10;
	short int a  = x;
	short int b = static_cast<short int>(x); 
	
	const int *pic; // Puntatori ad interi costanti 
	pic = ai; 
	int *pi = const_cast<int*>(pic);
	
	return 0;
}
