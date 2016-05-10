#include <bits/stdc++.h>

using namespace std;

int n, a[500010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	if (n == 1)
	{
		printf("1");
		return 0;
	}

	sort(a+1, a+1+n);
	int res = n;

	int lef = 1, rig = (n+3) / 2;

	while (rig <= n)
	{
		if (a[lef]*2 <= a[rig])
			++lef, --res;
		++rig;
	}

	printf("%d", res);
	return 0;
}