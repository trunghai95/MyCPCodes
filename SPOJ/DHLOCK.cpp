#include <bits/stdc++.h>

using namespace std;

int n, k, a[310], b[310], dif[310];

int main()
{
	scanf("%d %d", &n, &k);
	++k;

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b+i);

	int res = 2e9;

	for (int sh = 0; sh < n; ++sh)
	{
		// printf("sh=%d\n", sh);
		int inc = 2e9;
		for (int i = 0; i < n; ++i)
			dif[i] = (b[(i+sh)%n] - a[i] + k) % k;
		// for (int i = 0; i < n; ++i)
		// 	printf("%d ", dif[i]);
		// printf("\n");
		for (int i = 0; i < n; ++i)
		{
			int cnt = dif[i];
			for (int j = 0; j < n; ++j)
			{
				cnt += (dif[j] - dif[i] + k) % k;
				// printf("%d %d: %d\n", i, j, (dif[i] - dif[j] + k) % k);
			}
			// printf("%d %d: %d\n", i, dif[i], cnt);
			inc = min(inc, cnt);
		}

		res = min(res, inc + sh);
		// printf("%d %d %d\n", sh, res, inc);
	}

	printf("%d", res);
	return 0;
}