#include <bits/stdc++.h>

using namespace std;

int n, a, b, ab, x[2], xx, yy;

int main()
{
	cin >> n >> a >> b;
	ab = a*b;
	x[0] = n/2 + (n&1), x[1] = n/2;
	xx = ab/2 + (ab&1), yy = ab/2;

	if (x[0] > xx || x[1] > yy)
	{
		cout << -1;
		return 0;
	}

	x[0] = 1, x[1] = 2;
	xx = 0;

	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			if (x[xx] <= n)
				cout << x[xx] << ' ';
			else
				cout << "0 ";
			x[xx] += 2;
			xx = 1 - xx;
		}
		cout << '\n';
		if (!(b&1))
			xx = 1 - xx;
	}
	return 0;
}