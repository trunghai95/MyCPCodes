#include <bits/stdc++.h>

using namespace std;

char s[100010];
int n, b[100010];

void preKMP()
{
	int i = 0, j = b[0] = -1;
	while (i < n)
	{
		while (j >= 0 && s[i] != s[j]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

int main()
{
	while (1)
	{
		scanf("%s", s);
		if (s[0] == '*')
			return 0;
		n = strlen(s);
		preKMP();
		if (n % (n - b[n]) == 0)
			printf("%d\n", n / (n - b[n]));
		else
			printf("1\n");
		// printf("%d\n", n);
		// for (int i = 0; i <= n; ++i)
		// 	printf("%d ", b[i]);
		// printf("\n");
	}
	return 0;
}