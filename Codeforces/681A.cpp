#include <bits/stdc++.h>

using namespace std;

int n, be, af;
char s[20];

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		scanf("%s %d %d", s, &be, &af);
		if (be >= 2400 && af > be)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}