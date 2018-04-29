#include <bits/stdc++.h>

using namespace std;

int test, n, cnt[2510];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = n*2 - 1, x; i > 0; --i)
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &x);
			++cnt[x];
		}

		printf("Case #%d:", tt);
		for (int i = 1; i <= 2500; ++i)
		if (cnt[i] & 1)
			printf(" %d", i);
		printf("\n");
	}
	return 0;
}