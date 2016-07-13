#include <bits/stdc++.h>

using namespace std;

int n, c, x[100010], test;

bool check(int m)
{
	int cc = 1, last = x[0];

	for (int i = 1; i < n && cc < c; ++i)
	if (x[i] - last >= m)
		++cc, last = x[i];

	return (cc == c);
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &c);

		for (int i = 0; i < n; ++i)
			scanf("%d", x+i);

		sort(x, x+n);

		int lef = 1, rig = 1e9;

		while (lef < rig)
		{
			int mid = (lef + rig) / 2 + 1;

			if (check(mid))
				lef = mid;
			else
				rig = mid - 1;
		}

		printf("%d\n", lef);
	}
	return 0;
}