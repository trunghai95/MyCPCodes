#include <bits/stdc++.h>

using namespace std;

int test, n, m, b[100010];
char S[100010], P[100010];

void preKMP()
{
	int i = 0, j = b[0] = -1;

	while (i < m)
	{
		while (j >= 0 && P[j] != P[i]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

int searchKMP()
{
	int i = 0, j = 0, res = 0;
	while (i < n)
	{
		while (j >= 0 && S[i] != P[j]) j = b[j];
		++i, ++j;
		if (j == m)
		{
			j = b[j];
			++res;
		}
	}
	return res;
}

int main()
{
	scanf("%d", &test);

	for (int ii = 1; ii <= test; ++ii)
	{
		scanf("\n%[^\n] %s", S, P);
		int i = 0, j = 0;
		while (1)
		{
			if (S[j] == 0)
			{
				S[i] = 0; break;
			}
			if (S[j] != ' ')
				S[i] = S[j], ++i;
			++j;
		}
		n = strlen(S);
		m = strlen(P);
		preKMP();
		printf("Case %d: %d\n", ii, searchKMP());
	}
	return 0;
}