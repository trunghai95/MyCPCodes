#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int INF = 2e9;
int test, n, e[MAXN][MAXN], f, prev[MAXN];
vector<int> adj[MAXN];

void bfs() {
	memset(prev, -1, sizeof(prev));
	queue<int> q;

	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == n) {
			break;
		}

		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			if (e[u][v] > 0 && prev[v] == -1) {
				q.push(v);
				prev[v] = u;
			}
		}
	}
}

void augment(int u, int minEdge) {
	if (u == 1) {
		f = minEdge;
		return;
	}

	if (prev[u] != -1) {
		int v = prev[u];
		augment(v, min(minEdge, e[v][u]));
		e[v][u] -= f;
		e[u][v] += f;
	}
}

int maxFlow() {
	int mf = 0;

	while (true) {
		bfs();
		f = 0;
		augment(n, INF);
		if (!f) {
			break;
		}
		mf += f;
	}

	return mf;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		memset(e, 0, sizeof(e));
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		for (int i = 1, cnt, x; i < n; ++i) {
			scanf("%d", &cnt);
			while (cnt --> 0) {
				scanf("%d", &x);
				adj[i].push_back(x);
				adj[x].push_back(i);
				if (i == 1 || x == n)
					e[i][x] = 1;
				else
					e[i][x] = 1000;
			}
		}

		printf("%d\n", maxFlow());
	}
	return 0;
}