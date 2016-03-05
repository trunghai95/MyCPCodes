#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, a, last;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &last);
		int res = 0;

		while (1)
		{
			scanf("%d", &a);
			if (a == 0)
				break;
			res += max(0, a - last * 2);
			last = a;
		}

		printf("%d\n", res);
	}
	return 0;
}