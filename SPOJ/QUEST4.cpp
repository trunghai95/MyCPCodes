#include <bits/stdc++.h>

using namespace std;

const int MAXN = 120;
int test, n, pairU[120], pairV[120], dist[120];
vector<int> adj[120];

bool bfs() {
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	int mx = -1;

	for (int u = 0; u < 120; ++u)
	if (pairU[u] == -1)
		q.push(u), dist[u] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (mx != -1 && dist[u] >= mx) continue;

		for (int i = 0; i < (int)adj[u].size(); ++i) {
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
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
			pairU[u] = v;
			pairV[v] = u;
			return true;
		}
	}

	dist[u] = -1;
	return false;
}

int maxMatching() {
	memset(pairU, -1, sizeof(pairU));
	memset(pairV, -1, sizeof(pairV));
	int res = 0;

	while (bfs()) {
		for (int u = 0; u < 120; ++u)
		if (pairU[u] == -1 && dfs(u))
			++res;
	}

	return res;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		for (int i = 0; i < 120; ++i)
			adj[i].clear();

		for (int i = 0, u, v; i < n; ++i) {
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		printf("%d\n", maxMatching());
	}
	return 0;
}