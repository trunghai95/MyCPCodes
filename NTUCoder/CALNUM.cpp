#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool spec(ll x) {

	ll y = x;
	ll s1 = 0, s2 = 0;
	while (x) {
		ll tmp = x % 10;
		s1 += tmp;
		s2 += tmp*tmp;
		x /= 10;
	}

	if (__gcd(s1, s2) != 1 && (s1&1)) {
		cout << s1 << ' ' << s2 << ' ' << y << '\n';
	}

	return (__gcd(s1, s2) == 1);
}

int main() {

	for (ll i = 1; i <= 1000000; ++i)
		spec(i);
	return 0;
}