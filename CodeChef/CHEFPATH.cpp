#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll n, m;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld %lld", &n, &m);

		if (n > m) swap(n, m);
		if (n == 1)
		{
			if (m == 2)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else if ((n&1LL) && (m&1LL))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}