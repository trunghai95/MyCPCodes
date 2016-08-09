#include <bits/stdc++.h>

using namespace std;

int test, n, m, p[30010], cnt[30010], u, v;

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
	scanf("%d", &test);

	while (test--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; ++i)
			p[i] = i;

		while (m--)
		{
			scanf("%d %d", &u, &v);
			join(u, v);
		}

		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			int tmp = find(i);
			res = max(res, ++cnt[tmp]);
		}

		printf("%d\n", res);
	}
	return 0;
}