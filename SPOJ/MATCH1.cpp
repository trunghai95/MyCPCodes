#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int n1, n2, dist[MAXN+10], pairU[MAXN+10], pairV[MAXN+10], u, v;
vector<int> adj[MAXN+10];

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
	int res = 0;

	memset(pairU, -1, sizeof(pairU));
	memset(pairV, -1, sizeof(pairV));

	while (bfs()) {
		for (int u = 1; u <= n1; ++u)
		if (pairU[u] == -1 && dfs(u))
			++res;
	}

	return res;
}

int main() {
	scanf("%d %d", &n1, &n2);

	while (scanf("%d %d", &u, &v) != EOF) {
		adj[u].push_back(v);
	}

	printf("%d\n", maxMatching());
	for (int i = 1; i <= n1; ++i)
	if (pairU[i] != -1)
		printf("%d %d\n", i, pairU[i]);
	return 0;
}