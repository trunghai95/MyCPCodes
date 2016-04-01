#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int dirx[4] = {0,0,1,-1};
const int diry[4] = {1,-1,0,0};

int n, m;
ll k, a[1000][1000];
int ck[1000][1000];

bool valid(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int main()
{
	scanf("%d %d %lld", &n, &m, &k);

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
	{
		scanf("%lld", a[i]+j);
	}

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
	{
		if (k % a[i][j] != 0 || k / a[i][j] > n*m)
			continue;

		int nn = k / a[i][j];
		queue<pii> q;
		int res = 1;
		int ff = i*100000+j;
		ck[i][j] = ff;
		q.push(pii(i, j));

		while (!q.empty() && res < nn)
		{
			pii u = q.front(); q.pop();
			// printf("%d %d\n", u.first, u.second);

			for (int d = 0; d < 4 && res < nn; ++d)
			{
				int nr = u.first + dirx[d];
				int nc = u.second + diry[d];
				if (!valid(nr, nc) || ck[nr][nc] == ff || a[nr][nc] < a[i][j])
					continue;
				++res;
				ck[nr][nc] = ff;
				q.push(pii(nr, nc));
			}
		}
		// printf("%d\n", res);

		if (res >= nn)
		{
			printf("YES\n");
			for (int r = 0; r < n; ++r)
			{
				for (int c = 0; c < m; ++c)
					printf("%lld ", (ck[r][c] == ff)?a[i][j]:0LL);
				printf("\n");
			}
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}