#include <iostream> 
#include <cassert>

void stampa_stringa(const char *s) {
	assert(s != nullptr);
	while(*s != '\0')
		std::cout << *s++ << std::endl;
}

unsigned int calcola_lunghezza(const char *s) {
	assert(s != nullptr);
	unsigned int ans = 0;
	while(*s != '\0') {
		s++;
		ans++;
	}
	return ans;
}

void inverti(char *s) {
	unsigned int l = 0, r = calcola_lunghezza(s) - 1;
	while(l < r) {
		char tmp = *(s + l);
		*(s + l) = *(s + r);
		*(s + r) =  tmp;
		l++, r--;
	}
}
char* copia(const char *c) {
	assert(c != nullptr);
	unsigned int n = calcola_lunghezza(c);
	char *s = new char[n + 1];
	for(unsigned int i = 0; i <= n; i++)
		s[i] = c[i];
	return s;
}
char* concatena(const char *s, const char *t) {
	assert(s != nullptr && t != nullptr);
	unsigned int n = calcola_lunghezza(s), m = calcola_lunghezza(t);
	char *ans = new char[n + m + 1];
	for(unsigned int i = 0; i < n; i++)
		ans[i] = s[i];
	for(unsigned int i = 0; i <= m; i++)
		ans[n + i] = t[i];
	return ans;
}
int main(int argc, char *argv[]) {
	assert(argc == 3);
	char *conc = concatena(argv[1], argv[2]);
	stampa_stringa(conc);
	delete[] conc;
	conc = nullptr;
	
	return 0;
}
