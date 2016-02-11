#include <bits/stdc++.h>

using namespace std;

int n, k, a[509][509];

int main()
{
	scanf("%d %d", &n, &k);

	int t = 0;

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j < k; ++j)
		a[i][j] = ++t;

	for (int i = 1; i <= n; ++i)
	for (int j = k; j <= n; ++j)
		a[i][j] = ++t;

	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += a[i][k];

	printf("%d\n", res);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}