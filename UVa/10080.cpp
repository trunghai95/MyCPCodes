#include <bits/stdc++.h>

using namespace std;

int n, m, s, V, pairU[111], pairV[111], dist[111];
double x[111], y[111], tx, ty;
vector<int> adj[111];

bool bfs() {
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	int mx = -1;

	for (int u = 0; u < n; ++u)
	if (pairU[u] == -1)
		q.push(u), dist[u] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (mx != -1 && dist[u] >= mx) continue;

		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			if (pairV[v] == -1) {
				mx = dist[u];
			} else if (dist[pairV[v]] == -1) {
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
		for (int u = 0; u < n; ++u)
		if (pairU[u] == -1 && dfs(u))
			++res;
	}
	return res;
}

int main() {
	while (scanf("%d %d %d %d", &n, &m, &s, &V) != EOF) {
		for (int i = 0; i < n; ++i)
			adj[i].clear(), scanf("%lf %lf", x+i, y+i);

		for (int v = 0; v < m; ++v) {
			scanf("%lf %lf", &tx, &ty);
			for (int u = 0; u < n; ++u) {
				if ((tx-x[u])*(tx-x[u]) + (ty-y[u])*(ty-y[u]) <= s*s*V*V) {
					adj[u].push_back(v);
				}
			}
		}

		printf("%d\n", n - maxMatching());
	}
	return 0;
}