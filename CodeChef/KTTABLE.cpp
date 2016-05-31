#include <bits/stdc++.h>

using namespace std;

int test, n, a[10010], b, res;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
			scanf("%d", a+i);
		res = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &b);
			if (b <= a[i] - a[i-1])
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}