#include <stdio.h>

int test;
char s[3009];
bool dp[3009][3009];

int main() {

	scanf("%d", &test);

	while (test --> 0) {
		scanf("%s", s);

		int res1 = 1, res2 = 0;

		for (int i = 0; s[i]; ++i) {
			dp[i][i] = true;
			if (res1 == 1) {
				++res2;
			}

			if (i > 0) {
				if (s[i] == s[i-1]) {
					dp[i-1][i] = true;
					if (res1 == 2) {
						++res2;
					} else if (res1 < 2) {
						res1 = 2;
						res2 = 1;
					}
				} else {
					dp[i-1][i] = false;
				}
			}

			for (int j = 0; j < i - 1; ++j) {
				if (s[i] == s[j] && dp[j+1][i-1]) {
					dp[j][i] = true;
					int len = i - j + 1;
					if (len > res1) {
						res1 = len;
						res2 = 1;
					} else if (len == res1) {
						++res2;
					}
				} else {
					dp[j][i] = false;
				}
			}
		}

		printf("%d %d\n", res1, res2);
	}
	return 0;
}