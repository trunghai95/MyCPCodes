#include <bits/stdc++.h>

using namespace std;

int test, n, a[1009], res;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);
		sort(a, a+n);

		res = 0;
		for (int i = 0; i < n/2; ++i)
		{
			res += a[n-i-1] - a[i];
		}

		printf("%d\n", res);
	}
	return 0;
}