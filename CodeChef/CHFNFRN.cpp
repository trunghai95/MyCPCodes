#include <bits/stdc++.h>

using namespace std;

int test, n, m, color[1010];
bool e[1010][1010];

bool solve() {
	scanf("%d %d", &n, &m);
	memset(e, 0, sizeof(e));
	memset(color, -1, sizeof(color));

	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		e[u][v] = e[v][u] = true;
	}

	vector<int> adj[1010];

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j < i; ++j)
	if (!e[i][j]) {
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	for (int i = 1; i <= n; ++i)
	if (color[i] == -1) {
		queue<int> q;
		q.push(i);
		color[i] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int j = 0; j < (int)adj[u].size(); ++j) {
				int v = adj[u][j];
				if (color[v] == -1) {
					q.push(v);
					color[v] = 1 - color[u];
				} else if (color[v] == color[u]) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}