#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

int test;
ll a, b, n, k, powA[100010], powB[100010], res, cntA[100010], cntB[100010];

ll modPow(ll x, ll y) {
	if (y == 0)
		return 1LL;

	ll res = modPow(x, y>>1);
	res = res*res % k;
	if (y&1)
		res = res*x % k;

	return res;
}

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		scanf("%lld %lld %lld %lld", &a, &b, &n, &k);
		ll res = 0;

		for (ll i = 0; i < k; ++i) {
			powA[i] = modPow(i, a);
			cntA[powA[i]] = (cntA[powA[i]] + max(0LL, n - i) / k + (i != 0)) % MODD;

			powB[i] = modPow(i, b);
			cntB[powB[i]] = (cntB[powB[i]] + max(0LL, n - i) / k + (i != 0)) % MODD;

			if ((powA[i] + powB[i]) % k == 0)
				res = (res - max(0LL, n - i) / k - (i != 0) + MODD) % MODD;
		}

		res = (res + cntA[0] * cntB[0]) % MODD;
		for (ll i = 1; i < k; ++i) {
			res = (res + cntA[i] * cntB[k-i]) % MODD;
		}

		printf("Case #%d: %lld\n", tt, res);
	}
	return 0;
}