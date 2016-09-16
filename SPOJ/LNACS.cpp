#include <bits/stdc++.h>

using namespace std;

int n, m, a[1010], b[1010], dp[1010][1010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for (int i = 1; i <= m; ++i)
		scanf("%d", b+i);

	for (int i = 1; i <= n; ++i)
	if (a[i] == b[1])
		dp[i][1] = 1;
	else
		dp[i][1] = dp[i-1][1];

	for (int j = 1; j <= m; ++j)
	if (b[j] == a[1])
		dp[1][j] = 1;
	else
		dp[1][j] = dp[1][j-1];

	for (int i = 2; i <= n; ++i)
	for (int j = 2; j <= m; ++j) {
		dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		if (a[i] == b[j])
			dp[i][j] = max(dp[i][j], dp[i-2][j-2] + 1);
	}

	printf("%d\n", dp[n][m]);
	return 0;
}