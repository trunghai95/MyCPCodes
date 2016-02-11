#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main()
{
	cin >> n;
	ll lef = 0, rig = 1e9;

	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;
		if (mid*(mid+1) / 2 < n)
			lef = mid + 1;
		else
			rig = mid;
	}

	if (lef*(lef+1) / 2 == n)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}