#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

int n, m;
char s[100010];
ll dp[2010][2010], en, mn;

ll& DP(int i, int j) { return dp[i][j]; }

int main()
{
	scanf("%d %d %s", &n, &m, s);

	n -= m;

	mn = 2e9;
	for (int i = 0; i < m; ++i)
	{
		en += (s[i] == '(' ? 1 : -1);
		mn = min(mn, en);
	}

	if (en < -n || mn < -n || en > n || mn > n)
	{
		printf("0");
		return 0;
	}

	DP(0, 0) = 1;

	for (int i = 1; i <= n; ++i)
	for (int j = 0; j < i; ++j)
	{
		DP(i, j-1) = (DP(i, j-1) + DP(i-1, j)) % MODD;
		DP(i, j+1) = (DP(i, j+1) + DP(i-1, j)) % MODD;
	}

	ll res = 0;

	for (int i = 0; i <= n; ++i)
	for (int j = max(-mn, 0LL); j <= i; ++j)
	{
		ll tmp = (DP(i, j) * DP(n - i, j + en)) % MODD;
		res = (res + tmp) % MODD;
	}

	printf("%lld", res);
	return 0;
}