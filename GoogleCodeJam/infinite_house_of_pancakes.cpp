#include <bits/stdc++.h>

using namespace std;

int test, d, p[2000];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d", &d);
		for (int i = 0; i < d; ++i)
			scanf("%d", p+i);

		int res = 1000;

		for (int x = 1; x <= 1000; ++x)
		{
			int tmp = x;
			for (int i = 0; i < d; ++i)
				tmp += (p[i] - 1) / x;

			res = min(res, tmp);
		}
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}