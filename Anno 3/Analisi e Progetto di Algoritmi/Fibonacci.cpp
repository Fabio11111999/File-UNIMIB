#include <bits/stdc++.h>ù

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n <= 1) {
		cout << n;
	} else {
		int a = 0, b = 1, c;
		for(int i = 0; i < n - 2; i++) {
			c = a + b;
			a = b;
			b = c;
		} 
		cout << b;
	}
	return 0;
}
