#include <bits/stdc++.h>

using namespace std;

int n, a[100010], cnt[100010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	int lef = 1, rig = 1, mn = a[1], mx = a[1], res = 1;
	cnt[a[1]] = 1;

	while (++rig <= n)
	{
		++cnt[a[rig]];
		mx = max(mx, a[rig]);
		mn = min(mn, a[rig]);

		while (mx - mn > 1)
		{
			--cnt[a[lef]];
			++lef;
			while (!cnt[mn]) ++mn;
			while (!cnt[mx]) --mx;
		}

		res = max(res, rig - lef + 1);
	}

	printf("%d", res);
	return 0;
}