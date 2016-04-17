#include <bits/stdc++.h>

using namespace std;

char s[1000010];
int z[1000010], n;

void calcZ()
{
	int L = 0, R = 0;

	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && s[R] == s[R-L])
				++R;
			z[i] = R - L; --R;
		}
		else
		{
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else
			{
				L = i;
				while (R < n && s[R] == s[R-L])
					++R;
				z[i] = R - L; --R;
			}
		}
	}
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	calcZ();

	int maxz = 0, res = -1;
	for (int i = 1; i < n; ++i)
	{
		if (z[i] == n - i && z[i] <= maxz)
		{
			res = z[i];
			break;
		}

		maxz = max(maxz, z[i]);
	}

	if (res == -1)
		printf("Just a legend");
	else
	{
		for (int i = 0; i < res; ++i)
			printf("%c", s[i]);
	}
	return 0;
}