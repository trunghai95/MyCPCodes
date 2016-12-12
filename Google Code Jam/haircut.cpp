#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 5e18;
int test, n, p;
ll m[1010];

ll count(ll t) {
	if (t <= 0) return 0;
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		res += (t - 1) / m[i] + 1;
		if (res >= p) return INF;
	}
	return res;
}

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		printf("Case #%d: ", tt);
		scanf("%d %d", &n, &p);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", m+i);

		if (p <= n) {
			printf("%d\n", p);
			continue;
		}

		ll lo = 1, hi = INF;

		while (lo < hi) {
			ll mid = (lo + hi) / 2;
			ll tmp = count(mid);
			if (tmp < p) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}

		--lo;
		p -= count(lo);
		for (int i = 1; i <= n; ++i) {
			if (lo % m[i] == 0) {
				--p;
				if (!p) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
