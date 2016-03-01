#include <bits/stdc++.h>

using namespace std;

int m, x, cur;

int main()
{
	scanf("%d", &m);

	if (m == 0)
	{
		printf("4\n1 2 3 4");
		return 0;
	}

	while (cur < m)
	{
		x += 5;
		int tmp = x, cnt = 0;
		while (tmp % 5 == 0)
			tmp /= 5, ++cnt;
		cur += cnt;
	}

	if (cur == m)
	{
		printf("5\n");
		for (int i = 0; i < 5; ++i)
			printf("%d ", x+i);
	}
	else
		printf("0\n");
	return 0;
}