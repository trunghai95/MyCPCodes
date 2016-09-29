#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll a, b, c, d, res;

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		res = 0;

		for (ll y = c; y <= d; ++y) {
			ll x = min(y - 1, b);
			res += max(0ll, x - a + 1);
		}

		printf("%lld\n", res);
	}
	return 0;
}