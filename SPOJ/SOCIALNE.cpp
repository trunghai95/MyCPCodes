#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int test, n, dist[60][60];
char s[60];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		n = INF;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s);
			if (n == INF)
				n = strlen(s);

			for (int j = 0; j < n; ++j)
			{
				if (s[j] == 'Y')
					dist[i][j] = 1;
				else
					dist[i][j] = INF;
			}

			dist[i][i] = 0;
		}

		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		for (int k = 0; k < n; ++k)
		if (dist[i][j] + dist[i][k] < dist[j][k])
			dist[j][k] = dist[k][j] = dist[i][j] + dist[i][k];

		int mx = -1, mxi = -1;
		for (int i = 0; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
				cnt += (dist[i][j] == 2);
			if (cnt > mx)
				mx = cnt, mxi = i;
		}

		printf("%d %d\n", mxi, mx);
	}
	return 0;
}