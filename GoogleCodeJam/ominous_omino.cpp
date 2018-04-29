//wa
#include <bits/stdc++.h>

using namespace std;

int test, x, r, c;

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d %d %d", &x, &r, &c);

		if (x >= 7 || (r*c) % x)
		{
			printf("Case #%d: RICHARD\n", tt);
			continue;
		}

		if (r > c) swap(r, c);

		int m1 = (x + 1) / 2, m2 = x + 1 - m1;

		if (r < m1 || c < m2 || r <= x - 2)
		{
			printf("Case #%d: RICHARD\n", tt);
			continue;
		}

		printf("Case #%d: GABRIEL\n", tt);
	}
	return 0;
}