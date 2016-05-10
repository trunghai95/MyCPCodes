#include <bits/stdc++.h>

using namespace std;

int n, d[100010];
char s[100010];
bool visited[100010];

int main()
{
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", d+i);

	int cur = 1;
	visited[cur] = true;

	while (1)
	{
		if (s[cur] == '>')
			cur += d[cur];
		else
			cur -= d[cur];
		if (cur < 1 || cur > n)
		{
			printf("FINITE");
			return 0;
		}

		if (visited[cur])
		{
			printf("INFINITE");
			return 0;
		}

		visited[cur] = true;
	}
	return 0;
}