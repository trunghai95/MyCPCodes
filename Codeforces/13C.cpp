#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(a) cout << #a << ": " << a << '\n'

int n, k;
ll a[5001], b[5001], dp[2][5001];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", a+i);

	memcpy(b, a, sizeof(a));

	sort(b+1, b+1+n);

	++k;
	for (int j = 2; j <= n; ++j)
	if (b[j] != b[j-1])
		b[++k] = b[j];

	for (int i = 1; i <= n; ++i) {
		dp[1][1] = dp[0][1] + abs(a[i] - b[1]);
		for (int j = 2; j <= k; ++j) {
			dp[1][j] = min(dp[1][j-1], dp[0][j] + abs(a[i] - b[j]));
		}
		memcpy(dp[0], dp[1], sizeof(dp[0]));
	}

	printf("%lld\n", dp[1][k]);
	return 0;
}