#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

char P[MAXN+10], T[MAXN+10];
int n, m, b[MAXN+10];

void preKMP()
{
	int i = 0, j = b[0] = -1;

	while (i < m)
	{
		while (j >= 0 && P[i] != P[j]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

void searchKMP()
{
	int i = 0, j = 0;

	while (i < n)
	{
		while (j >= 0 && T[i] != P[j]) j = b[j];
		++i, ++j;
		if (j == m)
		{
			printf("%d ", i - j + 1);
			j = b[j];
		}
	}
}

int main()
{
	scanf("%s %s", T, P);
	n = strlen(T);
	m = strlen(P);
	preKMP();
	searchKMP();
	return 0;
}