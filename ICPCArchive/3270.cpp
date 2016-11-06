#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
#define F first
#define S second

const double EPS = 1e-9;
int nb, nc, nr, q;
pdd b[60], c[60];
int e[60][60];

double dist(pdd u, pdd v) {
	return (u.F - v.F)*(u.F - v.F) + (u.S - v.S)*(u.S - v.S);
}

int findBTS(pdd pos) {
	double mindis = 2e18;
	int res = -1;

	for (int i = 1; i <= nb; ++i) {
		double dis = dist(pos, b[i]);
		if (dis < mindis) {
			res = i;
			mindis = dis;
		}
	}

	return res;
}

int main() {
	int tt = 0;
	while (true) {
		scanf("%d %d %d %d", &nb, &nc, &nr, &q);
		if (!nb) return 0;

		memset(e, -1, sizeof(e));

		for (int i = 1; i <= nb; ++i) {
			scanf("%lf %lf", &b[i].F, &b[i].S);
		}

		for (int i = 1; i <= nc; ++i) {
			scanf("%lf %lf", &c[i].F, &c[i].S);

		}

		for (int i = 1, u, v; i <= nr; ++i) {
			int w = 0;
			scanf("%d %d", &u, &v);
			if (c[u] > c[v]) swap(u, v);
			pdd pu = c[u];
			pdd pv = c[v];
			int btsu = findBTS(pu);
			int btsv = findBTS(pv);
			while (btsu != btsv) {
				pdd lef = pu, rig = pv;
				while (rig.F - lef.F > EPS && rig.S - lef.S > EPS) {
					pdd mid((lef.F + rig.F) / 2, (lef.S + rig.S) / 2);
					if (findBTS(mid) != btsu) {
						rig = mid;
					} else {
						lef = pdd(mid.F + EPS, mid.S + EPS);
					}
				}

				++w;
				pu = rig;
				btsu = findBTS(pu);
			}

			e[u][v] = e[v][u] = w;
		}

		for (int k = 1; k <= nc; ++k)
		for (int i = 1; i <= nc; ++i)
		for (int j = 1; j <= nc; ++j) {
			if (e[i][k] == -1 || e[j][k] == -1)
				continue;
			if (e[i][j] == -1 || e[i][j] > e[i][k] + e[k][j]) {
				e[i][j] = e[j][i] = e[i][k] + e[k][j];
			}
		}

		printf("Case %d:\n", ++tt);
		while (q --> 0) {
			int u, v;
			scanf("%d %d", &u, &v);
			if (e[u][v] != -1)
				printf("%d\n", e[u][v]);
			else
				printf("Impossible\n");
		}
	}
	return 0;
}