#include <iostream> 

using namespace std;

int GLOBAL = 0;

int main() {
	int i;
	int a[10];
	int *pi = new int;
	cout << "Indirizzo di i: " << &i << endl;
	cout << "Indirizzo di a[]: " << a << endl;
	cout << "Indirizzo pi: " << pi << endl;
	int *darray = new int[100];
	delete pi;
	pi = nullptr;
	delete[] darray;
	darray = nullptr;
	return 0;
}
