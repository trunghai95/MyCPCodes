#include <bits/stdc++.h>

using namespace std;

char s[2000];
int test, k;

int main()
{
	scanf("%d", &test);

	for (int ii = 1; ii <= test; ++ii)
	{
		scanf("%d %s", &k, s);
		int sum = 0, res = 0, tmp;

		for (int i = 0; i <= k; ++i)
		{
			tmp = 0;
			if (i > sum)
				tmp = i - sum;
			res += tmp;
			sum += tmp + s[i] - '0';
		}

		printf("Case #%d: %d\n", ii, res);
	}
	return 0;
}