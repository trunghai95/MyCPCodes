#include <bits/stdc++.h>

using namespace std;

int n, k, c;
bool f[501][501][501];

int main()
{
	scanf("%d %d", &n, &k);

	f[0][0][0] = true;

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &c);
		for (int j = 0; j <= 500; ++j)
		for (int kk = 0; kk <= 500; ++kk)
		{
			f[i][j][kk] = f[i-1][j][kk];

			if (j >= c)
			{
				f[i][j][kk] |= f[i-1][j-c][kk];
				if (kk >= c)
					f[i][j][kk] |= f[i-1][j-c][kk-c];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i <= k; ++i)
		cnt += f[n][k][i];
	printf("%d\n", cnt);
	for (int i = 0; i <= k; ++i)
	if (f[n][k][i])
		printf("%d ", i);
	return 0;
}