#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b, p, q, cnta, cntb, cntab, res;

ll gcd(ll x, ll y)
{
	if (!x) return y;
	return gcd(y%x, x);
}

int main()
{
	cin >> n >> a >> b >> p >> q;
	cntab = n / ((a*b) / gcd(a, b));
	cnta = n / a - cntab;
	cntb = n / b - cntab;

	res = cnta * p + cntb * q + max(p, q) * cntab;
	cout << res;
	return 0;
}