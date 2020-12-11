#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("space-table.txt", "r", stdin);
	freopen("table.txt", "w", stdout);
	cout << "{\n";
	for(int i = 0; i < 24; i++) {
		cout << "\t{";
		for(int j = 0; j < 24; j++) {
			int x;
			cin >> x;
			cout << x;
			if(j == 23) {
				if(i != 23)
					cout << "},\n";
				else cout << "}\n}";
			}
			else cout << ", ";
		}
	}
}
