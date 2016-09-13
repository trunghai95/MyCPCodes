#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
ll n, a, xorsum;

ll modPow(ll x, ll y) {
	ll res = 1;

	while (y) {
		if (y&1)
			res = res*x % MODD;

		x = x*x % MODD;
		y >>= 1;
	}

	return res;
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a), xorsum ^= a;

	if (xorsum != 0) {
		printf("0\n");
		return 0;
	}

	n = modPow(2, n-1) - 1;
	printf("%lld\n", n);
	return 0;
}