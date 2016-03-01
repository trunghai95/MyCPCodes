#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, e[1009][1009];
ll a[1009];

int Try(int u, int v)
{
	bool ck[1009];
	memset(ck, 0, sizeof(ck));
	ck[u] = ck[v] = true;
	ll x = a[u], y = a[v];
	int res = 2;

	while (1)
	{
		ll tmp = x + y;
		int p = lower_bound(a+1, a+n+1, tmp) - a;

		while (p <= n && a[p] == tmp && ck[p])
			++p;

		if (p > n || a[p] != tmp)
			break;
		ck[p] = true;
		x = y;
		y = tmp;
		++res;
	}

	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a+i);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	{
		int p = lower_bound(a+1, a+n+1, a[i] + a[j]) - a;
		if (p > n)
			e[i][j] = e[j][i] = -1;
		else
			e[i][j] = e[j][i] = p;
	}

	int res = 2;
	for (int i = 1; i < n && res < n; ++i)
	for (int j = i + 1; j <= n && res < n; ++j)
	if (e[i][j] != -1)
		res = max(res, max(Try(i, j), Try(j, i)));

	printf("%d", res);
	return 0;
}