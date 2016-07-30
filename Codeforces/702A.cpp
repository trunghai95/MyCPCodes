#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	int lef = 0, rig = -1, res = 1;

	while (lef < n)
	{
		rig = lef + 1;
		while (rig < n && a[rig] > a[rig - 1])
			++rig;
		--rig;
		res = max(res, rig - lef + 1);
		lef = rig + 1;
	}

	printf("%d\n", res);
	return 0;
}