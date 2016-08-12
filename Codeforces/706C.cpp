#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 2e18;

int n;
ll c[100010], dp[100010][2];
string s[100010][2];
char cs[100010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", c+i);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", cs);
		s[i][0] = s[i][1] = string(cs);
		reverse(s[i][1].begin(), s[i][1].end());
		dp[i][0] = dp[i][1] = INF;
	}

	dp[1][0] = 0;
	dp[1][1] = c[1];

	for (int i = 2; i <= n; ++i)
	{
		if (dp[i-1][0] != -1)
		{
			if (s[i][0] >= s[i-1][0])
				dp[i][0] = min(dp[i][0], dp[i-1][0]);
			if (s[i][1] >= s[i-1][0])
				dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
		}

		if (dp[i-1][1] != -1)
		{
			if (s[i][0] >= s[i-1][1])
				dp[i][0] = min(dp[i][0], dp[i-1][1]);
			if (s[i][1] >= s[i-1][1])
				dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
		}
	}

	ll res = min(dp[n][0], dp[n][1]);
	if (res >= INF)
		printf("-1\n");
	else
		printf("%lld\n", res);
	return 0;
}