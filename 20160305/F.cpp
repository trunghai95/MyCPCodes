#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int color;
	bool ck[4];
	Node()
	{
		color = -1;
		memset(ck, 0, sizeof(ck));
	}
};

int test, n, m, u, v, f;
bool e[20][20];
Node a[20];

bool Try(int p)
{
	if (a[p].color >= 0)
		return 1;

	for (int i = 0; i < 4; ++i)
	if (!a[p].ck[i])
	{
		a[p].color = i;
		break;
	}

	if (a[p].color < 0)
		return 0;

	f = max(f, a[p].color);

	for (int i = 0; i < n; ++i)
	if (e[i][p] && a[i].color < 0)
	{
		a[i].ck[a[p].color] = true;
	}

	for (int i = 0; i < n; ++i)
	if (e[i][p] && a[i].color < 0)
	{
		if (!Try(i))
			return 0;
	}

	return 1;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		f = -1;
		memset(e, 0, sizeof(e));

		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v);
			e[u][v] = e[v][u] = true;
		}

		for (int i = 0; i < n; ++i)
			a[i] = Node();

		for (int i = 0; i < n; ++i)
		if (a[i].color < 0)
		{
			if (!Try(i))
			{
				f = -1;
				break;
			}
		}

		if (f >= 0)
			printf("%d\n", f + 1);
		else
			printf("many\n");
	}
	return 0;
}