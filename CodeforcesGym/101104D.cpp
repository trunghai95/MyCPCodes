#include <bits/stdc++.h>

using namespace std;

int test, n[2], cnt[2][10];
char s[2][200];

bool check() {
	for (int i = 0; i < 10; ++i) {
		if ((!cnt[0][i] && cnt[1][i]) || (cnt[0][i] && !cnt[1][i])) {
			return false;
		}
	}
	return true;
}

int solve() {
	if (check()) {
		return 0;
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j < n[i]; ++j) {
			if (((j == 1 && s[i][j-1] > '1') || (j > 1 && s[i][j-1] > '0'))
				&& s[i][j] < '9') {
				--cnt[i][s[i][j-1] - '0'];
				--cnt[i][s[i][j] - '0'];
				++cnt[i][s[i][j-1] - 1 - '0'];
				++cnt[i][s[i][j] + 1 - '0'];
				if (check()) {
					return 1;
				}
				++cnt[i][s[i][j-1] - '0'];
				++cnt[i][s[i][j] - '0'];
				--cnt[i][s[i][j-1] - 1 - '0'];
				--cnt[i][s[i][j] + 1 - '0'];
			}

			if (s[i][j-1] < '9' && s[i][j] > '0') {
				--cnt[i][s[i][j-1] - '0'];
				--cnt[i][s[i][j] - '0'];
				++cnt[i][s[i][j-1] + 1 - '0'];
				++cnt[i][s[i][j] - 1 - '0'];
				if (check()) {
					return 1;
				}
				++cnt[i][s[i][j-1] - '0'];
				++cnt[i][s[i][j] - '0'];
				--cnt[i][s[i][j-1] + 1 - '0'];
				--cnt[i][s[i][j] - 1 - '0'];
			}
		}
	}

	return 2;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 2; ++i) {
			scanf("%s", s[i]);
			n[i] = strlen(s[i]);
			for (int j = 0; j < n[i]; ++j) {
				++cnt[i][s[i][j] - '0'];
			}
		}

		int tmp = solve();
		if (tmp == 0) {
			printf("friends\n");
		} else if (tmp == 1) {
			printf("almost friends\n");
		} else {
			printf("nothing\n");
		}
	}
	return 0;
}