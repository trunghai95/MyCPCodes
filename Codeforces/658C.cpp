#include <bits/stdc++.h>

using namespace std;

int n, d, h;

int main()
{
	scanf("%d %d %d", &n, &d, &h);

	if (h*2 < d || (n > 2 && d == 1))
	{
		printf("-1");
		return 0;
	}

	int curNode = 2;
	for (int i = 0; i < h; ++i)
	{
		printf("%d %d\n", curNode - 1, curNode);
		++curNode;
	}

	if (curNode > n)
		return 0;
	
	if (d == h)
		printf("2 %d\n", curNode);
	else
		printf("1 %d\n", curNode);
	++curNode;
	for (int i = 1; i < d - h; ++i)
	{
		printf("%d %d\n", curNode - 1, curNode);
		++curNode;
	}

	while (curNode <= n)
	{
		if (d == h)
			printf("2 %d\n", curNode);
		else
			printf("1 %d\n", curNode);
		++curNode;
	}
	return 0;
}