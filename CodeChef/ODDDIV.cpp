#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, l, r;
ll f[100010];

void init()
{
	for (int i = 1; i <= 100000; i += 2)
	{
		for (int j = i; j <= 100000; j += i)
			f[j] += i;
	}
}

int main()
{
	init();

	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &l, &r);
		ll res = 0;
		for (int i = l; i <= r; ++i)
			res += f[i];
		printf("%lld\n", res);
	}
	return 0;
}