#include <bits/stdc++.h>

using namespace std;

int test, n;

int main()
{
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		
		if (n < 7)
		{
			printf("-1\n");
			continue;
		}

		printf("%d\n", n);
		printf("1 2\n1 3\n2 4\n2 5\n3 4\n3 6\n");

		for (int i = 7; i <= n; ++i)
			printf("4 %d\n", i);
		printf("1\n");
	}
	return 0;
}