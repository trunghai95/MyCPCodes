#include <bits/stdc++.h>

using namespace std;

const int MODD = 5318008;

int test, n, x1, Y1, x2, y2, dp[5010][5010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %d %d %d", &n, &x1, &Y1, &x2, &y2);
		int begin, end, len;
		if (abs(x1 - x2) == abs(Y1 - y2))
		{
			printf("1\n");
			continue;
		}

		if (abs(x1 - x2) < abs(Y1 - y2))
			begin = x1, end = x2, len = abs(Y1 - y2);
		else
			begin = Y1, end = y2, len = abs(x1 - x2);

		memset(dp, 0, sizeof(dp));

		dp[0][begin] = 1;

		for (int i = 1; i <= len; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MODD;
				dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MODD;
				dp[i][j] = (dp[i][j] + dp[i-1][j]) % MODD;
			}
		}

		printf("%d\n", dp[len][end]);
	}
	return 0;
}