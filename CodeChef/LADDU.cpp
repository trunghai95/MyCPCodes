#include <bits/stdc++.h>

using namespace std;

int test, n, type, x;
char s[50];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %s", &n, s);

		if (!strcmp(s, "INDIAN"))
			type = 200;
		else
			type = 400;

		int sum = 0;

		while (n--)
		{
			scanf("%s", s);

			if (!strcmp(s, "CONTEST_WON"))
			{
				scanf("%d", &x);
				sum += 300 + max(20 - x, 0);
			}
			else if (!strcmp(s, "TOP_CONTRIBUTOR"))
				sum += 300;
			else if (!strcmp(s, "BUG_FOUND"))
			{
				scanf("%d", &x);
				sum += x;
			}
			else sum += 50;
		}

		printf("%d\n", sum / type);
	}
	return 0;
}