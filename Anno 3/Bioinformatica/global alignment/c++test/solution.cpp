#include <bits/stdc++.h>

using namespace std;
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out(){
	cerr<<endl;
}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){
	cerr<<' '<< H; 
	dbg_out(T...);
}
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
int pos[256];
void compute_pos() {
	string order = "ARNDCQEGHILKMFPSTWYVBZX*";
	for(int i = 0; i < MAXN; i++)
		pos[(int)order[i]] = i;
}
bool in_bounds(int i, int j, int rows, int width) {
	if(i < 0 || j < 0 || i > rows || j >= width)
		return false;
	if(i + j < width / 2) // top left-corner
		return false;
	return true;
}
struct result {
	int answer;
	string s1;
	string s2;
	bool correct;
};
ostream &operator<<(ostream &os, const result &x) {
	os << "Answer: " << x.answer << endl;
	os << "s: " << x.s1 << endl;
	os << "t: " << x.s2 << endl;
	return os;
}
result calc(string &s, string &t, int band) {
	int n = s.length(), m = t.length();
	if(band < (int)(t.length() - s.length()))
		return {0, "", "", false};
	band = min(band, m);
	int width = 2 * band  + 1;
	//dbg(n, m, band, width);
	vector<vector<int>> dp(n + 1, vector<int>(width, -1e9));
	vector<vector<char>> pre(n + 1, vector<char>(width, '-'));
	dp[0][band] = 0;
	pre[0][band] = '*';
	for(int i = 0; i <= n; i++) {
		for(int j = i - band; j <= i + band; j++) {
			if(i < 0 || j < 0 || i > n || j > m)
				continue;
			int mappedi = i, mappedj = j - i + band;
			//dbg(i, j, mappedi, mappedj);
			if(in_bounds(mappedi, mappedj - 1, n, width)) {
				int left = dp[mappedi][mappedj - 1] + price[pos['*']][pos[(int)t[j - 1]]];
				if(left > dp[mappedi][mappedj]) {
					dp[mappedi][mappedj] = left;
					pre[mappedi][mappedj] = 'L';
				}
			}
			if(in_bounds(mappedi - 1, mappedj + 1, n, width)) {
				int up = dp[mappedi - 1][mappedj + 1] + price[pos[(int)s[i - 1]]][pos['*']];
				if(up > dp[mappedi][mappedj]) {
					dp[mappedi][mappedj] = up;
					pre[mappedi][mappedj] = 'U';
				}
			}
			if(in_bounds(mappedi - 1, mappedj, n, width)) {
				int up_left = dp[mappedi - 1][mappedj] + price[pos[(int)s[i - 1]]][pos[(int)t[j - 1]]];
				if(up_left > dp[mappedi][mappedj]) {
					dp[mappedi][mappedj] = up_left;
					pre[mappedi][mappedj] = 'D';
				}
			}
		}
	}
	int x = n, y = m - n + band;
	string s1 = "", s2 = "";
	while(pre[x][y] != '*') {
		int realy = y + x - band;
		if(pre[x][y] == 'L') {
			s1 += '_';
			s2 += t[realy - 1];
			y--;
		}
		else if(pre[x][y] == 'U') {
			s1 += s[x - 1];
			s2 += '_';
			x--;
			y++;
		}
		else if(pre[x][y] == 'D') {
			s1 += s[x - 1];
			s2 += t[realy - 1];
			x--;
		}
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	return {dp[n][m - n + band], s1, s2, true};
}
int best_aligment(string &s) {
	int score = 0;
	for(int i = 0 ; i < (int)s.length(); i++)
		score += price[pos[(int)s[i]]][pos[(int)s[i]]];
	return score;
}
int main() {
	string s, t;
	cin >> s >> t;
	if(s.length() > t.length())
		swap(s, t);
	compute_pos();
	int best = best_aligment(s);
	int start = t.length() - s.length();
	int offset = 1;
	result ans;
	while(start + offset <= (int)t.length()) {
		int band = start + offset;
		ans = calc(s, t, band);
		int upper = best + (-4 * (band + 1));
		if(upper <= ans.answer)
			break;
		offset *= 2;
	}
	cout << ans;
}
/*
 ABCAB ABABACD 
 CAGTGAGCTAGA GCTAGCATCAGCATAGATGA
 
 
*/ 
