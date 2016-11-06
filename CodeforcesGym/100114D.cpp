#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[100010], ast[100010], back[100010];
char s[100010];

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i-1] + (s[i] == '*');
		if (s[i] == '*')
			ast[++m] = i;
	}

	if (m == 0) {
		printf("0\n");
		return 0;
	}

	int res = m, resl = -1, resr = -1;
	back[1] = 1;

	for (int i = 2; i <= m; ++i) {
		int b = ast[back[i-1]];
		if (ast[i] - b - (i - back[i-1]) < i) {
			back[i] = back[i-1];
			int tmp = 2 + ast[i] - b - (i - back[i-1]) + back[i-1] - 1 + m - i;
			if (tmp <= res) {
				res = tmp;
				resl = back[i];
				resr = i;
			}
		} else {
			back[i] = i;
		}

		cout << i << ' ' << back[i] << '\n';
	}

	if (resl == -1) {
		printf("%d\n%d\n", m, ast[1]);
		for (int i = 2; i <= m; ++i) {
			printf("Ctrl+%d\n", ast[i]);
		}
	} else {
		printf("%d\n%d\nShift+%d\n", res, ast[resl], ast[resr]);
		for (int i = 1; i < resl; ++i) {
			printf("Ctrl+%d\n", ast[i]);
		}
		for (int i = resr + 1; i <= m; ++i) {
			printf("Ctrl+%d\n", ast[i]);
		}
		for (int i = ast[resl]; i <= ast[resr]; ++i)
		if (s[i] == '.') {
			printf("Ctrl+%d\n", i);
		}
	}
	return 0;
}