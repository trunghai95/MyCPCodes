#include <bits/stdc++.h>

using namespace std;

int test, n, m, k, a[101][101];
bool f[101][101][501];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %d", &n, &m, &k);

		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", a[i]+j);

		memset(f, 0, sizeof(f));
		f[0][0][0] = true;

		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		for (int x = a[i][j]; x <= k; ++x)
			f[i][j][x] = (f[i - 1][j - 1][x - a[i][j]] || f[i - 1][j][x - a[i][j]]
					|| f[i][j - 1][x - a[i][j]]);

		int res = -1;
		for (int i = k; i >= 0; --i)
		if (f[n][m][i])
		{
			res = i;
			break;
		}

		printf("%d\n", res);
	}
	return 0;
}