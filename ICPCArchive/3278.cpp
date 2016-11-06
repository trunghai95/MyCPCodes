#include <bits/stdc++.h>

using namespace std;

struct CSA {
	vector<int> towers;
	int val;
};

int n, m, q, a[25], x, t;
CSA csa[15];

int main() {
	int tt = 0;
	while (true) {
		scanf("%d %d", &n, &m);
		if (!n && !m) return 0;

		for (int i = 1; i <= n; ++i) {
			scanf("%d", a+i);
		}

		scanf("%d", &q);
		for (int i = 1; i <= q; ++i) {
			csa[i] = CSA();
			scanf("%d", &t);
			for (int j = 0; j < t; ++j) {
				scanf("%d", &x);
				csa[i].towers.push_back(x);
			}
			scanf("%d", &csa[i].val);
			for (int j = 0; j < t; ++j) {
				a[csa[i].towers[j]] -= csa[i].val;
			}
		}

		int res = 0, resmask = 0;
		for (int mask = (1 << n) - 1; mask >= 0; --mask) {
			if (__builtin_popcount(mask) != m) continue;

			int sum = 0;
			for (int i = 1; i <= q; ++i) {
				for (int j = 0; j < (int)csa[i].towers.size(); ++j) {
					int u = csa[i].towers[j];
					if ((mask >> (n-u)) & 1) {
						sum += csa[i].val;
						break;
					}
				}
			}

			for (int i = 1; i <= n; ++i) {
				if ((mask >> (n-i)) & 1)
					sum += a[i];
			}

			if (sum > res) {
				res = sum;
				resmask = mask;
			}
		}

		printf("Case Number  %d\n", ++tt);
		printf("Number of Customers: %d\n", res);
		printf("Locations recommended:");
		for (int i = 1; i <= n; ++i) {
			if ((resmask >> (n-i)) & 1) {
				printf(" %d", i);
			}
		}
		printf("\n\n");
	}
	return 0;
}