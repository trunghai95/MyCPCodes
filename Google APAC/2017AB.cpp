#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int INF = 2e9;
int test, r, c, h[51][51], res;
bool ck[51][51];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool outofmat(int x, int y)
{
	return x > r || x < 1 || y > c || y < 1;
}

bool bfs(int x, int y)
{
	int mn = INF;
	queue<pii> q;
	memset(ck, 0, sizeof(ck));
	q.push(pii(x, y));
	ck[x][y] = true;

	while (!q.empty())
	{
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pii v(u.F + dx[i], u.S + dy[i]);
			if (outofmat(v.F, v.S))
				return false;
			if (h[v.F][v.S] == h[x][y] && !ck[v.F][v.S])
			{
				ck[v.F][v.S] = true;
				q.push(v);
			}
			else if (h[v.F][v.S] < h[x][y])
				return false;
			else if (h[v.F][v.S] > h[x][y])
				mn = min(mn, h[v.F][v.S]);
		}
	}

	if (mn == INF)
		return false;
	int rr = 0;
	for (int i = 1; i <= r; ++i)
	for (int j = 1; j <= c; ++j)
	if (ck[i][j])
	{
		rr += mn - h[i][j];
		h[i][j] = mn;
	}

	res += rr;
	if (!rr)
		return false;
	else
		return true;
}

bool proc()
{
	for (int i = 1; i <= r; ++i)
	for (int j = 1; j <= c; ++j)
	if (bfs(i, j))
		return true;
	return false;
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d %d", &r, &c);

		for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			scanf("%d", &h[i][j]);

		res = 0;
		while (proc());

		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}