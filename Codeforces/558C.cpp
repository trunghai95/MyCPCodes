#include <bits/stdc++.h>

using namespace std;

int n, a, visited[100010], cnt[100010], dist[100010], totDist[100010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);

		queue<int> q;
		q.push(a);
		visited[a] = i;
		dist[a] = 0;

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			++cnt[u];
			totDist[u] += dist[u];

			int v = (u >> 1);
			if (visited[v] != i)
				q.push(v), visited[v] = i, dist[v] = dist[u] + 1;
			v = (u << 1);
			if (v <= 100000 && visited[v] != i)
				q.push(v), visited[v] = i, dist[v] = dist[u] + 1;
		}
	}

	int res = 2e9;

	for (int i = 1; i <= 100000; ++i)
	if (cnt[i] == n)
		res = min(res, totDist[i]);

	printf("%d", res);
	return 0;
}