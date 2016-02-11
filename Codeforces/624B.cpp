#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[30];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a+n);
	reverse(a, a+n);

	ll res = 0, mx = 2e9;

	for (int i = 0; i < n; ++i)
	{
		ll tmp = min(mx, a[i]);
		mx = tmp-1;
		res += tmp;

		if (mx == 0)
			break;
	}

	cout << res;
	return 0;
}