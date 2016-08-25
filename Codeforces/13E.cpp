#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int MAXSQRT = 316;

int n, q, a[MAXN+500], next[MAXN+500], dist[MAXN+500], u, v, type;

void findnext(int p) {
	if (dist[p] != -1)
		return;

	if (p + a[p] >= n) {
		dist[p] = 1;
		return;
	}

	if ((p+a[p])/MAXSQRT > p/MAXSQRT) {
		next[p] = p+a[p];
		dist[p] = 1;
		return;
	}

	findnext(p + a[p]);
	next[p] = next[p+a[p]];
	dist[p] = dist[p+a[p]] + 1;
}

int main() {
	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	memset(next, -1, sizeof(next));
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n; ++i)
	if (dist[i] == -1)
		findnext(i);

	while (q --> 0) {
		scanf("%d %d", &type, &u);
		--u;

		if (type) {
			int res = 0;
			while (next[u] != -1) {
				res += dist[u];
				u = next[u];
			}

			while (u + a[u] < n) {
				++res;
				u += a[u];
			}

			printf("%d %d\n", u+1, res+1);

		} else {
			scanf("%d", &v);
			a[u] = v;
			int zone = u/MAXSQRT;
			memset(next+zone*MAXSQRT, -1, MAXSQRT*sizeof(int));
			memset(dist+zone*MAXSQRT, -1, MAXSQRT*sizeof(int));
			for (int i = zone*MAXSQRT; i < min(n, (zone+1)*MAXSQRT); ++i)
			if (dist[i] == -1)
				findnext(i);
		}
	}
	return 0;
}