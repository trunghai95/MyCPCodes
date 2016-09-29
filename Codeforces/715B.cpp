#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define F first
#define S second

const ll INF = 1e18;
int n, m, s, t, prev[1000];;
ll L, w[1000][1000], dist[1000];
bool erased[1000][1000], ck[1000];
vector<int> adj[1000];

void printGraph() {
	printf("YES\n");
	for (int i = 0; i < n; ++i)
	for (int j = i+1; j < n; ++j)
	if (w[i][j] >= 0) {
		if (erased[i][j]) {
			w[i][j] = INF;
		}

		printf("%d %d %lld\n", i, j, w[i][j]);
	}
}

ll dijkstra() {
	priority_queue<pli, vector<pli>, greater<pli> > heap;
	memset(prev, -1, sizeof(prev));
	memset(dist, -1, sizeof(dist));
	memset(ck, 0, sizeof(ck));

	heap.push(pli(0, s));
	dist[s] = 0;

	while (!heap.empty()) {
		int u = heap.top().S;
		heap.pop();

		if (ck[u])
			continue;
		ck[u] = true;
		if (u == t)
			return dist[t];

		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!ck[v] && w[u][v] > 0 
				&& (dist[v] == -1 || dist[u] + w[u][v] < dist[v])) {
				dist[v] = dist[u] + w[u][v];
				heap.push(pli(dist[v], v));
				prev[v] = u;
			}
		}
	}

	return -1;
}

int main() {
	memset(w, -1, sizeof(w));
	scanf("%d %d %lld %d %d", &n, &m, &L, &s, &t);

	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		scanf("%lld", &w[u][v]);
		w[v][u] = w[u][v];
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (!w[u][v]) {
			erased[u][v] = erased[v][u] = true;
		}
	}

	ll L1 = dijkstra();
	if (L1 < L && L1 >= 0) {
		printf("NO\n");
		return 0;
	} else if (L1 == L) {
		printGraph();
		return 0;
	}

	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
	if (w[i][j] == 0)
		w[i][j] = w[j][i] = 1;

	L1 = dijkstra();
	if (L1 > L || L1 < 0) {
		printf("NO\n");
		return 0;
	} else if (L1 == L) {
		memset(erased, 0, sizeof(erased));
		printGraph();
	} else {
		int u = t;
		while (prev[u] != -1) {
			int v = prev[u];
			if (erased[u][v]) {
				erased[u][v] = erased[v][u] = false;
				w[u][v] += L - L1;
				w[v][u] += L - L1;
				L1 = L;
			}
			u = prev[u];
		}
		printGraph();
	}

	return 0;
}