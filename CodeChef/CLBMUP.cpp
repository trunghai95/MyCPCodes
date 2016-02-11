#include <bits/stdc++.h>

using namespace std;

int test, n, s, ss;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &ss);
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &s);
			res += (s > ss);
		}

		printf("%d\n", res);
	}
	return 0;
}