#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main()
{
	cin >> n;

	ll lef = 0, rig = 1e8;

	while (lef < rig - 1)
	{
		ll mid = (lef + rig) >> 1;

		if (mid*(mid+1)/2 > n)
			rig = mid - 1;
		else
			lef = mid;
	}

	// cout << lef << ' ' << rig << '\n';
	if (rig*(rig+1)/2 < n)
		cout << n - rig*(rig+1)/2;
	else if (rig*(rig+1)/2 == n)
		cout << rig;
	else if (lef*(lef+1)/2 < n)
		cout << n - lef*(lef+1)/2;
	else
		cout << lef;
	return 0;
}