#include <bits/stdc++.h>

using namespace std;

const int MAXN = 24;
int price[MAXN][MAXN] = {
	{4, -1, -2, -2, 0, -1, -1, 0, -2, -1, -1, -1, -1, -2, -1, 1, 0, -3, -2, 0, -2, -1, 0, -4},
	{-1, 5, 0, -2, -3, 1, 0, -2, 0, -3, -2, 2, -1, -3, -2, -1, -1, -3, -2, -3, -1, 0, -1, -4},
	{-2, 0, 6, 1, -3, 0, 0, 0, 1, -3, -3, 0, -2, -3, -2, 1, 0, -4, -2, -3, 3, 0, -1, -4},
	{-2, -2, 1, 6, -3, 0, 2, -1, -1, -3, -4, -1, -3, -3, -1, 0, -1, -4, -3, -3, 4, 1, -1, -4},
	{0, -3, -3, -3, 9, -3, -4, -3, -3, -1, -1, -3, -1, -2, -3, -1, -1, -2, -2, -1, -3, -3, -2, -4},
	{-1, 1, 0, 0, -3, 5, 2, -2, 0, -3, -2, 1, 0, -3, -1, 0, -1, -2, -1, -2, 0, 3, -1, -4},
	{-1, 0, 0, 2, -4, 2, 5, -2, 0, -3, -3, 1, -2, -3, -1, 0, -1, -3, -2, -2, 1, 4, -1, -4},
	{0, -2, 0, -1, -3, -2, -2, 6, -2, -4, -4, -2, -3, -3, -2, 0, -2, -2, -3, -3, -1, -2, -1, -4},
	{-2, 0, 1, -1, -3, 0, 0, -2, 8, -3, -3, -1, -2, -1, -2, -1, -2, -2, 2, -3, 0, 0, -1, -4},
	{-1, -3, -3, -3, -1, -3, -3, -4, -3, 4, 2, -3, 1, 0, -3, -2, -1, -3, -1, 3, -3, -3, -1, -4},
	{-1, -2, -3, -4, -1, -2, -3, -4, -3, 2, 4, -2, 2, 0, -3, -2, -1, -2, -1, 1, -4, -3, -1, -4},
	{-1, 2, 0, -1, -3, 1, 1, -2, -1, -3, -2, 5, -1, -3, -1, 0, -1, -3, -2, -2, 0, 1, -1, -4},
	{-1, -1, -2, -3, -1, 0, -2, -3, -2, 1, 2, -1, 5, 0, -2, -1, -1, -1, -1, 1, -3, -1, -1, -4},
	{-2, -3, -3, -3, -2, -3, -3, -3, -1, 0, 0, -3, 0, 6, -4, -2, -2, 1, 3, -1, -3, -3, -1, -4},
	{-1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2, -4, 7, -1, -1, -4, -3, -2, -2, -1, -2, -4},
	{1, -1, 1, 0, -1, 0, 0, 0, -1, -2, -2, 0, -1, -2, -1, 4, 1, -3, -2, -2, 0, 0, 0, -4},
	{0, -1, 0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1, 1, 5, -2, -2, 0, -1, -1, 0, -4},
	{-3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1, 1, -4, -3, -2, 11, 2, -3, -4, -3, -2, -4},
	{-2, -2, -2, -3, -2, -1, -2, -3, 2, -1, -1, -2, -1, 3, -3, -2, -2, 2, 7, -1, -3, -2, -1, -4},
	{0, -3, -3, -3, -1, -2, -2, -3, -3, 3, 1, -2, 1, -1, -2, -2, 0, -3, -1, 4, -3, -2, -1, -4},
	{-2, -1, 3, 4, -3, 0, 1, -1, 0, -3, -4, 0, -3, -3, -2, 0, -1, -4, -3, -3, 4, 1, -1, -4},
	{-1, 0, 0, 1, -3, 3, 4, -2, 0, -3, -3, 1, -1, -3, -1, 0, -1, -3, -2, -2, 1, 4, -1, -4},
	{0, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, 0, 0, -2, -1, -1, -1, -1, -1, -4},
	{-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, 1}
};
int M[256];
void compute_pos() {
	string order = "ARNDCQEGHILKMFPSTWYVBZX*";
	for(int i = 0; i < MAXN; i++)
		M[(int)order[i]] = i;
}
int main(){
	compute_pos();
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1e9));
	vector<vector<char>> from(n + 1, vector<char> (m + 1)); // U, L, D = up, left, upleft
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = (i == 0) ? 1 : 0; j <= m; j++) {
			if(i == 0) {
				dp[i][j] = dp[i][j - 1] + price[M[t[j - 1]]][M['*']];
				from[i][j] = 'L';
			} else if(j == 0) {
				dp[i][j] = dp[i - 1][j] + price[M[s[i - 1]]][M['*']];
				from[i][j] = 'U';
			} else {
				int up = dp[i - 1][j] + price[M[s[i - 1]]][M['*']];
				int left = dp[i][j - 1] + price[M[t[j - 1]]][M['*']];
				int upleft = dp[i - 1][j - 1] + price[M[s[i - 1]]][M[t[j - 1]]];
				if(up >= left && up >= upleft) {
					dp[i][j] = up;
					from[i][j] = 'U';
				} 
				if(left >= up && left >= upleft) {
					dp[i][j] = left;
					from[i][j] = 'L';
				}
				if(upleft >= up && upleft >= left) {
					dp[i][j] = upleft;
					from[i][j] = 'D';
				}
			}
		}
	}
	int i = n, j = m;
	string s1 = "", s2 = "";
	while(i != 0 || j != 0) {
		if(from[i][j] == 'U') {
			s1 += s[i - 1];
			s2 += '_';
			i--;
		} else if(from[i][j] == 'L') {
			s1 += '_';
			s2 += t[j - 1];
			j--;
		} else {
			s1 += s[i - 1];
			s2 += t[j - 1];
			i--;
			j--;
		}
	}		
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	cout << "ALLINEAMENTO: " << endl << s1 << endl << s2 << endl;
	cout << "COSTO: " << dp[n][m] << endl;
	
}
// ACGCGA CAGCGAT
// CAGTGAGCTAGA GCTAGCATCAGCATAGATGA
