#include <bits/stdc++.h>

using namespace std;

int test, n;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		int res = 0, cur = 1;
		while (n >= cur)
		{
			++res;
			n -= cur;
			++cur;
		}

		printf("%d\n", res);
	}
	return 0;
}