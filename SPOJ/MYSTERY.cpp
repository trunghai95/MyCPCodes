#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 20122007;
ll a, i;

ll modPow(ll x, ll y) {
	if (y == 0)
		return 1;

	ll res = modPow(x, y>>1);
	res = res*res % MODD;

	if (y&1)
		res = res*x % MODD;
	return res;
}

int main() {
	scanf("%lld", &a);

	i = 1;

	ll res = 1;
	while (i*i < a) {
		if (a % i == 0) {
			res = res * (modPow(3, i) - 1 + MODD) % MODD;
			res = res * (modPow(3, a/i) - 1 + MODD) % MODD;
		}
		++i;
	}

	if (i*i == a)
		res = res * (modPow(3, i) - 1 + MODD) % MODD;

	printf("%lld\n", res);
	return 0;
}