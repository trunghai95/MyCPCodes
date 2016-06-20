#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

ll myPow(ll a, ll b)
{
	if (b == 0)
		return 1;
	ll tmp = myPow(a, b>>1);
	tmp = tmp*tmp % MODD;
	if (b&1)
		tmp = tmp*a % MODD;
	return tmp;
}

ll a, b, n, x, res, res2;

int main()
{
	cin >> a >> b >> n >> x;
	ll a_n = myPow(a, n);
	// cout << "a_n = " << a_n << '\n';
	res = a_n * x % MODD;
	// cout << "res = " << res << '\n';

	if (a == 1)
		res2 = b*(n % MODD) % MODD;
	else
	{
		a_n = (a_n - 1 + MODD) % MODD;
		a = (a - 1 + MODD) % MODD;
		res2 = a_n * myPow(a, MODD - 2) % MODD;
		res2 = b * res2 % MODD;
	}
	// cout << "res2 = " << res2 << '\n';

	res = (res + res2) % MODD;

	cout << res;
	return 0;
}