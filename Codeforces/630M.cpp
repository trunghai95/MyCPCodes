#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x;

int main()
{
	cin >> x;
	x = (-x)%360 + 360;
	ll mn = 1000, mnc = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (x >= 360)
			x -= 360;
		ll tt = min(x, 360-x);
		if (tt < mn)
		{
			mn = tt;
			mnc = i;
		}

		x += 90;
	}

	cout << mnc;
	return 0;
}