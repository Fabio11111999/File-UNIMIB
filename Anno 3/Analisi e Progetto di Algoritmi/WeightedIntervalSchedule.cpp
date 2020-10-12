#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

struct range{
	int l, r, val;
	bool operator<(const range &other) const {
		return r < other.r
	}
}v[MAXN];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> v[i].l >> v[i].r >> v[i].val;
	}
	sort(v, v + n);
	vector<int> p(n);
	for(int i = 1; i < n; i++) {
		int low = 0, mid, high = i - 1, pos = -1;
		while(low <= high) {
			mid = (low + high) / 2;
			if(v[mid].r < v[i].l) {
				pos = mid;
				low = mid + 1;
			} else {
				high = mid -1;
			}
		}
		p[i] = pos;
	}
	vector<int> dp(n);
	dp[0] = v[0].val;
	for(int i = 1; i < n; i++) {
		dp[i] = max(dp[i-1], v[i].val);
		if(p[i] > -1 && dp[p[i]] + v[i].val > dp[i]) {
			dp[i] = dp[p[i]] + v[i].val;
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
