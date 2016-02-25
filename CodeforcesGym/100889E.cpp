#include <bits/stdc++.h>

using namespace std;

int test, n, m;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &m);

		bool f = false;

		for (int i = 0, u, v; i < m; ++i)
		{
			scanf("%d %d", &u, &v);

			if ((u == 1 && v == n) && !f)
			{
				f = true;
				printf("Jorah Mormont\n");
			}
		}

		if (!f)
			printf("Khal Drogo\n");
	}
	return 0;
}