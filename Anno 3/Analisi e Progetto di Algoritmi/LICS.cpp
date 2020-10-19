#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(m);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	for(int j = 0; j < m; j++)
		cin >> y[j];
	vector<int> dp(m); //dp[j] = length of LICS ending with y[j]
	for(int i = 0; i < n; i++) {
		int current = 0;
		for(int j = 0; j < m; j++) {
			if(x[i] == y[j] && dp[j] < current + 1)
				dp[j] = current + 1;
			if(x[i] > y[j] && current < dp[j])
				current = dp[j];
		}
	}
	cout << *(max_element(dp.begin(), dp.end()));
}
