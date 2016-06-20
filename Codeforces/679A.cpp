#include <bits/stdc++.h>

using namespace std;

int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int cur = -1;
char s[10];
bool ck[110];

int main()
{
	int n = sizeof(p) / sizeof(int);
	memset(ck, 0, sizeof(ck));

	for (int i = 2; i <= 100; ++i)
	if (!ck[i])
	{
		if (cur == -1 && i > 13)
		{
			printf("prime");
			return 0;
		}
		printf("%d\n", i);
		fflush(stdout);
		scanf("%s", s);
		if (!strcmp(s, "yes"))
		{
			for (int j = i; j <= 100; ++j)
			if (j % i != 0)
				ck[j] = true;
			cur = i;
		}
		else
		{
			for (int j = i; j <= 100; ++j)
			if (j % i == 0)
				ck[j] = true;
		}
	}

	for (int i = 0; i < n; ++i)
	if (cur == p[i])
	{
		printf("prime");
		return 0;
	}

	printf("composite");
	return 0;
}