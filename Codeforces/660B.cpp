#include <bits/stdc++.h>

using namespace std;

vector<int> v[4];
int n, m, p[4];

int next[4] = { 2, 0, 3, 1};

int main()
{
	scanf("%d %d", &n, &m);

	int cur = 0;

	for (int i = 1; i <= min(m, n*2); ++i)
	{
		v[cur].push_back(i);
		cur = 3 - cur;
	}

	cur = 1;

	if (m > n*2)
	for (int i = n*2 + 1; i <= min(m, n*4); ++i)
	{
		v[cur].push_back(i);
		cur = 3 - cur;
	}

	cur = 1;

	for (int i = 1; i <= n*4; ++i)
	{
		if (p[cur] < v[cur].size())
			printf("%d ", v[cur][p[cur]]);
		++p[cur];
		cur = next[cur];
	}
	return 0;
}