#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
int n, m, res;
bool a[17][17], b[17][17];
char s[20];

void flipcheck(int i, int j) {
	if (j < 0)
		return;
	b[i][j] = !b[i][j];
}

void flip(int i, int j) {
	b[i][j] = !b[i][j];
}

int main() {
	while (true) {
		scanf("%d %d", &n, &m);

		if (n == 0) {
			return 0;
		}

		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			for (int j = 0; j < m; ++j) {
				a[i][j] = (s[j] == 'X');
			}
		}

		int nn = (1 << m);
		res = INF;

		for (int mask = 0; mask < nn; ++mask) {
			int cnt = 0;

			memcpy(b, a, sizeof(a));
			for (int j = 0; j < m; ++j) {
				if ((mask >> j) & 1) {
					++cnt;
					flip(0, j); flip(1, j);
					flip(0, j+1); flipcheck(0, j-1);
				}
			}

			for (int i = 1; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (b[i-1][j]) {
						++cnt;
						flip(i, j); flip(i+1, j);
						flipcheck(i, j-1); flip(i, j+1);
					}
				}
			}

			for (int j = 0; j < m; ++j)
			if (b[n-1][j]) {
				cnt = INF;
				break;
			}

			res = min(res, cnt);
		}

		if (res == INF) {
			printf("Damaged billboard.\n");
		} else {
			printf("You have to tap %d tiles.\n", res);
		}
	}
	return 0;
}