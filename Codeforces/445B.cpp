#include <bits/stdc++.h>

using namespace std;

int n, m, p[100], cnt[100], u, v;

int find(int x)
{
	return (p[x] == x) ? x : (p[x] = find(p[x]));
}

void join(int x, int y)
{
	p[find(x)] = find(y);
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		p[i] = i;

	while (m--)
	{
		scanf("%d %d", &u, &v);
		join(u, v);
	}

	for (int i = 1; i <= n; ++i)
		++cnt[find(i)];

	long long res = 1;

	for (int i = 1; i <= n; ++i)
	if (cnt[i] > 1)
		res *= (1LL << (cnt[i] - 1));

	printf("%lld\n", res);
	return 0;
}