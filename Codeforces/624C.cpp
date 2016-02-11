#include <bits/stdc++.h>

using namespace std;

int n, m;
bool e[510][510];
char s[510];
int deg[510];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		e[u][v] = e[v][u] = true;
		++deg[u], ++deg[v];
	}

	for (int i = 1; i <= n; ++i)
	if (deg[i] == n-1)
		s[i] = 'b';

	for (int i = 1; i <= n; ++i)
	if (s[i] != 'b')
	{
		s[i] = 'a';
		for (int j = i+1; j <= n; ++j)
		if (s[j] != 'b')
		{
			if (e[i][j])
				s[j] = 'a';
			else
				s[j] = 'c';
		}

		break;
	}

	for (int i = 1; i <= n; ++i)
	for (int j = i + 1; j <= n; ++j)
	{
		if ((!e[i][j] && abs(s[i] - s[j]) != 2)
			|| (e[i][j] && abs(s[i] - s[j]) == 2))
		{
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n%s\n", s+1);
	return 0;
}