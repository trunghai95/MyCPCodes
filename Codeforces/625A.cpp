#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b, c;

ll solve1()
{
	// cout << n/a + (n%a >= b?(n%a - b) / (b - c) + 1:0) << '\n';
	return n/a + (n%a >= b?(n%a - b) / (b - c) + 1:0);
}

ll solve2()
{
	ll tmp, res;
	if (n >= b)
	{
		res = (n - b) / (b - c);
		tmp = n - res * (b - c);
		++res;
		tmp -= b - c;
	}
	else
		tmp = n, res = 0;

	// cout << tmp << ' ' << res << '\n';
	return res + tmp / a;
}

int main()
{
	cin >> n >> a >> b >> c;
	cout << max(solve1(), solve2());
	return 0;
}