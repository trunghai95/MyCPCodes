#include <bits/stdc++.h>

using namespace std;

char s[1000010];
int n, b[1000010];

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
		n = strlen(s);

		if (s[0] == '.' && n == 1)
			return 0;
		preKMP();

		if (n % (n - b[n]) == 0)
			printf("%d\n", n / (n - b[n]));
		else
			printf("1\n");
	}
	return 0;
}