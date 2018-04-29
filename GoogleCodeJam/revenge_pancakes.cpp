#include <bits/stdc++.h>

using namespace std;

int test, n, dp[2][111];
char s[111];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%s", s);
		n = strlen(s);
		memset(dp, 0, sizeof(dp));

		dp[0][0] = (s[0] == '+');
		dp[1][0] = (s[0] == '-');

		for (int i = 1; i < n; ++i)
		{
			if (s[i] == '-')
			{
				dp[0][i] = min(dp[0][i-1], dp[1][i-1] + 1);
				dp[1][i] = dp[0][i] + 1;
			}
			else
			{
				dp[1][i] = min(dp[1][i-1], dp[0][i-1] + 1);
				dp[0][i] = dp[1][i] + 1;
			}
		}
		printf("Case #%d: %d\n", tt, dp[1][n-1]);
	}
	return 0;
}