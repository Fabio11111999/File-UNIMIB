#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int m = static_cast<int>(s.size());
	int n = static_cast<int>(t.size());
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1; 
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = m, j = n;
	string ans = "";
	while(i > 0 && j > 0) {
		if(dp[i - 1][j] == dp[i][j]) {
			i--;
		} else if(dp[i][j - 1] == dp[i][j]){
			j--;
		} else {
			ans += s[i - 1];
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << " " << ans << endl;
	return 0;
}
