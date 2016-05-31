#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calLcm(ll x, ll y) { return x / __gcd(x,y) * y; }

int test, b;
ll n, m[1010];

int main()
{
	b = 1000;
	for (int i = 0; i < b; ++i)
		m[i] = 100000 - i;

	ll lcm = m[0];
	for (int i = 1; i < b; ++i)
		lcm = calLcm(lcm, m[i]);
	ll sum = 0;
	for (int i = 0; i < b; ++i)
		sum += lcm / m[i];

	cout << lcm << ' ' << sum;
	return 0;
}