#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const ll MAXN = 1000009;

int n;
ll a[MAXN], pow2[MAXN], coe[MAXN];

int main() {
	pow2[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		pow2[i] = pow2[i-1] * 2 % MODD;
	}

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
	}

	coe[1] = coe[n] = (pow2[n] - 1 + MODD) % MODD;
	for (int i = 2; i <= (n+1)/2; ++i) {
		int j = n - i + 1;
		coe[i] = coe[j] = (coe[i-1] + pow2[n-i] - pow2[i-2] + MODD) % MODD;
	}

	ll res = 0;

	for (int i = 1; i <= n; ++i) {
		res = (res + a[i] * coe[i]) % MODD;
	}

	printf("%lld\n", res);
	return 0;
}