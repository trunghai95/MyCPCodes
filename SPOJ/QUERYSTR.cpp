#include <bits/stdc++.h>

using namespace std;

int test, z[1000010], n, x, len;
char s[1000010];

void calcZ()
{
	int L = 0, R = 0;

	for (int i = 1; i < len; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < len && s[R] == s[R-L]) ++R;
			z[i] = R - L; --R;
		}
		else
		{
			int k = i - L;
			if (z[k] < R - i + 1) z[i] = z[k];
			else
			{
				L = i;
				while (R < len && s[R] == s[R-L]) ++R;
				z[i] = R - L; --R;
			}
		}
	}

	z[0] = len;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%s %d", s, &n);
		len = strlen(s);
		reverse(s, s+len);
		calcZ();

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			printf("%d\n", z[len - x]);
		}
	}
	return 0;
}