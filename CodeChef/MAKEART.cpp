#include <bits/stdc++.h>

using namespace std;

int test, n, c[100010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", c+i);

		bool res = false;
		for (int i = 1; i <= n-2; ++i)
		if (c[i] == c[i+1] && c[i] == c[i+2])
		{
			res = true;
			break;
		}

		if (res)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}