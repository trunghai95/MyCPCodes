#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lef, rig, lo, hi, mid, midBound;
const ll INF = 1e18;
const ll BOUND = 1e17;

ll digPro(ll x) {
	ll res = 1;
	while (x) {
		res *= (x % 10);
		x /= 10;
	}
	return res;
}

ll cal(ll x) {
	ll tmp = digPro(x);
	if (tmp > INF/x)
		return INF;
	return tmp*x;
}

int main() {
	for (ll i = 1; i <= 2000; ++i)
		cout << i << ' ' << cal(i) << '\n';
	return 0;
}