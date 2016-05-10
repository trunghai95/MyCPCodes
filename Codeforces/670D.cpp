#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[100010], b[100010], k;


bool valid(ll m)
{
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
	if (a[i]*m > b[i])
	{
		sum += a[i]*m - b[i];
		if (sum > k)
			return false;
	}
	// printf("%d %lld %lld\n", m, sum, k);
	return true;
}

int main()
{
	scanf("%d %lld", &n, &k);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", a+i);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", b+i);

	ll lef = 0, rig = 2000000010;

	while (lef < rig)
	{
		ll mid = ((lef + rig) / 2);
		// printf("%lld %lld %lld\n", lef, rig, mid);

		if (valid(mid + 1))
			lef = mid + 1;
		else
			rig = mid;
	}

	printf("%lld", lef);
	return 0;
}