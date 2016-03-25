#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n, cnt[100010];
ll a[100010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
			scanf("%lld", a+i);

		cnt[n] = 1;

		for (int i = n - 1; i > 0; --i)
		{
			if (a[i] * a[i+1] < 0)
				cnt[i] = cnt[i+1] + 1;
			else
				cnt[i] = 1;
		}

		for (int i = 1; i <= n; ++i)
			printf("%d ", cnt[i]);
		printf("\n");
	}
	return 0;
}