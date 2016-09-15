#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int n;
ll a[25010], dp[25010][2];

int main() {
	scanf("%d", &n);

	for (int i = 1; i < n; ++i)
		scanf("%lld", a+i);

	dp[1][0] = INF;
	dp[1][1] = a[1];

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][0] + a[i-1]);
		dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + a[i];
	}

	printf("%lld\n", dp[n][0]);

	return 0;
}