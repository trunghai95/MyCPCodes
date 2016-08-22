// not done

#include <bits/stdc++.h>

using namespace std;

struct Flight {
	int s, f, t;
};

bool operator<(const Flight& x, const Flight& y) {
	return x.t < y.t;
}

int n, m, p[510], t[510][510];
Flight f[510];
bool ck[510];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", p+i);

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		scanf("%d", t[i] + j);

	for (int i = 1; i <= m; ++i)
		scanf("%d %d %d", &f[i].s, &f[i].f, &f[i].t);

	sort(f+1, f+1+m);
	int res = 0;

	for (int i = 1; i <= m; ++i) {
		int u = 0;
		for (int j = 1; j < i; ++j)
		if (!ck[j]) {
			int d = f[j].t + t[f[j].s][f[j].f] + p[f[j].f];
			if (f[j].f != f[i].s)
				d += t[f[j].f][f[i].s] + p[f[i].s];

			if (d <= f[i].t) {
				u = j;
				ck[j] = true;
			}
		}

		if (!u)
			++res;
	}

	printf("%d\n", res);
	return 0;
}