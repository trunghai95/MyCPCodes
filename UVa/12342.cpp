#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll k;

ll solve(ll k) {
	if (k <= 180000) {
		return 0;
	}

	ll res = 0;
	k -= 180000;
	res += 10*min(k, 300000ll);
	if (k <= 300000) {
		return max(2000ll, (res - 1) / 100 + 1);
	}

	k -= 300000;
	res += 15*min(k, 400000ll);
	if (k <= 400000) {
		return max(2000ll, (res - 1) / 100 + 1);
	}

	k -= 400000;
	res += 20*min(k, 300000ll);
	if (k <= 300000) {
		return max(2000ll, (res - 1) / 100 + 1);
	}

	k -= 300000;
	res += 25*k;
	return max(2000ll, (res - 1) / 100 + 1);
}

int main() {

	scanf("%d", &test);

	for (int _ = 1; _ <= test; ++_) {
		scanf("%lld", &k);
		printf("Case %d: %lld\n", _, solve(k));
	}
	return 0;
}