#include <bits/stdc++.h>

using namespace std;

char s[10000001];
int n, n2, z[10000001], f[5000001], res;

void calcZ()
{
	int L = 0, R = 0;

	for (int i = 1; i < n2; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n2 && s[R] == s[R-L]) ++R;
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
				while (R < n2 && s[R] == s[R-L]) ++R;
				z[i] = R - L;
				--R;
			}
		}
	}
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	n2 = n*2;

	for (int i = 0; i < n; ++i)
		s[n2 - i - 1] = s[i];

	calcZ();

	f[0] = res = 1;
	for (int i = 1; i < n; ++i)
	{
		if (z[n2 - i - 1] == i + 1)
			f[i] = f[(i-1)>>1] + 1;
		res += f[i];
	}

	printf("%d", res);
	return 0;
}