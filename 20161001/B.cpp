#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll test, r, s, x, y, w;
ll gt[21];

ll power(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y&1) {
			res *= x;
		}
		x = x*x;
		y >>= 1;
	}
	return res;
}

int main() {

	gt[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		gt[i] = gt[i-1] * i;
	}

	scanf("%lld", &test);

	while (test --> 0) {
		scanf("%lld %lld %lld %lld %lld", &r, &s, &x, &y, &w);
		ll res = 0;

		for (int i = x; i <= y; ++i) {
			ll tmp = gt[y] / gt[i] / gt[y-i] * power(s - r + 1, i) * power(r - 1, y-i);
			res += tmp;
		}

		res *= w;
		if (res > power(s, y)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}