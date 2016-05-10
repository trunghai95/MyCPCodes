#include <bits/stdc++.h>

using namespace std;

int n, t, a[100010];

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	int res = 0;
	int lef = 1, rig = 0, sum = 0;

	while (1)
	{
		while (rig <= n && sum <= t)
		{
			++rig;
			sum += a[rig];
		}

		// printf("%d %d\n", lef, rig);
		res = max(res, rig - lef);

		if (rig > n)
			break;

		while (sum > t)
		{
			sum -= a[lef];
			++lef;
		}
	}

	printf("%d", res);
	return 0;
}