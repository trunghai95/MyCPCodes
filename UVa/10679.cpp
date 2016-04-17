#include <bits/stdc++.h>

using namespace std;

int test, n, m, q, b[1010];
char s[100010], t[1010];

void preKMP()
{
	int i = 0, j = b[0] = -1;

	while (i < m)
	{
		while (j >= 0 && t[i] != t[j]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

bool searchKMP()
{
	int i = 0, j = 0;
	while (i < n)
	{
		while (j >= 0 && s[i] != t[j]) j = b[j];
		++i, ++j;
		if (j == m)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%s %d", s, &q);
		n = strlen(s);
		while (q--)
		{
			scanf("%s", t);
			m = strlen(t);
			preKMP();
			if (searchKMP())
				printf("y\n");
			else
				printf("n\n");
		}
	}
	return 0;
}