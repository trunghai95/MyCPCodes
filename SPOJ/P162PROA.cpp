#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

ld a, b, x;

int main()
{
	cin >> a >> b >> x;

	ll lef = 0, rig = 2e18;

	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;

		if (a*pow((ld)mid, (ld)1/3) + b*pow((ld)mid, (ld)1/2) < x)
			lef = mid + 1;
		else
			rig = mid;
	}

	cout << lef;
	return 0;
}