#include <bits/stdc++.h>

using namespace std;

int n, m, p[111], rank[111], u, v, cnt;

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

	--cnt;
	if (rank[x] > rank[y])
		swap(x,y);
	p[x] = y;
	rank[y] += rank[x];
}

int main()
{
	scanf("%d %d", &n, &m);

	if (n != m)
	{
		printf("NO\n");
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		p[i] = i;

	cnt = n;

	while (m--)
	{
		scanf("%d %d", &u, &v);
		join(u, v);
	}

	if (cnt == 1)
		printf("FHTAGN!\n");
	else
		printf("NO\n");
	return 0;
}