#include "band.h"

int pos[256];
void compute_pos() {
	char order[] = "ARNDCQEGHILKMFPSTWYVBZX*";
	for(unsigned int i = 0; i < 24; i++)
		pos[(unsigned int)order[i]] = i;
}
int in_bounds(int i, int j, int rows, int width) {
	if(i < 0 || j < 0 || i > rows || j >= width || i + j < width / 2)
		return 0;
	return 1;
}
// read: length of s, s, length of t, t. swap(s, t) if length of s is greater than length of t
int read_input(char **s, char **t) {
	size_t n, m;
	scanf("%ld", &n);
	*s = malloc((n + 1) * sizeof(char));
	scanf("%s", *s);
	scanf("%ld", &m);
	*t = malloc((m + 1) * sizeof(char));
	scanf("%s", *t);
	if(n != strlen(*s) || m != strlen(*t))
		return -1;
	if(n > m) {
		char *tmp = *s;
		*s = *t;
		*t = tmp;
	}
	return 0;
}
// best alignment for a string s, aligned with a string equal to s
int64_t best_aligment(char *s) {
	size_t n = strlen(s);
	int64_t score = 0;
	for(unsigned int i = 0; i < n; i++)
		score += price[pos[(int)s[i]]][pos[(int)s[i]]];
	return score;
}
// reverse a string
void reverse_string(char *s) {
	char *start = s, *end = s + strlen(s) - 1;
	char tmp;
	while(start < end) {
		tmp = *start;
		*start = *end;
		*end = tmp;
		end--;
		start++;
	}
}
// compute the best alignment of s and t in a limited band
struct result band_align(char *s, char *t, int band) {
	struct result answer = {-1e9, NULL, NULL, 0};
	int n = strlen(s), m = strlen(t);
	if(band < m - n)
		return answer;
	if(band > m)
		band = m;
	int width = 2 * band + 1;
	int64_t **dp = (int64_t **)malloc((n + 1) * sizeof(int64_t *));
	char **pre = (char **)malloc((n + 1) * sizeof(char *));
	for(unsigned int i = 0; i <= n; i++) {
		dp[i] = (int64_t *)malloc(width * sizeof(int64_t));
		pre[i] = (char *)malloc(width * sizeof(char));
	}
	for(unsigned int  i = 0; i <= n; i++)
		for(unsigned int j = 0; j < width; j++)
			dp[i][j] = -1e9;
	dp[0][band] = 0;
	pre[0][band] = '*';
	for(int i = 0; i <= n; i++) {
		for(int j = i - band; j <= i + band; j++) {
			if(j < 0 || j > m)
				continue;
			int mappedi = i, mappedj = j - i + band;
			if(in_bounds(mappedi, mappedj - 1, n, width) == 1) {
				int64_t left = dp[mappedi][mappedj - 1] + price[pos['*']][pos[(int)t[j - 1]]];
				if(left > dp[mappedi][mappedj]) {
					dp[mappedi][mappedj] = left;
					pre[mappedi][mappedj] = 'L';
				}
			}
			if(in_bounds(mappedi - 1, mappedj + 1, n, width) == 1) {
				int64_t up = dp[mappedi - 1][mappedj + 1] + price[pos[(int)s[i - 1]]][pos['*']];
				if(up > dp[mappedi][mappedj]) {
					dp[mappedi][mappedj] = up;
					pre[mappedi][mappedj] = 'U';
				}
			}
			if(in_bounds(mappedi - 1, mappedj, n, width) == 1) {
				int64_t up_left = dp[mappedi - 1][mappedj] + price[pos[(int)s[i - 1]]][pos[(int)t[j - 1]]];
				if(up_left > dp[mappedi][mappedj]) {
					dp[mappedi][mappedj] = up_left;
					pre[mappedi][mappedj] = 'D';
				}
			}
		}
	}
	// finding the size of the alignment 
	int x = n, y = m - n + band;
	int newn = 0;
	while(pre[x][y] != '*') {
		newn++;
		if(pre[x][y] == 'L')
			y--;
		else if(pre[x][y] == 'U') {
			x--;
			y++;
		}
		else if(pre[x][y] == 'D')
			x--;
	}
	char *news1 = malloc(newn + 1);
	char *news2 = malloc(newn + 1);
	int _i = 0, _j = 0;
	x = n, y = m - n + band;
	// reconstruct the strings
	while(pre[x][y] != '*') {
		int realy = y + x - band;
		if(pre[x][y] == 'L') {
			news1[_i++] = '_';
			news2[_j++] = t[realy - 1]; 
			y--;
		}
		else if(pre[x][y] == 'U') {
			news1[_i++] = s[x - 1];
			news2[_j++] = '_';
			x--;
			y++;
		}
		else if(pre[x][y] == 'D') {
			news1[_i++] = s[x - 1];
			news2[_j++] = t[realy - 1]; 
			x--;
		}
	}
	reverse_string(news1);
	reverse_string(news2);
	struct result correct_answer = {dp[n][m - n + band], news1, news2, 1};
	return correct_answer;
}
int main(int argc, char *argv[]) {
	char *s, *t;
	int correct_read = read_input(&s, &t);
	if(correct_read == -1) {
		printf("Can't read the input");
		return 0;
	}
	compute_pos();
	int64_t best = best_aligment(s);
	int start = strlen(t) - strlen(s), offset = 1;
	struct result ans;
	// enlarging the band
	while(start + offset <= (int) strlen(t)) {
		int band = start + offset;
		ans = band_align(s, t, band);
		int64_t upper = best + (-4 * (band + 1));
		if(upper <= ans.answer)
			break;
		offset *= 2;
	}
	printf("Score: %ld \ns: %s \nt: %s\n", ans.answer, ans.s1, ans.s2);
	return 0;
}
