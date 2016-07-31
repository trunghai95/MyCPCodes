#include <bits/stdc++.h>

using namespace std;

int test, n, cnt[200], k;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &k);
		memset(cnt, 0, sizeof(cnt));

		for (int i = 1, x; i <= n; ++i)
		{
			scanf("%d", &x);
			if (x == i)
				cnt[x] = -2e9;
			else
				++cnt[x];
		}

		int res = 0;
		for (int i = 1; i <= n; ++i)
			res += (cnt[i] >= k);

		printf("%d\n", res);
	}
	return 0;
}