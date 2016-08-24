#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, w;

	bool operator<(const Edge& e) const {
		return this->w < e.w;
	}
};

int n, m, p[1010], rk[1010], res;
Edge e[10010];

int find(int x) {
	return (x == p[x]) ? x : (p[x] = find(p[x]));
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return false;

	if (rk[x] > rk[y])
		swap(x, y);

	p[x] = y;
	rk[y] += rk[x];
	return true;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		p[i] = i, rk[i] = 1;

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}

	sort(e, e+m);

	for (int i = 0; i < m; ++i)
	if (join(e[i].u, e[i].v)) {
		res = e[i].w;
	}

	printf("%d\n", res);
	return 0;
}