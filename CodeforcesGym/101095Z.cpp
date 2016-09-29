#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d, k, n;

int main() {
	scanf("%lld %lld %lld", &d, &k, &n);

	ll res = k-1;
	if (k&1) {
		res += n*2;
	} else {
		res -= n*2;
		res += d*1000000000;
	}
	res %= d;
	ll res2 = (res + 2) % d;

	if (res == 0) res = d;
	if (res2 == 0) res2 = d;

	printf("%lld %lld\n", res2, res);
	return 0;
}