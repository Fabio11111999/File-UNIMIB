#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h> 

int read_input(char **s, char **t) {
	size_t n, m;
	printf("Type the length of the first string:\n");
	scanf("%ld", &n);
	*s = malloc((n + 1) * sizeof(char));
	if(*s == NULL)
		return -1;
	printf("Type the first string:\n");
	scanf("%s", *s);
	printf("Type the length of the second string:\n");
	scanf("%ld", &m);
	*t = malloc((m + 1) * sizeof(char));
	if(*t == NULL)
		return -1;
	printf("Type the second string:\n");
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
void print_input(char *s, char *t) {
	printf("N: %ld, M: %ld, s: %s, t: %s\n", strlen(s), strlen(t), s, t);
}
char* band_align(size_t band, char *s, char *t) {
	int64_t rows = strlen(s), cols = 2 * band + 1;
	int64_t **dp = (int64_t **)malloc(rows * cols * sizeof(int64_t *));
	if(dp == NULL)
		return NULL;
	for(uint64_t i = 0; i < rows; i++) {
		dp[i] = (int64_t *)malloc(cols * sizeof(int64_t));
		if(dp[i] == NULL)
			return NULL;
	}
	return NULL;
}
int main(int argc, char *argv[]) {
	char *s, *t;
	int correct_read = read_input(&s, &t);
	if(correct_read == -1) {
		printf("Can't read the input");
		return 0;
	}
	print_input(s, t);
	char *result = band_align(1, s, t);
	return 0;
}
