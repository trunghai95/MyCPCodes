#include <bits/stdc++.h>

using namespace std;

int test, n, m, a, b, x[50010], dp[50010][110], mn[110];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d %d %d", &n, &m, &a, &b);
		memset(dp, -1, sizeof(dp));
		memset(mn, 0, sizeof(mn));

		for (int i = 0; i < n; ++i) {
			scanf("%d", x+i);

			for (int j = 0; j < m; ++j) {
				dp[i][j] = j*b + mn[m-1];
				if (i > 0 && x[i-1] <= j) {
					dp[i][j] = min(dp[i][j], mn[j-x[i-1]] - b*(m - j));
				}
				if (j + x[i] > m)
					dp[i][j] += a*(j + x[i] - m);
				else
					dp[i][j] += b*(m - j - x[i]);
			}

			mn[0] = dp[i][0];
			for (int j = 1; j < m; ++j)
				mn[j] = min(mn[j-1], dp[i][j]);
		}

		printf("%d\n", mn[m-1]);
	}
	return 0;
}