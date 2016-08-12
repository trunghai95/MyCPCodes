#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u, v, w;
	Edge(): u(0), v(0), w(0) {}
};

bool operator<(Edge x, Edge y) { return x.w < y.w; }

int test, n, m, a, p[100010], cnt, res, cost, rescnt, rk[100010];
Edge e[100010];

int find(int x)
{
	return (p[x] == x) ? x : (p[x] = find(p[x]));
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (rk[x] > rk[y])
		swap(x, y);

	p[x] = y;
	rk[y] += rk[x];
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		memset(rk, 0, sizeof(rk));
		scanf("%d %d %d", &n, &m, &a);

		for (int i = 1; i <= n; ++i)
			p[i] = i;

		for (int i = 0; i < m; ++i)
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

		sort(e, e+m);

		cnt = n, rescnt = n, res = n*a, cost = 0;

		for (int i = 0; i < m; ++i)
		{
			if (find(e[i].u) == find(e[i].v))
				continue;

			cost += e[i].w;
			join(e[i].u, e[i].v);
			--cnt;
			int tmp = cost + cnt*a;
			if (tmp < res)
				res = tmp, rescnt = cnt;
		}

		printf("Case %d: %d %d\n", tt, res, rescnt);
	}
	return 0;
}