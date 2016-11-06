#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int test, n, a[202][202], x[202], y[202], cnt[2], cur[2];

int dist(int u, int v) {
	return (x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v]);
}

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", x+i);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", y+i);
		}

		map<int, pii> mp;
		cnt[0] = cnt[1] = 0;
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%d", a[i] + j);

			if (i != j) {
				if (a[i][j]) {
					++mp[dist(i, j)].F;
					++cnt[1];
				} else {
					++mp[dist(i, j)].S;
				}
			}
		}

		int res = 0, falseMin = cnt[1];

		for (map<int,pii>::iterator it = mp.begin(); it != mp.end(); ++it) {
			cnt[0] += it->S.S;
			cnt[1] -= it->S.F;

			if (cnt[0] + cnt[1] < falseMin) {
				falseMin = cnt[0] + cnt[1];
				res = it->F;
			}
		}

		printf("Case #%d: %d %d\n", tt, res, falseMin);
	}
	return 0;
}