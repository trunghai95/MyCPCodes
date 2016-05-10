#include <bits/stdc++.h>

using namespace std;

int k, n, z[1000010];
char s[1000010];

void calcZ()
{
	int L = 0, R = 0;

	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && s[R] == s[R-L]) ++R;
			z[i] = R - L;
			--R;
		}
		else
		{
			int k = i - L;
			if (z[k] <= R - i) z[i] = z[k];
			else
			{
				L = i;
				while (R < n && s[R] == s[R-L]) ++R;
				z[i] = R - L;
				--R;
			}
		}
	}
}

int main()
{
	while (1)
	{
		scanf("%d %s", &k, s);

		if (k == -1)
			return 0;

		n = strlen(s);
		if (k < n)
		{
			printf("0\n");
			continue;
		}

		if (n == 1)
		{
			printf("%d\n", k);
			continue;
		}

		calcZ();
		int len = n;
		for (int i = 1; i < n; ++i)
		if (z[i] == n - i)
		{
			len = i;
			break;
		}

		int res = 1 + (k - n) / len;
		printf("%d\n", res);
	}
	return 0;
}