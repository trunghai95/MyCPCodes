#include <bits/stdc++.h>

using namespace std;

struct Node {
	vector<int> adj[26];
};

int n, m;
Node node[1010];
double f[1010][210];
char s[210];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d %d %s", &u, &v, s);
		node[u].adj[s[0] - 'A'].push_back(v);
		node[v].adj[s[0] - 'A'].push_back(u);
	}

	scanf("%s", s+1);
	int len = strlen(s+1);

	f[1][0] = 1.0;

	for (int i = 1; i <= len; ++i) {
		f[n][i] = f[n][i-1];
		int p = s[i] - 'A';

		for (int u = 1; u < n; ++u) {
			if (node[u].adj[p].empty()) {
				f[u][i] += f[u][i-1];
			} else {
				int sz = node[u].adj[p].size();
				for (int j = 0; j < sz; ++j) {
					int v = node[u].adj[p][j];
					f[v][i] += f[u][i-1] / sz;
				}
			}
		}
	}

	printf("%.3lf\n", f[n][len] * 100.0);
	return 0;
}