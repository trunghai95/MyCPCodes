#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, x;
ll a[200010], pre[200010], suf[200010];

int main()
{
	scanf("%d %d %d", &n, &k, &x);
	ll xx = 1;
	for (int i = 0; i < k; ++i)
		xx *= x;

	for (int i = 1; i <= n; ++i)
		scanf("%lld", a+i), pre[i] = pre[i-1] | a[i];

	for (int i = n; i >= 1; --i)
		suf[i] = suf[i+1] | a[i];

	ll res = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll tmp = a[i] * xx;
		res = max(res, tmp | pre[i-1] | suf[i+1]);
	}

	printf("%lld", res);
	return 0;
}