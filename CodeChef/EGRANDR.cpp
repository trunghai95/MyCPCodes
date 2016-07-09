#include <bits/stdc++.h>

using namespace std;

int test, n, a, sum;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		sum = 0;
		bool f2 = false, f5 = false;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			sum += a;
			if (a == 2)
				f2 = true;
			if (a == 5)
				f5 = true;
		}

		if (!f2 && f5 && n*4 <= sum)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}