#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[11], b[11];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%lld %lld", a+i, b+i);

	int nn = (1 << n);

	ll res = 1e18;

	for (int i = 1; i < nn; ++i) {
		ll aa = 1, bb = 0;
		for (int j = 0; j < n; ++j)
		if ((i >> j) & 1)
			aa *= a[j], bb += b[j];

		res = min(res, abs(aa-bb));
	}

	printf("%lld\n", res);
	return 0;
}