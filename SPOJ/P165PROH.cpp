#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll s1, s2, s3, a, b, c, res;

ll mySqrt(ll x)
{
	ll lef = 0, rig = 10000;

	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;

		if (mid * mid < x)
			lef = mid + 1;
		else
			rig = mid;
	}

	return lef;
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> s1 >> s2 >> s3;
		a = mySqrt(s1*s2/s3);
		b = mySqrt(s2*s3/s1);
		c = mySqrt(s3*s1/s2);
		cout << (a+b+c)*4 << '\n';
	}
	return 0;
}