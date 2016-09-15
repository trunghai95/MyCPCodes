#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int n;
ll a[1000010], dp[1000010][2], max0, max1;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
	}

	dp[1][0] = a[1];
	dp[1][1] = -INF;

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] + a[i], a[i]));
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] - a[i]);
	}

	// for (int i = 1; i <= n; ++i)
	// 	cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';

	printf("%lld\n", max(dp[n][0], dp[n][1]));
	return 0;
}