#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll a[3001], b[3001], dp[3001][3001];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
		a[i] -= i;
	}

	memcpy(b, a, sizeof(a));
	sort(b+1, b+1+n);

	++k;
	for (int i = 2; i <= n; ++i)
	if (b[i] != b[i-1])
		b[++k] = b[i];

	for (int i = 1; i <= n; ++i) {
		dp[i][1] = dp[i-1][1] + abs(a[i] - b[1]);
		for (int j = 2; j <= k; ++j) {
			dp[i][j] = min(dp[i][j-1], dp[i-1][j] + abs(a[i] - b[j]));
		}
	}

	printf("%lld\n", dp[n][k]);
	return 0;
}