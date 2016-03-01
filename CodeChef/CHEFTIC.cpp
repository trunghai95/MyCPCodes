#include <bits/stdc++.h>

using namespace std;

int n, k, test;
char s[30][30];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);

		bool f = false;
		for (int i = 0; i < n && !f; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i <= n - k)
			{
				int dotcnt = 0, xcnt = 0;
				for (int ii = i; ii <= i + k - 1; ++ii)
					dotcnt += (s[ii][j] == '.'),
					xcnt += (s[ii][j] == 'X');
				if (dotcnt == 1 && xcnt == k-1)
				{
					f = true;
					break;
				}
			}

			if (j <= n - k)
			{
				int dotcnt = 0, xcnt = 0;
				for (int ii = j; ii <= j + k - 1; ++ii)
					dotcnt += (s[i][ii] == '.'),
					xcnt += (s[i][ii] == 'X');
				if (dotcnt == 1 && xcnt == k-1)
				{
					f = true;
					break;
				}
			}

			if (i <= n - k && j <= n - k)
			{
				int dotcnt = 0, xcnt = 0;
				for (int ii = i, jj = j; ii <= i + k - 1; ++ii, ++jj)
					dotcnt += (s[ii][jj] == '.'),
					xcnt += (s[ii][jj] == 'X');
				if (dotcnt == 1 && xcnt == k-1)
				{
					f = true;
					break;
				}
			}

			if (i <= n - k && j >= k - 1)
			{
				int dotcnt = 0, xcnt = 0;
				for (int ii = i, jj = j; ii <= i + k - 1; ++ii, --jj)
					dotcnt += (s[ii][jj] == '.'),
					xcnt += (s[ii][jj] == 'X');
				if (dotcnt == 1 && xcnt == k-1)
				{
					f = true;
					break;
				}
			}
		}

		if (f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}