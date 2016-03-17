#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[2010];
ll dp[2010][2010];
bool isPalin[2010][2010];

int main()
{
	cin >> s;

	int n = strlen(s);

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 1;
		isPalin[i][i] = true;
		for (int j = i - 1; j >= 0; --j)
		{
			dp[j][i] = dp[j][i-1] + dp[j+1][i] - dp[j+1][i-1];
			if (s[j] == s[i] && (j == i - 1 || isPalin[j+1][i-1]))
				++dp[j][i], isPalin[j][i] = true;
		}
	}

	ll res = 0;
	for (int i = 0; i < n - 1; ++i)
	for (int j = 0; j <= i; ++j)
	if (isPalin[j][i])
		res += dp[i+1][n-1];

	cout << res;
	return 0;
}