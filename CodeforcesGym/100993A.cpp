#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, test;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if (abs(b - c) > 1)
		{
			printf("impossible\n");
			continue;
		}

		if (!b && !c)
		{
			if (a && d)
				printf("impossible\n");
			else if (a)
			{
				for (int i = 0; i <= a; ++i)
					printf("0");
				printf("\n");
			}
			else if (d)
			{
				for (int i = 0; i <= d; ++i)
					printf("1");
				printf("\n");
			}
			continue;
		}

		int last;
		if (b > c)
		{
			for (int i = 0; i <= a; ++i)
				printf("0");
			for (int i = 0; i <= d; ++i)
				printf("1");
			last = 1;
		}
		else
		{
			for (int i = 0; i <= d; ++i)
				printf("1");
			for (int i = 0; i <= a; ++i)
				printf("0");
			last = 0;
		}

		b = b+c-1;
		for (int i = 0; i < b; ++i)
			printf("%d", (last = 1 - last));
		printf("\n");
	}
	return 0;
}