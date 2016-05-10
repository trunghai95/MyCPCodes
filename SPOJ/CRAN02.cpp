#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n, a, sum;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		map<int,ll> cnt;
		cnt[0] = 1;
		sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a);
			sum += a;
			++cnt[sum];
		}

		// for (int i = 1; i <= n; ++i)
		// 	printf("%d ", a[i]);
		// printf("\n");

		ll res = 0;

		for (map<int,ll>::iterator it = cnt.begin(); it != cnt.end(); ++it)
			res += it->second * (it->second - 1) / 2;

		printf("%lld\n", res);
	}
	return 0;
}