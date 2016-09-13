#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
int test;
ll n;

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
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%lld", &n);
		n = modPow(2, n-1);
		n = modPow(n, MODD - 2);
		printf("%lld\n", n);
	}
	return 0;
}