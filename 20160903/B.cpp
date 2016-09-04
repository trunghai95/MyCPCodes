#include <bits/stdc++.h>

using namespace std;

int test, n1, n2, pairU[50010], pairV[100010], dist[50010];
vector<int> adj[50010];

bool bfs() {
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	int mx = -1;

	for (int u = 0; u < n1; ++u)
	if (pairU[u] == -1)
		q.push(u), dist[u] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (mx != -1 && dist[u] >= mx) continue;

		for (int i = 0; i < (int) adj[u].size(); ++i) {
			int v = adj[u][i];
			if (pairV[v] == -1) mx = dist[u];
			else if (dist[pairV[v]] == -1) {
				q.push(pairV[v]);
				dist[pairV[v]] = dist[u] + 1;
			}
		}
	}

	return (mx != -1);
}

bool dfs(int u) {
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
			pairV[v] = u;
			pairU[u] = v;
			return true;
		}
	}
	dist[u] = -1;
	return false;
}

int maxMatching() {
	int res = 0;
	memset(pairU, -1, sizeof(pairU));
	memset(pairV, -1, sizeof(pairV));

	while (bfs()) {
		for (int u = 0; u < n1; ++u)
		if (pairU[u] == -1 && dfs(u))
			++res;
	}

	return res;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n1);
		n2 = n1*2;
		for (int i = 0, p, q; i < n1; ++i) {
			scanf("%d %d", &p, &q);
			adj[i].clear();

			--p, --q;

			adj[i].push_back(p);
			if (p != q)
				adj[i].push_back(q);
		}

		if (maxMatching() == n1)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	return 0;
}