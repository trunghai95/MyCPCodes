#include <bits/stdc++.h>

using namespace std;

int test, n, cnt[2001];

void init()
{
	for (int i = 2; i <= 2000; ++i)
	{
		cnt[i] += cnt[i-1];
		for (int j = 1; j < i; ++j)
		{
			if ((i^j) <= i)
				++cnt[i];
			else if ((i^j) <= 2000)
				++cnt[i^j];
		}
	}
}

int main()
{
	init();
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		printf("%d\n", cnt[n]);
	}
	return 0;
}