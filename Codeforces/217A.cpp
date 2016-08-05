#include <bits/stdc++.h>

using namespace std;

int n, x[111], y[111], p[111], cnt;
int rank[111];

int find(int u)
{
	return (p[u] == u) ? u : (p[u] = find(p[u]));
}

void join(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return;

	--cnt;
	if (rank[u] > rank[v])
		swap(u, v);
	p[u] = v;
	rank[v] += rank[u];
}

int main()
{
	scanf("%d", &n);
	cnt = n;

	for (int i = 1; i <= n; ++i)
	{
		p[i] = i;
		scanf("%d %d", x+i, y+i);

		for (int j = 1; j < i; ++j)
		if (x[i] == x[j] || y[i] == y[j])
			join(i, j);
	}

	printf("%d\n", cnt - 1);
	return 0;
}