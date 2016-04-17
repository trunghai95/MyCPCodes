#include <bits/stdc++.h>

using namespace std;

int n, k, a[300010];

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	int l = 0, r = 0, resl = 0, resr = 0, cnt = 1 - a[0];
	if (k == 0)
	{
		int r = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (a[i])
				a[i] += a[i-1], r = max(r, a[i]);
		}
		printf("%d\n", r);
		for (int i = 0; i < n; ++i)
			printf("%d ", a[i]?1:0);
		return 0;
	}

	while (1)
	{
		// printf("%d %d %d %d %d\n", l, r, resl, resr, cnt);
		++r;
		if (r == n)
			break;
		if (a[r])
		{
			if (r - l > resr - resl)
				resr = r, resl = l;
		}
		else
		{
			if (++cnt <= k)
			{
				if (r - l > resr - resl)
					resr = r, resl = l;
			}
			else
			{
				while (a[l]) ++l;
				--cnt;
				++l;
			}
		}
	}

	printf("%d\n", resr - resl + 1);
	for (int i = 0; i < resl; ++i)
		printf("%d ", a[i]);
	for (int i = resl; i <= resr; ++i)
		printf("1 ");
	for (int i = resr + 1; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}