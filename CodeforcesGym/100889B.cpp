#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n;
ll a[100010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
			scanf("%lld", a+i);

		int lef = 1, rig = n, lastlef = 0, lastrig = n+1, res = 0;
		ll lefsum = a[1], rigsum = a[n];

		while (lef < rig)
		{
			if (lefsum == rigsum)
			{
				res += lef - lastlef + lastrig - rig - 2;
				lastrig = rig;
				lastlef = lef;
				lefsum += a[++lef];
				rigsum += a[--rig];
			}
			else if (lefsum < rigsum)
				lefsum += a[++lef];
			else
				rigsum += a[--rig];
		}

		res += max(lastrig - lastlef - 2, 0);

		printf("%d\n", res);
	}
	return 0;
}