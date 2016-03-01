#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll s, x, res;

int main()
{
	cin >> s >> x;
	ll ss = s, xx = x;

	res = 1;

	while (s || x)
	{
		if ((s&1) != (x&1) || s < 0)
		{
			cout << 0;
			return 0;
		}

		if ((s&1) && (x&1))
		{
			res *= 2;
			s >>= 1;
			x >>= 1;
		}
		else
		{
			s >>= 1;
			x >>= 1;
			if ((s&1) != (x&1))
				s -= 1;
		}
	}

	if (ss == xx)
		res -= 2;

	cout << res;
	return 0;
}