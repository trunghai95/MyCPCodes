#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;

ll myPow(ll a, ll b) {
	ll res = 1;

	while (b) {
		if (b&1) {
			res = res*a;
		}
		a = a*a;
		b /= 2;
	}

	return res;
}

int main() {
	scanf("%lld", &n);

	ll res = 0;
	for (int a = 1; a < n; ++a)
	if (n % a == 0) {
		ll tmp = n/a;
		++res;

		int x = 2;
		while (true) {
			if (x + 1 > tmp) break;
			ll k = 1;
			while ((myPow(x, k+1) - 1) / (x - 1) < tmp) {
				++k;
			}
			if ((myPow(x, k+1) - 1) / (x - 1) == tmp) {
				++res;
			}
			++x;
		}
	}

	printf("%lld\n", res);
	return 0;
}