#include <bits/stdc++.h>

using namespace std;

int n, k, a[100010], cnt[100010], cur;

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	if (k == 1)
	{
		printf("1 1");
		return 0;
	}

	int lef = 1, rig = 0;
	
	while (cur < k && ++rig <= n)
	{
		if (++cnt[a[rig]] == 1)
			++cur;
	}

	while (cnt[a[lef]] > 1)
	{
		--cnt[a[lef]];
		++lef;
	}

	if (rig > n)
		printf("-1 -1");
	else
		printf("%d %d", lef, rig);

	return 0;
}