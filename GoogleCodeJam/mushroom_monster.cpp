#include <bits/stdc++.h>

using namespace std;

int test, n, a[1010];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);

		int res1 = 0, res2 = 0;

		for (int i = 1; i < n; ++i)
			res1 += max(0, a[i-1] - a[i]);

		int rate = 0;
		for (int i = 1; i < n; ++i)
			rate = max(rate, a[i-1] - a[i]);
		for (int i = 1; i < n; ++i)
			res2 += min(rate, a[i-1]);

		printf("Case #%d: %d %d\n", tt, res1, res2);
	}
	return 0;
}