#include <bits/stdc++.h>

using namespace std;

int n, m, k, dp[1001][1001][11];
char s[1001], t[1001];

int f(int i, int j, int p)
{
	if (i < 0 || j < 0 || p == 0)
		return 0;
	if (dp[i][j][p] != -1)
		return dp[i][j][p];
	dp[i][j][p] = max(f(i, j-1, p), f(i-1, j, p));
	int cnt = 0;
	while (cnt <= min(i, j) && s[i-cnt] == t[j-cnt])
		++cnt;
	return dp[i][j][p] = max(dp[i][j][p], f(i-cnt, j-cnt, p-1) + cnt);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d %s %s", &n, &m, &k, s, t);
	printf("%d", f(n-1, m-1, k));
	return 0;
}