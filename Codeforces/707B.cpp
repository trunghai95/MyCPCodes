#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, w;
};

bool operator<(const Edge& x, const Edge& y) {
	return x.w < y.w;
}

int n, m, k;
bool f[100010];
Edge e[100010];

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; ++i)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

	for (int i = 0, x; i < k; ++i)
	{
		scanf("%d", &x);
		f[x] = true;
	}

	sort(e, e+m);

	for (int i = 0; i < m; ++i)
	if (f[e[i].u] != f[e[i].v]) {
		printf("%d\n", e[i].w);
		return 0;
	}

	printf("-1\n");
	return 0;
}