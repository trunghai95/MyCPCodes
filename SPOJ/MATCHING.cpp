#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000;
const int MAXM = 150000;

int n1, n2, m, pairU[MAXN+5], pairV[MAXN+5], dist[MAXN+5];
vector<int> adj[MAXN+5];

bool bfs() {
	memset(dist, -1, sizeof(dist));
	queue<int> q;

	for (int u = 1; u <= n1; ++u)
	if (pairU[u] == -1)
		q.push(u), dist[u] = 0;

	int mx = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (mx != -1 && dist[u] >= mx)
			continue;

		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			if (pairV[v] == -1)
				mx = dist[u];
			else if (dist[pairV[v]] == -1) {
				dist[pairV[v]] = dist[u] + 1;
				q.push(pairV[v]);
			}
		}
	}

	return (mx != -1);
}

bool dfs(int u) {
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (pairV[v] == -1
			|| (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
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

	int cnt = 0;

	while (bfs()) {
		for (int u = 1; u <= n1; ++u)
		if (pairU[u] == -1 && dfs(u))
			++cnt;
	}

	return cnt;
}

int main() {
	scanf("%d %d %d", &n1, &n2, &m);

	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}

	printf("%d\n", maxMatching());
	return 0;
}