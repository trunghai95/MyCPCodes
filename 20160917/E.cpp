#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n, p;
ll dp[20][2010];

void init() {
	for (int i = 1; i <= 2000; ++i)
		dp[1][i] = i;

	for (int i = 2; i <= 10; ++i) {
		for (int j = 1; j <= 2000; ++j) {
			dp[i][j] += dp[i-1][j/2];
		}

		for (int j = 1; j <= 2000; ++j)
			dp[i][j] += dp[i][j-1];
	}
}

int main() {
	init();
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d", &n, &p);
		printf("%lld\n", dp[n][p]);
	}
	return 0;
}