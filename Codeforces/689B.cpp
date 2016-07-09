#include <bits/stdc++.h>

using namespace std;

int n, a[200010], dist[200010];

int main()
{
	scanf("%d", &n);

	memset(dist, -1, sizeof(dist));

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (u < n && dist[u+1] == -1)
			q.push(u+1), dist[u+1] = dist[u] + 1;

		if (u > 1 && dist[u-1] == -1)
			q.push(u-1), dist[u-1] = dist[u] + 1;

		if (dist[a[u]] == -1)
			q.push(a[u]), dist[a[u]] = dist[u] + 1;
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", dist[i]);
	return 0;
}